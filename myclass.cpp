
#include <stdio.h>

#include "myclass.hh"
#include "myclass_c.h"



MyClass::MyClass() {
  val = 0;
  printf("MyClass: constructor\n");
}
MyClass::~MyClass(){
  printf("MyClass: destructor last - val is %d\n", val);
}

void MyClass::Set(int i){
  printf("MyClass: set to %d\n", i);
  val = i;
}
int MyClass::Get(){
  printf("MyClass: get of %d\n", val);
  return val;
}


inline MyClass * real(myclass *mc){ return static_cast<MyClass *>(mc); }

myclass *myclass_new(){ return new MyClass(); }
void     myclass_delete(myclass *mc){ delete real(mc); }

void     myclass_set(myclass *mc, int val) { real(mc)->Set(val); }
int      myclass_get(myclass *mc) { return real(mc)->Get(); }


