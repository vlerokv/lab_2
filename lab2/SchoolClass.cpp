#include <iostream>
#include "SchoolClass.h"

using namespace std;

namespace School
{
  Class::Class()
  {
    class_id = 0;
    teacher_id = 0;
    is_advanced = false;
    students_quantity = 0;
    class_letter = 'A';
    year_created = 2023;
    year_of_study = 1;  
  }
  
  void Class::add_student(int plus_student)
  {
    set_students_quantity(get_students_quantity() + plus_student);
  }
  
  void Class::delete_student(int minus_student)
  {
    set_students_quantity(get_students_quantity() - minus_student);
  }
  
  void Class::increment_year_of_study(int year)
  {
    set_year_of_study(get_year_of_study() + year);
  }
  
  void Class::display_info()
  {
    cout << "Class id:" << get_class_id() << endl;
    cout << "Class name:" << get_year_of_study() << "-" << get_class_letter() << endl;
    cout << "Teacher id:" << get_teacher_id() << endl;
    cout << (is_advanced? "Advanced class" : "Regular class") << endl;
    cout << "Number of students:" << get_students_quantity() << endl;
    cout << "Year of creation:" << get_year_created() << endl;
    cout << endl;
  }
  
  int Class::get_class_id()
  {
    return class_id;
  }
  
  int Class::get_teacher_id()
  {
    return teacher_id;
  }
  
  bool Class::get_class_is_advanced()
  {
    return is_advanced;
  }
  
  int Class::get_students_quantity()
  {
    return students_quantity;
  }
  
  char Class::get_class_letter()
  {
    return class_letter;
  }
  
  int Class::get_year_created()
  {
    return year_created;
  }
  
  int Class::get_year_of_study()
  {
    return year_of_study;
  }
  
  void Class::set_class_id(int class_id)
  {
    this->class_id = class_id;
  }
  
  void Class::set_teacher_id(int teacher_id)
  {
    this->teacher_id = teacher_id;
  }
  
  void Class::set_students_quantity(int students_quantity)
  {
    this->students_quantity = students_quantity;
  }
  
  void Class::set_class_letter(char class_letter)
  {
    this->class_letter = class_letter;
  }
  
  void Class::set_year_created(int year_created)
  {
    this->year_created = year_created; 
  }
  
  void Class::set_year_of_study(int year_of_study)
  {
    this->year_of_study = year_of_study;
  }
  
  void Class::set_class_is_advanced(bool is_advanced) 
  {
    this->is_advanced = is_advanced;
  }
};
