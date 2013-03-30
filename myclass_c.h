#ifndef MYCLASS_C_H
#define MYCLASS_C_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct myclass myclass;

myclass * myclass_new();
void myclass_delete(myclass *mc);

void myclass_set(myclass *mc, int val);
int  myclass_get(myclass *mc);


#ifdef __cplusplus
}
#endif


#endif
