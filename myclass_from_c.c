#include <stdio.h>

#include "myclass_c.h"


int main(){

  int i,j;

  printf("Calling MyClass from C\n");

  myclass *mc = myclass_new();

  for(i=0; i<10; i++)
    myclass_set(mc, i);

  j=myclass_get(mc);
  printf("Last value is '%d'\n", j);

  myclass_delete(mc);

}
