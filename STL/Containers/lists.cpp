#include <iostream>
#include <list>

int main() {
    // lists are dynamically sized sequence containers that allows constant time insert and delete anywhere in the sequence
    // lists are implemented as doubly linked lists
    // each element in the list is allocated in a different location of memory
    // as they are associated by pointers to the next and previous elements
    // compared to other base standard sequence containers(array, vector, deque, list)
    // perfrom generally better in inserting extracting anfd moving elements in any within the container
    // a forward_list is a simplified version of list but just pointing to the next element
    // lists are random access and can to be indexed by []
    // you take small memory penalty
    // to access the 5th element you should iterate 5 times


    std::list<int> mylist {10, 20, 25, 30, 40, 50};
    std::list<int> other {15, 25, 35, 45, 50, 55};
    // merge, tranfers all element from other to mylist
    mylist.merge(other);

    std::cout << "list size = " << mylist.size() << "\n";
    // after the merge mylist has 12 elements and other has 0
    // cause merge tranfers the elements 
   
    // remember we can not use the bracket operator to access the elements 
    // so we must use iterators like bellow
    for (auto i = mylist.begin(); i != mylist.end(); ++i){
      std::cout << *i << " ";
    }
    std::cout << "\n";

    // Only hold unique elements and remove all the duplicates
    mylist.unique();
    for (auto i = mylist.begin(); i != mylist.end(); ++i){
      std::cout << *i << " ";
    }

    std::cout << "\n";
    return 0;
}