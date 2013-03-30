#ifndef MYCLASS_HH
#define MYCLASS_HH

struct myclass { };

class MyClass : public myclass {

public:
  MyClass();
  ~MyClass();

  void Set(int i);
  int Get();

private:
  int val;

};


#endif
