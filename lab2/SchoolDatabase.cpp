#include <iostream>
#include <stdexcept>
#include "SchoolDatabase.h"

using namespace std;

namespace School
{
  Database::Database()
  {
    nextClass = 0;
    nextId = StartClassID; 
  }
  
  Database::~Database()
  {
  
  }
  
  Class& Database:: addClass(int class_id, int teacher_id, bool is_advanced, int students_quantity, char class_letter, int year_created, int year_of_study )
  {
    if(nextClass >= MaxClasses)
    {
      cerr << "Maximum number of classes reached!" << endl;
      throw exception();
    }
    
    else
    {
      Class& _class = Classes[nextClass++];
      _class.set_class_id(class_id);
      _class.set_teacher_id(teacher_id);
      _class.set_students_quantity(students_quantity);
      _class.set_class_letter(class_letter);
      _class.set_year_created(year_created);
      _class.set_year_of_study(year_of_study);
      _class.set_class_is_advanced(is_advanced);
      
      return _class;
    }
  }
    
  Class& Database::getClassById(int class_id)
  {
    for(int i = 0; i < nextClass; i++)
    {
      if(Classes[i].get_class_id() == class_id)
      {
        return Classes[i];
      }
    }
    throw exception();
  }
  
  
  void Database::displayAllClasses()
  {
    for(int i = 0; i < nextClass; i++)
    {
      Classes[i].display_info();
    }
  }
    
  void Database::displayAdvanced()
  {
    for(int i = 0; i < nextClass; i++)
    {
      if(Classes[i].get_class_is_advanced())
      {
        Classes[i].display_info();
      }
    }
  }
    
  void Database::displayRegular()
  {
    for(int i = 0; i < nextClass; i++)
    {
      if(!Classes[i].get_class_is_advanced())
      {
        Classes[i].display_info();
      }
    }
  }
    
}
