package main

// #include "myclass_c.h"
// #cgo LDFLAGS: -L. -lmyclass -lstdc++  
import "C"
import "fmt"
import "strconv"

func main() {


	fmt.Println("Calling MyClass from go");
	mc := C.myclass_new();
	for i:=0; i<10; i++ {
		C.myclass_set(mc, C.int(i));
	}
	j:=int(C.myclass_get(mc));
	fmt.Println("Last value is '"+strconv.Itoa(j)+"'");

	C.myclass_delete(mc);

}
