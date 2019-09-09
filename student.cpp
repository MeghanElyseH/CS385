/***********************
* Name : student.cpp
* Author : Meghan Elyse Hom
* Version : 1.0
* Date : September 4, 2019
* Description : Creates a student class with various public and private methods.
* Pledge : I pledge my honor that I have abided by the Stevens Honor System.
************************/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

class Student{
	
	//PUBLIC METHODS
public:
	Student(string first, string last, float gpa, int id) : 
	first_(first), last_(last), gpa_(gpa), id_(id){
	};
	
	//This function returns the student's first and last name
	string full_name() const{
		return first_ + " " + last_;
	}
	
	//This function returns the student's id
	int id() const{
		return id_;
	}
	
	//This function returns the student's gpa
	float gpa() const{
		return gpa_;
	}
	
	//This function prints the student's name, gpa, and id
	//Will print in the format (GPA has 2 decimal places) :
	//Bob Smith, GPA: 3.50, ID: 20146
	void print_info() const{
		cout /*<< first*/ << full_name() << ", GPA: " << setprecision(2) << fixed << gpa_ << ", ID: " << id_ << endl;
	}
	
	//PRIVATE METHODS
private:
	string first_;
	string last_;
	float gpa_;
	int id_;
};

/**
*Takes a vector of Student objects, and returns a new vector with all 
*Students whose GPA is less than 1.0.
**/
vector<Student> find_failing_students(const vector<Student> &students){
	vector<Student> failing_students;
	/**
	*Iterates through the students vector, appending each student whose gpa
	*is less than 1.0 to the failing_students vector
	**/
	for(vector<Student>::const_iterator it = students.begin();
	it != students.end(); ++it){
		if(it -> gpa() < 1.0){
			failing_students.push_back(*it);
		}
	}
	
	return failing_students;
}

/**
* Takes a vector of Student objects and prints them to the screen.
**/
void print_students(const vector<Student> &students){
	//Iterates through the students vector, calling print_info() for each student.
	for(vector<Student>::const_iterator it = students.begin();
	it != students.end(); ++it){
		it -> print_info();
	}
}

int main(){
	string first_name, last_name;
	float gpa;
	int id;
	char repeat;
	vector<Student> students;
	
	do{
		cout << "Enter student's first name: ";
		cin >> first_name;
		cout << "Enter student's last name: ";
		cin >> last_name;
		gpa = -1;
		while(gpa < 0 || gpa > 4){
			cout << "Enter student's GPA (0.0-4.0): ";
			cin >> gpa;
		}
		cout << "Enter student's ID: ";
		cin >> id;
		students.push_back(Student(first_name, last_name, gpa, id));
		cout << "Add another student to database (Y/N)? ";
		cin >> repeat;
	} while(repeat == 'Y' || repeat == 'y');{
		cout << endl << "All students:" << endl;
		print_students(students);
		
		cout << endl << "Failing students:";
		vector<Student> failing_students = find_failing_students(students);
		if(failing_students.empty()){
			cout << " None";
		}
		else{
			cout << endl;
			print_students(failing_students);
		}
		//Print a space and the word 'None' on the same line if no students are failing
		//Otherwise, print each failing student on a separate line
		
		return 0;
	}
}