#include "groupProject.h"
#include <sstream>

groupProject::groupProject(){maxN = 99; status = "nf";};

groupProject::groupProject(vector<Student *> studentsIN)
{
	students = studentsIN;
	Professor p("no_teacher", 0);
	teacher = p;
	maxN = 99;
	status = "nf";
}

bool groupProject::addStudent(Student *st)
{
	if (students.size() < (unsigned)maxN)
	{
		students.push_back(st);
		return true;
	}
	return false;
}

void groupProject::removeSudent(Student *st, string title)
{
	st->deleteTitle(title);
	for (vector<Student *>::iterator it = students.begin(); it != students.end(); it++)
	{
		if ((*it)->getName() == st->getName())
		{
			students.erase(it);
			break;
		}
	}
}

void groupProject::setTeacher(Professor *prof)
{
	this->teacher.setId(prof->getId());
	this->teacher.setName(prof->getName());
}

void groupProject::setTextFile(string tFile)
{
	textFile = tFile;
}

void groupProject::setMaxNum(int num)
{
	maxN = num;
}

vector<Student *> groupProject::getStudents() const
{
	return students;
}

string groupProject::getTextFile()
{
	return textFile;
}

Professor groupProject::getTeacher() const
{
	return teacher;
}

string groupProject::getTitle() const
{
	return title;
}

string groupProject::getYear() const
{
	return year;
}

string groupProject::getType() const
{
	return type;
}

void groupProject::setMark(Student *st, int mark, string title)
{
	for (vector<Student *>::iterator it=students.begin(); it != students.end(); it++)
	{
		if ((*it)->getId() == st->getId())
		{
			(*it)->setMark(mark, title);
		}
	}
}

string groupProject::printInfoProject(string title)
{
	stringstream ss;
	ss << "Title: " << title << "\n";
	ss << "Year: " << year << "\n";
	ss << "Status: ";
	if (status == "nf") ss << "not finished\n";
	else if (status == "f") ss << "finished, not evaluated\n";
	else if (status == "ev") ss << "finished, evaluated\n";
	ss << "Monitor: " << teacher.getName() << "\n";
	ss << "Students\n";
	for (unsigned int i=0; i<students.size(); i++)
	{
		ss << students[i]->getId() << " - " << students[i]->getName() << " - " << students[i]->getMark(title) << "\n";
	}
	ss << "\n Free places: " << (maxN - students.size()) << "\n";
	return ss.str();
}

int groupProject::getMax()
{
	return maxN;
}

void groupProject::setStatus(string newSt)
{
	status = newSt;
}

void groupProject::setTitle(string title)
{
	this->title = title;
}

void groupProject::setYear(string year)
{
	this->year = year;
}

void groupProject::setType(string type)
{
	this->type = type;
}

string groupProject::getStatus() const
{
	return status;
}

bool groupProject::operator < (const groupProject *right) const
{
	if (type == right->type)
	{
		if (title == right->title)
			return year >= right->year;
		else
			return title < right->title;
	}
	return type < right->type;

	/*if (this->type < right.type) return true;
	else if (this->type > right.type) return false;
	else if (this->title < right.title) return true;
	else if (this->title > right.title) return false;
	else if (this->year >= right.year) return true;
	else return false;*/

}

bool groupProject::operator == (const groupProject *right) const
{
	return (title == right->title && year == right->year && students == right->students);
}
