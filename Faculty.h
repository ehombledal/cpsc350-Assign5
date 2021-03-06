#include "GenLinkedList.h"
#include "Student.h"

class Faculty
{
public:
  Faculty();
  Faculty(int id, string name, string level, string department);

  bool operator< (const Faculty& f)
  {
    return (m_ID < f.m_ID);
  }

  bool operator> (const Faculty& f)
  {
    return (m_ID > f.m_ID);
  }

  bool operator== (const Faculty& f)
  {
    return (m_ID == f.m_ID);
  }

  bool operator!= (const Faculty& f)
  {
    return (m_ID != f.m_ID);
  }

  void printInfo();
  void addToFile(string fileName);


  int m_ID;
  string m_name;
  string m_level;
  string m_department;
  GenLinkedList<Student*> *advisees;
};
