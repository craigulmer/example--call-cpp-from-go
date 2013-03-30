
TARGETS=\
	myclass_from_cpp \
	myclass_from_c  \
	myclass_from_go

OBJS=\
	myclass.o \
	myclass.so \
	libmyclass.a

all: $(TARGETS)


# First, just simple cpp
myclass.o: myclass.cpp myclass.hh
	g++ -c $< 

myclass_from_cpp: myclass_from_cpp.cpp myclass.o
	g++ $< myclass.o -o $@


# Second, link to a c program in gcc - make sure you include stdc++
myclass_from_c: myclass_from_c.c myclass.o
	gcc $< myclass.o -o $@ -lstdc++



# Third, build a shared object Go can pull in
myclass.so: myclass.cpp myclass.hh
	g++ -fPIC -shared $< -o $@

libmyclass.a: myclass.so
	ar rvs $@ $<

myclass_from_go: myclass_from_go.go libmyclass.a
	go build myclass_from_go.go


# Make sure object is in path for shared object to work
run: myclass_from_go
	LD_LIBRARY_PATH=. ./myclass_from_go


clean:
	rm -f $(TARGETS) $(OBJS)




