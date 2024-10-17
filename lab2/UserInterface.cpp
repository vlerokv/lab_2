#include <iostream>
#include <stdexcept>
#include <limits>
#include <cctype>

#include "UserInterface.h"
#include "SchoolDatabase.h"


using namespace std;
using namespace School;

UserInterface::UserInterface()
{
     
}
  
UserInterface::~UserInterface()
{
  
}

int displayMenu(); //done
void addClass(Database& database); //done
void displayAllClasses(Database& database); //done
void displayAdvancedClasses(Database& database); //done
void displayRegularClasses(Database& database);
void addStudent(Database& database);
void deleteStudent(Database& database);
void incrementClassYear(Database& database);
bool handleInvalidInput();
bool isClassIDUnique(Database& database, int class_id);

void UserInterface::run()
{
  Database database;
  bool done = false;
  
  while(!done)
  {
    int choice = displayMenu();
    switch (choice)
    {
      case 1:
        addClass(database);
        break;
      case 2:
        displayAllClasses(database);
        break;
      case 3:
        displayAdvancedClasses(database);
        break;
      case 4:
        displayRegularClasses(database);
        break;
      case 5:
        addStudent(database);
        break;
      case 6:
        deleteStudent(database);
        break;
      case 7:
        incrementClassYear(database);
        break;
      case 8:
        done = true;
        break;
      default:
        cerr << "We do not have this command" << endl;
    }
  }
}

int displayMenu()
{
  int choice; 
  cout << endl;
  cout << "Options:" << endl;
  cout << "1) Add class" << endl;
  cout << "2) Display all classes" << endl;
  cout << "3) Display advanced classes" << endl;
  cout << "4) Display regular classes" << endl;
  cout << "5) Add student" << endl;
  cout << "6) Delete student" << endl;
  cout << "7) Increment class year" << endl;
  cout << "8) Quit" << endl;
  cout << endl;
  
  cout << "Your choice: ";
  cin >> choice;
  return choice;
}

void displayAllClasses(Database& database)
{
  database.displayAllClasses();
}

void displayAdvancedClasses(Database& database)
{
  database.displayAdvanced();
}

void displayRegularClasses(Database& database)
{
  database.displayRegular();
}

void addClass(Database& database) 
{
    int class_id, teacher_id, students_quantity, year_created, year_of_study;
    char class_letter;
    bool is_advanced;
  
    cout << "Class ID: ";
    cin >> class_id;

    
    if (handleInvalidInput() || !isClassIDUnique(database, class_id) || class_id <= 0)
    {
        cerr << "Invalid input or class ID is not unique." << endl;
        return;
    }
  
    cout << "Teacher ID: ";
    cin >> teacher_id;
    if (handleInvalidInput() || teacher_id <= 0) 
    {
        cerr << "Invalid Teacher ID input!" << endl;
        return;
    }

    cout << "Number of students: ";
    cin >> students_quantity;
    if (handleInvalidInput() || students_quantity <= 0) 
    {
        cerr << "Invalid number of students input!" << endl;
        return;
    }

    cout << "Year of class creation: ";
    cin >> year_created;
    if (handleInvalidInput() || year_created <= 0) 
    {
        cerr << "Invalid year of class creation input!" << endl;
        return;
    }

    cout << "Year of study: ";
    cin >> year_of_study;
    if (handleInvalidInput() || year_of_study <= 0 || year_of_study > 11) 
    {
        cerr << "Invalid year of study input!" << endl;
        return;
    }

    cout << "Class letter: ";
    cin >> class_letter;
    if (handleInvalidInput() || !isalpha(class_letter)) 
    {
        cerr << "Invalid class letter input!" << endl;
        return;
    }

    cout << "Is this an advanced class? (1 - yes; 0 - no;): ";
    cin >> is_advanced;
    if (handleInvalidInput()) 
    {
        cerr << "Invalid input for advanced class flag!" << endl;
        return;
    }

    try
    {
        database.addClass(class_id, teacher_id, is_advanced, students_quantity, class_letter, year_created, year_of_study);
        cout << "Class added successfully!" << endl;
    }
    catch (const exception& ex)
    {
        cerr << "Class is not  added" << endl; 
    }
}

void addStudent(Database& database)
{
  int class_id, numberOfStudents;
   cout << "Class ID: ";
   cin >> class_id;
   if (handleInvalidInput() || class_id <= 0)
    {
        cerr << "Invalid input" << endl;
        return;
    }

   cout << "Number of students to add: ";
   cin >> numberOfStudents;
   if (handleInvalidInput() || numberOfStudents <= 0 )
    {
        cerr << "Invalid input" << endl;
        return;
    }
    
   try
   {
    Class& _class = database.getClassById(class_id);
    _class.add_student(numberOfStudents);
    cout << "Students are added" << endl;
   }
   catch(exception& e)
   {
    cerr << "Students are not added" << endl;
   }
}

void deleteStudent(Database& database)
{
  int class_id, numberOfStudents;
   cout << "Class ID: ";
   cin >> class_id;
   if (handleInvalidInput() || class_id <= 0)
    {
        cerr << "Invalid input" << endl;
        return;
    }
    
   cout << "Number of students to delete: ";
   cin >> numberOfStudents;
   
   if (handleInvalidInput() || numberOfStudents <= 0)
    {
        cerr << "Invalid input" << endl;
        return;
    }
   try
   {
    Class& _class = database.getClassById(class_id);
    if (numberOfStudents >= _class.get_students_quantity())
    {
      cerr << "Trying to delete more students than available" << endl;
      return;
    }
    
    _class.delete_student(numberOfStudents);
    cout << "Students are deleted" << endl;
   }
   catch(exception& e)
   {
    cerr << "Students are not deleted" << endl;
   }
}

void incrementClassYear(Database& database)
{
  int class_id, numberOfYears;
   cout << "Class ID: ";
   cin >> class_id;
   if (handleInvalidInput() || class_id <= 0)
    {
        cerr << "Invalid input" << endl;
        return;
    }
   cout << "Number of years to increase: ";
   cin >> numberOfYears;
   if (handleInvalidInput() || numberOfYears <= 0 )
    {
        cerr << "Invalid input" << endl;
        return;
    }
   try
   {
    Class& _class = database.getClassById(class_id);
    
    if(_class.get_year_of_study() + numberOfYears > 11)
    {
      cerr << "Year of study cannot exceed 11" << endl;
      return;
    }
    
    _class.increment_year_of_study(numberOfYears);
    cout << "Years are added" << endl;
   }
   catch(exception& e)
   {
    cerr << "Class is not found" << endl;
   }
}

bool handleInvalidInput()
{
  if(cin.fail())
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << "Invalid input" << endl;
    return true;
  }
  return false;
}

bool isClassIDUnique(Database& database, int class_id)
{
    try
    {
      database.getClassById(class_id);
      return false;
    }
    catch (exception& e)
    {
      return true;
    }
}

