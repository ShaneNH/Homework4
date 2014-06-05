////////////////////////////////////
// Homework 4
// Shane Nishioka-Healy
// CS-172
// 6/4/2014
///////////////////////////////////

#include <iostream>
#include <string>
#include "Course.h"
using namespace std;
void ex04_01();
int* doubleCapacity(const int* list, int size); // ex04_02
int min(const int* array, int size); //ex04_03
string* doubleCapacity(const string* list, int size); //ex04_05

class Rectangle2D
{
private:
	double x, y;
	double width, height;

public:
	Rectangle2D()
	{
		x = 0;
		y = 0;
		width = 1;
		height = 1;
	}

	Rectangle2D(double x, double y, double width, double height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	double getX() const
	{
		return x;
	}

	void setX(double x)
	{
		this->x = x;
	}

	double getY() const
	{
		return y;
	}

	void setY(double y)
	{
		this->y = y;
	}

	double getWidth() const
	{
		return width;
	}

	void setWidth(double width)
	{
		this->width = width;
	}

	double getHeight() const
	{
		return height;
	}

	double setHeight(double height)
	{
		this->height = height;
	}

	double getPerimeter() const
	{
		return 2 * height + 2 * width;
	}

	double getArea() const
	{
		return height * width;
	}

	bool contains(double x, double y) const
	{

		return (abs(x - this->x) <= width) && (abs(y - this->y) <= height);
	}

	bool contains(const Rectangle2D &r) const
	{
		return contains(r.x - r.width, r.y) && contains(r.x + r.width, r.y)
			&& contains(r.x, r.y - r.height) && contains(r.x, r.y + r.height);
	}

	bool overlaps(const Rectangle2D &r) const
	{
		return ((x + .5 * width > r.x + .5 * r.width)
			&& (y + .5 * height > r.y + .5 * r.height)
			|| (x + .5 * width > r.x + .5 * r.width)
			&& (y + .5 * height > r.y + .5 * r.height));


	}

};

int main(){

	ex04_01();

	//ex04_03
	const int Size = 8;
	int arr[Size] = { 1, 2, 4, 5, 10, 100, 2, -22 };
	cout << min(arr, Size) << endl;

	//ex04_04
	Rectangle2D r1(2, 2, 5.5, 10);
	cout << "Area: " << r1.getArea() << endl;
	cout << "Perimeter: " << r1.getPerimeter() << endl;

	cout << r1.contains(3, 3) << endl;

	Rectangle2D r2(2, 2, 5, 5);
	cout << r1.contains(r2) << endl;
	cout << r1.overlaps(r2) << endl;

	//ex04_05
	Course course1("CS-172", 3);

	course1.addStudent("John Green");
	course1.addStudent("Connie White");
	course1.addStudent("David Black");

	course1.dropStudent("Connie White");

	string* students = course1.getStudents();

	for (int i = 0; i < course1.getNumberOfStudents(); i++){
		cout << students[i] << " ";
	}

}

//ex04_01
void ex04_01(){
	const int SIZE = 5;
	int arr[SIZE] = { 3, 4, 5, 6, 7 };
	int sum = 0;
	for (int a = 0; a < SIZE; a++){
		sum += arr[a];
	}
	int avg = sum / SIZE;
	int aboveavg = 0;
	for (int i = 0; i < SIZE; i++){

		if (arr[i] > avg){
			aboveavg++;
		}
	}
	cout << aboveavg << " Numbers over average" << endl;
}



//ex04_02
int* doubleCapacity(const int* list, int size)
{
	int* arr2 = new int[size * 2];

	for (int i = 0; i < size; i++)
	{
		arr2[i] = list[i];
	}

	for (int i = size + 1; i < size * 2; i++)
	{
		arr2[i] = 0;
	}
	return arr2;
}



//ex04_03
int min(const int* array, int size)
{
	int min = array[0];
	int i;

	for (i = 0; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}

	}
	return min;
}


//ex04_05
Course::Course(const string& courseName, int capacity){
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}

Course::~Course(){
	delete[] students;
}

string Course::getCourseName() const{
	return courseName;
}

void Course::addStudent(const string& name){
	students[numberOfStudents] = name;
	numberOfStudents++;
	if (numberOfStudents > capacity){
		doubleCapacity(students, capacity);
	}
}

void Course::dropStudent(const string& name){
	for (int i = 0; i < numberOfStudents; i++){
		if (students[i] == name){
			students[i] = "";
		}
	}
}

string* Course::getStudents() const{
	return students;
}

int Course::getNumberOfStudents() const{
	return numberOfStudents;
}


string* doubleCapacity(const string* list, int size)
{
	string* arr2 = new string[size * 2];

	for (int i = 0; i < size; i++)
	{
		arr2[i] = list[i];
	}

	for (int i = size + 1; i < size * 2; i++)
	{
		arr2[i] = "";
	}
	return arr2;
}

void Course::clear(){
	for (int i = 0; i < capacity;){
		students[i] = "";
	}
}



