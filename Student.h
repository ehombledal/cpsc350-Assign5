#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
  Student();
  Student(int id, int advisorID, double gpa, string name, string field, string level, string major);

  bool operator< (const Student& s)
  {
    cout << "overloaded <" << endl;
    return (m_ID < s.m_ID);
  }

  bool operator> (const Student& s)
  {
    cout << "overloaded >" << endl;
    return (m_ID > s.m_ID);
  }

  bool operator== (const Student& s)
  {
    return (m_ID == s.m_ID);
  }

  bool operator!= (const Student& s)
  {
    return (m_ID != s.m_ID);
  }

  void printInfo();
  void addToFile();

  int m_ID;
  int m_advisorID;
  string m_name;
  double m_gpa;
  string m_field;
  string m_level;
  string m_major;
};
