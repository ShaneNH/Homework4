//
//#include <iostream>
//#include "Course.h"
//
//using namespace std;
//
//string* doubleCapacity(const string* list, int size);
//
//int main(){
//	Course course1("CS-172", 3);
//
//	course1.addStudent("John Green");
//	course1.addStudent("Connie White");
//	course1.addStudent("David Black");
//
//	course1.dropStudent("John Green");
//
//	string* students = course1.getStudents();
//
//	for (int i = 0; i < course1.getNumberOfStudents(); i++){
//		cout << students[i] << " ";
//	}
//
//}
//
//
//Course::Course(const string& courseName, int capacity){
//	numberOfStudents = 0;
//	this->courseName = courseName;
//	this->capacity = capacity;
//	students = new string[capacity];
//}
//
//Course::~Course(){
//	delete[] students;
//}
//
//string Course::getCourseName() const{
//	return courseName;
//}
//
//void Course::addStudent(const string& name){
//	students[numberOfStudents] = name;
//	numberOfStudents++;
//	if (numberOfStudents > capacity){
//		doubleCapacity(students, capacity);
//	}
//}
//
//void Course::dropStudent(const string& name){
//	for (int i = 0; i < numberOfStudents; i++){
//		if (students[i] == name){
//			students[i] = "";
//		}
//	}
//}
//
//string* Course::getStudents() const{
//	return students;
//}
//
//int Course::getNumberOfStudents() const{
//	return numberOfStudents;
//}
//
//
//string* doubleCapacity(const string* list, int size)
//{
//	string* arr2 = new string[size * 2];
//
//	for (int i = 0; i < size; i++)
//	{
//		arr2[i] = list[i];
//	}
//
//	for (int i = size + 1; i < size * 2; i++)
//	{
//		arr2[i] = "";
//	}
//	return arr2;
//}
//
//void Course::clear(){
//	for (int i = 0; i < capacity;){
//		students[i] = "";
//	}
//}
//
//
