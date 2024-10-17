#include <iostream>
#pragma once
namespace School
{
  const int default_number_students = 1;
  class Class
  {
    public:
      Class();
      
      void display_info();
      void add_student(int plus_student);
      void delete_student(int minus_student); 
      void increment_year_of_study(int year);
      
      void set_class_id(int class_id);
      void set_teacher_id(int teacher_id);
      void set_students_quantity(int students_quantity);
      void set_class_letter(char class_letter);
      void set_year_created(int year_created);
      void set_year_of_study(int year_of_study);
      void set_class_is_advanced(bool is_advanced); 
      
      int get_class_id();
      int get_teacher_id();
      bool get_class_is_advanced();
      int get_students_quantity();
      char get_class_letter();
      int get_year_created();
      int get_year_of_study();
      
      private:
      int class_id;
      int teacher_id;
      bool is_advanced;
      int students_quantity;
      char class_letter;
      int year_created;
      int year_of_study;
      
  };

}
