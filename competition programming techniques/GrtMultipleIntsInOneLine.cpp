#include <iostream>
#include <vector>

int main(){
  int n;
  std::cin >> n;
  std::vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec[i];
  }
  return 0;
}
