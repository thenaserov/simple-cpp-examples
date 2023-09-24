#include <iostream>
#include <array>


/**
 * The Dutch National Flag problem is a three way partitioning problem. This
 * is one possible solution. 
 */
template<typename T>
void dutch_flag_sort(T arr[], int size, T midVal) {
  int i = 0, j = 0;
  int n = size - 1; 

  while (j <= n) {
    if (arr[j] < midVal) {
      T temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
      i++;
      j++;
    }
    else if (arr[j] > midVal) {
      T temp = arr[j];
      arr[j] = arr[n];
      arr[n] = temp;
      n--;
    }
    else {
      j++;
    }
  }
}


int main() {
    // Standard arrays work like C style arrays:
    // fixed size at compile time
    // swapping and moving is a linear time operation
    // there's no dynamic shrinking or growing

    // they can be used as tuple objects
    // std::array knows its own size
    
    // C style arrays
    int numbers[20] = {0,1,2,0,0,2,2,1,1,0,1,2,2,1,0,0,0,0,1,1};
    // STL style arrays
    std::array<int, 20> numbers2 = {0,1,2,0,0,2,2,1,1,0,1,2,2,1,0,0,0,0,1,1};

    // dutch national flag sort

    dutch_flag_sort(numbers, 20, 1);
    // nembers2.data() returns a raw pointer to the first element of the array
    dutch_flag_sort(numbers2.data(), numbers2.size(), 1);
    // &numbers[0] also points to the first element of the array
    dutch_flag_sort(&numbers2[0], numbers2.size(), 1);

    std::cout << "numbers: ";
    for (int i : numbers) {
      std::cout << i << " ";
    }

    std::cout << std::endl;
    std::cout << "numbers2: ";
    for (int i : numbers2) {
      std::cout << i << " ";
    }
  
    std::cout << std::endl;

    return 0;
}