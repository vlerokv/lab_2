#include <iostream>
#include "SchoolClass.h"
#pragma once
namespace School
{
  const int MaxClasses = 4;
  const int StartClassID = 1;
  
  class Database
  {
    public:
      Database();
      ~Database();
      
      
      Class& addClass(int class_id, int teacher_id, bool is_advanced, int students_quantity, char class_letter, int year_created, int year_of_study);
      
      Class& getClassById(int class_id);
      
      void displayAllClasses();
      
      void displayAdvanced();
      
      void displayRegular();
      
    protected:
    Class Classes[MaxClasses];
    int nextClass;
    int nextId;
  };
}
