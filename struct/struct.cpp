/*
 * struct.cpp
 *
 *  Created on: 07.03.2014
 *      Author: trifon
 */

#include <iostream>
#include <cstring>
using namespace std;

int const MAX_NAME = 100;

struct Student {
	char name[MAX_NAME];
	int fn;
	double grade;
} s = { "Иван Колев", 40000, 3.5 };

void printStudent(Student s) {
	cout << s.name << '\t' << s.fn << '\t' << s.grade << endl;
	// s.grade += 1; // не се отразява!
}

Student betterStudent(Student s1, Student s2) {
	if (s1.grade > s2.grade)
		return s1;
	return s2;
}

void examplesStudent() {
	//cout << s.name << ' ' << s.fn << endl;
	printStudent(s);
	cout << sizeof(Student) << endl;
	Student s1 = s;
	s1 = s;
	strcpy(s.name, "Петър Петров");
	s.grade += 0.5;
	printStudent(s);
	printStudent(s1);
	printStudent(s1);
	printStudent(betterStudent(s, s1));
}

Student readStudent() {
	Student s;
	//cout << "Име: ";
	//cout << "Ф№: ";
	//cout << "Оценка: ";
	cin >> s.fn;
	cin >> s.grade;cin.ignore();
	cin.getline(s.name, MAX_NAME);
	return s;
}

int readStudents(Student s[]) {
	int n;
	//cout << "Брой студенти? ";
	cin >> n; cin.ignore();
	for(int i = 0; i < n; i++)
		s[i] = readStudent();
}

void printStudents(Student s[], int n) {
	cout << "Име\t\tФ№\tОценка" << endl;
	for(int i = 0; i < n; i++)
		printStudent(s[i]);
}

double averageGrade(Student s[], int n) {
	double sum = 0;
	for(int i = 0; i < n; i++)
		sum += s[i].grade;
	return sum / n;
}

void sortStudentsByFN(Student s[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int min = i;
		for(int j = i + 1; j < n; j++)
			if (s[j].fn < s[min].fn)
				min = j;
		Student tmp = s[min];
		s[min] = s[i];
		s[i] = tmp;
	}
}

void sortStudentsByGrade(Student s[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int min = i;
		for(int j = i + 1; j < n; j++)
			if (s[j].grade > s[min].grade)
				min = j;
		Student tmp = s[min];
		s[min] = s[i];
		s[i] = tmp;
	}
}

void printStudentPointers(Student* ps[], int n) {
	cout << "Име\t\tФ№\tОценка" << endl;
	for(int i = 0; i < n; i++)
		printStudent(*ps[i]);
}


void simpleSort() {
	Student students[100];
	//printStudent(readStudent());
	int nStudents = readStudents(students);
	cout << "Прочетени " << nStudents << " студенти" << endl;
	printStudents(students, nStudents);
	cout << "Среден успех: " << averageGrade(students, nStudents) << endl;
	sortStudentsByFN(students, nStudents);
	printStudents(students, nStudents);
	sortStudentsByGrade(students, nStudents);
	printStudents(students, nStudents);
	Student* pStudent = students + 2;
	pStudent->grade += 0.5;
	// (*pStudent).grade += 0.5;
	printStudents(students, nStudents);
}

void initializePointers(Student s[], Student* ps[], int n) {
	for(int i = 0; i < n; i++)
		ps[i] = s + i;// &s[i];
}

void sortStudentPointersByFN(Student* s[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int min = i;
		for(int j = i + 1; j < n; j++)
			if (s[j]->fn < s[min]->fn)
				min = j;
		Student* tmp = s[min];
		s[min] = s[i];
		s[i] = tmp;
	}
}

void sortStudentPointersByGrade(Student* s[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int min = i;
		for(int j = i + 1; j < n; j++)
			if (s[j]->grade > s[min]->grade)
				min = j;
		Student* tmp = s[min];
		s[min] = s[i];
		s[i] = tmp;
	}
}

void pointerSort() {
	int const MAX_STUDENTS = 100;
	Student students[MAX_STUDENTS];
	int nStudents = readStudents(students);
	cout << "Прочетени " << nStudents << " студенти" << endl;
	printStudents(students, nStudents);

	Student *studentsByFN[MAX_STUDENTS], *studentsByGrade[MAX_STUDENTS];
	initializePointers(students, studentsByFN, nStudents);
	initializePointers(students, studentsByGrade, nStudents);
	sortStudentPointersByFN(studentsByFN, nStudents);
	sortStudentPointersByGrade(studentsByGrade, nStudents);
	cout << "По Ф№:\n";
	printStudentPointers(studentsByFN, nStudents);
	cout << "По оценка:\n";
	printStudentPointers(studentsByGrade, nStudents);
	cout << "Оригинален масив:\n";
	printStudents(students, nStudents);
}

int main() {
	pointerSort();
	return 0;
}
