#include <iostream>
#include <vector>
#include <array>
#include <list>

int main() {
    // Containers are used to store homogeneous data.

    // C style array type
    // int numbers[100];
    // char* name = {'a', 'b', 'c', 'd', 'e'}; 
    // cons : undefined behaviours if you access index outside the range, fixed size and size must be defined at compile time

    // STL containers >>>>>

    // sequence containers     (elements are accessed by index) -> linear and contagious
    // std::array, std::vector                  -> contagious in memory
    // std::deque, std::forwardlist, std::list  -> not

    // Associative containers  (elements are accessed by key - not by position)
    // std::map, std::set, std::unordered_set, std::unordered_map

    // Adaptive containers     (not fully implemented containers - new api in the top of existing containers)
    // std::stack, std::queue, std::priority_queue

    // All containers have iterators that can be found in <algorithms> and <functional> header

    // Accessor methods for these containers
    //----------------------------------------------------------------

    return 0;
}