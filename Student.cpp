#include "Student.h"
using namespace std;
Student::Student()
{
  m_name      = "NULL";
  m_ID        = 0;
  m_advisorID = 0;
  m_gpa       = 0;
  m_field     = "NULL";
  m_level     = "NULL";
  m_major     = "NULL";
}

Student::Student(int id, int advisorID, double gpa, string name, string field, string level, string major)
{
  m_name      = name;
  m_ID        = id;
  m_advisorID = advisorID;
  m_gpa       = gpa;
  m_field     = field;
  m_level     = level;
  m_major     = major;
}

void Student::printInfo()
{
  cout << "Name        : " << m_name << endl;
  cout << "Student ID  : " << m_ID   << endl;
  cout << "Advisor ID  : " << m_advisorID << endl;
  cout << "GPA         : " << m_gpa << endl;
  cout << "Field       : " << m_field << endl;
  cout << "Grade Level : " << m_level << endl;
  cout << "Major       : " << m_major << endl;
  cout << endl;
}

void Student::addToFile()
{
  ofstream outFS;
  outFS.open("studentTable.txt", ios::app);
  outFS << m_name << "|" << m_ID << "|" << m_advisorID << "|" << m_gpa << "|" << m_field << "|" << m_level << "|" << m_major << endl;
  outFS.close();
}
