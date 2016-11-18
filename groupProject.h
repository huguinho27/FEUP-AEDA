#ifndef GROUPPROJECT_H
#define GROUPPROJECT_H

#include <fstream>
#include <iostream>

#include "student.h"

using namespace std;

class groupProject
{
	Professor teacher;
	vector<Student> students;
	string textFile;
	unsigned int maxN;
public:
	groupProject();
	groupProject(vector<Student> studentsIN, string tFile);
	bool addStudent(Student st);
	void removeSudent(Student st);
	void setTeacher(Professor prof);
	void setTextFile(string tFile);
	void setMaxNum(unsigned int num);
	vector<Student> getStudents() const;
	string getTextFile();
	Professor getTeacher() const;
	string printInfoProject(string title);
};

#endif
