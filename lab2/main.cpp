#include "UserInterface.h"

//#define HEAP_ALLOC
#ifdef HEAP_ALLOC
int main(int argc, char** argv)
{
  auto UI = new School::UserInterface();
  UI->run();
  delete UI;
}

#else
int main(int argc, char** argv)
{
  auto UI = School::UserInterface();
  UI.run();
}

#endif
