
#include "GenBST.h"
#include "Faculty.h"

bool toExit = false;
GenBST<Student*> *masterStudent;
GenBST<Faculty*> *masterFaculty;
int sid = 0;
int fid = 0;

void initializeDatabase()
{
  cout << endl;
  cout << "Welcome to the Database Manager!" << endl;
  masterStudent = new GenBST<Student*>;
  Student *s1 = new Student(1000, 50, 3.0, "Mike", "Marketing", "Sophomore", "Business");
  Student *s2 = new Student(1030, 50, 3.3, "John", "Statistics", "Junior", "Math");
  Student *s3 = new Student(1020, 70, 3.7, "Sarah", "Advertising", "Freshman", "Business");
  Student *s4 = new Student(1080, 70, 3.7, "Miley", "Advertising", "Freshman", "Business");
  Student *s5 = new Student(900, 70, 3.7, "Kate", "Advertising", "Freshman", "Business");

  masterStudent -> insert(s1);
  masterStudent -> insert(s2);
  masterStudent -> insert(s3);
  masterStudent -> insert(s4);
  masterStudent -> insert(s5);

  masterFaculty = new GenBST<Faculty*>;
  Faculty *f1 = new Faculty(50, "Professor 1", "Lecturer", "Business");
  f1 -> advisees -> insertBack(s1);
  f1 -> advisees -> insertBack(s2);
  f1 -> advisees -> insertBack(s3);

  Faculty *f2 = new Faculty(70, "Professor 2", "Dean", "Math");
  masterFaculty -> insert(f1);
  masterFaculty -> insert(f2);
}

void showOptions()
{
  cout << endl;
  cout << "       DATABASE COMMANDS"        << endl;
  cout << endl;
  cout << "1.  Student List"                << endl;
  cout << "2.  Faculty List"                << endl;
  cout << "3.  Specific Student Info"       << endl;
  cout << "4.  Specific Faculty Info"       << endl;
  cout << "5.  Print Student's Advisor"     << endl;
  cout << "6.  Print Advisor's Students"    << endl;
  cout << "7.  Add Student"                 << endl;
  cout << "8.  Delete Student"              << endl;
  cout << "9.  Add Faculty Member"          << endl;
  cout << "10. Delete Faculty Member"       << endl;
  cout << "11. Change Student Advisor"      << endl;
  cout << "12. Remove Advisee from Faculty" << endl;
  cout << "13. Rollback"                    << endl;
  cout << "14. Exit"                        << endl;

  int choice = 0;
  cout << endl;
  cout << "Please make a selection!" << endl;
  cin >> choice;

  //each choice corresponds to the table above.
  switch(choice)
  {
    case 1: masterStudent -> printTree(masterStudent -> root);
            break;

    case 2: masterFaculty -> printTree(masterFaculty -> root);
            break;

    case 3: cout << "what is the student's ID?" << endl;
            cin >> sid;
            if (masterStudent -> searchNode(sid))
            {
              cout << "Student Found! Printing info..." << endl;
              masterStudent -> getNode(sid) -> value -> printInfo();
            } else {
              cout << "Student not found." << endl;
            }
            break;

    case 4: cout << "what is the faculty member's ID?" << endl;
            cin >> fid;
            if (masterFaculty -> searchNode(fid))
            {
              cout << "Faculty member found! Printing info." <<endl;
              masterFaculty -> getNode(fid) -> value -> printInfo();
            } else {
              cout << "Faculty not found." << endl;
            }
            break;

    case 5: cout << "what is the student's ID?" << endl;
            cin >> sid;
            if(masterStudent -> searchNode(sid))
            {
               //gets node based on advisor id of student, then prints that value.
               masterFaculty -> getNode(masterStudent -> getNode(sid) -> value -> m_advisorID) -> value -> printInfo();
            } else {
              cout << "Student does not exist. Please try again." << endl;
            }
            break;

    case 6: cout << "what is the faculty member's ID?" << endl;
            cin >> fid;
            if (masterFaculty -> searchNode(fid))
            {
              for (int i = 1; i <= masterFaculty -> getNode(fid) -> value -> advisees -> getSize(); ++i)
              {
                cout << i << endl;
                masterFaculty -> getNode(fid) -> value -> advisees -> valueAt(i) -> printInfo();
              }
            } else {
              cout << "faculty member doesnt exist. Please try again." << endl;
            }
            break;

    case 7:{cout << "What is the students name?" << endl;
            string sName = "NULL";
            cin >> sName;

            cout << "what is the student's GPA?" << endl;
            double sGPA = 0.0;
            cin >> sGPA;

            cout << "what is the student's field?" << endl;
            string sField = "NULL";
            cin >> sField;

            cout << "what is the student's grade level?" << endl;
            string sLevel = "NULL";
            cin >> sLevel;

            cout << "What is this student's major?" << endl;
            string sMajor = "NULL";
            cin >> sMajor;

            cout << "What ID number will be assigned to this student?" << endl;
            int newID = 0;
            cin >> newID;
            while (masterStudent -> searchNode(newID) == true)
            {
              cout << "ID taken! Please pick a new ID." << endl;
              cin >> newID;
            }

            cout << "What is the faculty ID of this student's advisor?" << endl;
            int newAdvisorID = 0;
            cin >> newAdvisorID;
            while (masterFaculty -> searchNode(newAdvisorID) == false)
            {
              cout << "That's not a valid advisor ID! Please try again." << endl;
              cin >> newAdvisorID;
            }

            Student *student = new Student(newID, newAdvisorID, sGPA, sName, sField, sLevel, sMajor);
            masterFaculty -> getNode(newAdvisorID) -> value -> advisees -> insertBack(student);
            masterStudent -> insert(student);
            cout << "student successfully created." << endl;
            break;}

    case 8: cout << "What is the id of the student to be deleted?" << endl;
            cin >> sid;
            if (masterStudent -> searchNode(sid))
            {
              fid = masterStudent -> getNode(sid) -> value -> m_advisorID;
              masterFaculty -> getNode(fid) -> value -> advisees -> remove(masterStudent -> getNode(sid) -> value);
              masterStudent -> deleteNode(masterStudent -> getNode(sid) -> value);
              cout << "Student successfully deleted." << endl;
            } else {
              cout << "Not a valid ID! Please try again." << endl;
            }
            break;

    case 9:{cout << "what is the faculty member's name?" << endl;
            string fName = "NULL";
            cin >> fName;

            cout << "What is this faculty member's level?" << endl;
            string fLevel = "NULL";
            cin >> fLevel;

            cout << "What is this faculty member's department?" << endl;
            string fDepartment = "NULL";
            cin >> fDepartment;

            cout << "Please assign an ID to this faculty member!" << endl;
            int newFacultyID = 0;
            cin >> newFacultyID;
            while (masterFaculty -> searchNode(newFacultyID))
            {
              cout << "ID taken! Please select a unique ID." << endl;
              cin >> newFacultyID;
            }

            Faculty *faculty = new Faculty(newFacultyID, fName, fLevel, fDepartment);
            while(true)
            {
              cout << "Please enter the ID of a student this faculty member advises. If there are none remaining, enter 0." << endl;
              int sidToCheck = -1;
              cin >> sidToCheck;
              if (sidToCheck == 0)
              {
                break;
              }

              if (masterStudent -> searchNode(sidToCheck))
              {
                faculty -> advisees -> insertBack(masterStudent -> getNode(sidToCheck) -> value);
                cout << "Student added to advisees." << endl;
              } else {
                cout << "Not a valid ID! Please try another ID, or enter 0 to end." << endl;
              }
            }
            masterFaculty -> insert(faculty);
            cout << "faculty member successfully added." << endl;
            break;}

    case 10: cout << "What is the ID of the faculty to be deleted?" << endl;
             cin >> fid;
             if (masterFaculty -> searchNode(fid))
             {
               cout << "Students to this faculty member must be assigned to a new advisor." << endl;
               while (masterFaculty -> getNode(fid) -> value -> advisees -> isEmpty() == false)
               {
                 cout << "Please enter the faculty member you wish the student to go to." << endl;
                 cout << "Current Student ID: " << masterFaculty -> getNode(fid) -> value -> advisees -> valueAt(0) -> m_ID << endl;
                 int phID = 0;
                 cin>>phID;
                 while (masterFaculty -> searchNode(phID) == false)
                 {
                   cout << "that isn't a valid faculty ID. Please enter a valid ID." << endl;
                   cin >>phID;
                 }
                 masterFaculty -> getNode(phID) -> value -> advisees -> insertFront(masterFaculty ->getNode(fid) -> value -> advisees -> removeFront());
               }
               masterFaculty -> deleteNode(masterFaculty->getNode(fid) -> value);
             } else {
               cout << "that faculty member doesn't exist. Please check your info and try again." << endl;
             }
             break;

    case 11: cout << "what is the ID of the student who is having their advisor changed?" << endl;
             cin >> sid;
             if (masterStudent -> searchNode(sid))
             {
               //removes student from faculty list.
               masterFaculty -> getNode(masterStudent -> getNode(sid) -> value -> m_advisorID) ->  value -> advisees -> remove(masterStudent -> getNode(sid) -> value);
               cout << "What is the ID of the new advisor?" << endl;
               cin >> fid;
               while (masterFaculty -> searchNode(fid) == false)
               {
                 cout << "new advisor ID not found. Please try again." << endl;
                 cin >> fid;
               }
               //adds student to new faculty advisor.
               masterFaculty -> getNode(fid) -> value -> advisees -> insertBack(masterStudent -> getNode(sid) -> value);
               //changes over ID on student side.
               masterStudent -> getNode(sid) -> value -> m_advisorID = fid;
               cout << "id changed successfully!" << endl;

             }else{
               cout << "Student does not exist! Please try again." << endl;
             }
             break;

    case 12: {cout << "What is the ID of the faculty member being edited?" << endl;
             cin >> fid;
             if (masterFaculty -> searchNode(fid))
             {
              cout << "what is the ID of the student being removed?" << endl;
              cin >> sid;
              if (masterStudent -> searchNode(sid))
              {
                if (masterFaculty -> getNode(fid) -> value -> advisees -> search(masterStudent -> getNode(sid) -> value) != -1)
                {
                  //removes student from faculty list.
                  masterFaculty -> getNode(fid) ->  value -> advisees -> remove(masterStudent -> getNode(sid) -> value);
                  cout << "What is the ID of the new advisor for the removed student?" << endl;
                  int newFID = 0;
                  cin >> newFID;
                  while (masterFaculty -> searchNode(newFID) == false)
                  {
                    cout << "new advisor ID not found. Please try again." << endl;
                    cin >> fid;
                  }
                  //adds student to new faculty advisor.
                  masterFaculty -> getNode(newFID) -> value -> advisees -> insertBack(masterStudent -> getNode(sid) -> value);
                  //changes over ID on student side.
                  masterStudent -> getNode(sid) -> value -> m_advisorID = newFID;
                  cout << "id changed successfully!" << endl;
                } else {
                  cout << "That student is not an advisee of this specific faculty member. Check your info and try again." << endl;
                }

              } else {
                cout << "No student assigned that ID. Please check your info and try again." << endl;
              }
             } else {
               cout << "No faculty member assigned that ID. Please check your info and try again." << endl;
             }
             break;
             }


    case 13: //ROLLBACK

    case 14: toExit = true;
             cout << "Now exiting and saving. Thank you for using the Database Manager!" << endl;
             break;

    default: cout << "Invalid option selected! Please try again." << endl;
             break;
  }
}


int main(int argc, char **argv)
{
  initializeDatabase();

  while (toExit == false)
  {
    showOptions();
  }
  //saveAndQuit();
}
