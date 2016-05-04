#include <iostream>

int main() {
  int* p1;
  int* p2;
  int x = 5;
  int y = 15;

  p1 = &x; 	 	// x contains 5; y 15; p1 address of x; p2 /
 
  p2 = &y;	 	// x contains 5; y 15; p1 address of x; p2 address of y
 
  *p1 = 6; 		// x contains 6; y 15; p1 address of x; p2 address of y
 
  *p1 = *p2;	// x contains 15; y 15; p1 address of x; p2 address of y
 
  p2 = p1; 		// x contains 15; y 25; p1 address of x; p2 address of x
 
  *p1 = *p2+10; // x contains 25; y 15; p1 address of x; p2 address of x
  
  return 0;
}
