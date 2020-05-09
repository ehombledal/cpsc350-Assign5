#include "Faculty.h"

using namespace std;
Faculty::Faculty()
{
  m_ID = 0;
  m_name = "NULL";
  m_level = "NULL";
  m_department = "NULL";
  advisees = new GenLinkedList<Student*>;
}

Faculty::Faculty(int id, string name, string level, string department)
{
  m_ID = id;
  m_name = name;
  m_level = level;
  m_department = department;
  advisees = new GenLinkedList<Student*>;
}


void Faculty::printInfo()
{
  cout << endl;
  cout << "Name        : " << m_name << endl;
  cout << "Faculty ID  : " << m_ID << endl;
  cout << "Level       : " << m_level << endl;
  cout << "Department  : " << m_department << endl;

  cout << "Advisees are as follows:" << endl;
  advisees -> printList();
  cout << endl;
}
