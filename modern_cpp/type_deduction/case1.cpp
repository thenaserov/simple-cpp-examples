#include <iostream>

template <typename T>
void f(T& param){}


int main(){
  int x = 27;
  const int cx = x;
  const int& rx = x;

  f(x);
  f(cx);
  f(rx);
  /* 
  FIRST: EASY
  SECOND : EASY
  
  THIRD :
  In the third example, note that even though rx’s type is a reference, T is deduced to
  be a non-reference. That’s because rx’s reference-ness is ignored during type deduction.
  */
  
  return 0;
}
