#include <stdio.h>
// yeah yeah.. should be iostreams instead of prints inside c++

#include "myclass.hh"


int main(){

  printf("Calling MyClass from C++\n");


  MyClass m;

  for(int i=0; i<10; i++)
    m.Set(i);

  int j = m.Get();
  printf("Last value is '%d'\n", j);

  
}

