#include <iostream>
#include <vector>
#include <exception>

template<typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "used : " << vec.size() << "/" << vec.capacity()
    << "max_size: " << vec.max_size() << std::endl;
    for (const auto& v : vec) {
        std::cout << v << "";
    }
    std::cout << std::endl;
}

int main() {
    // vectors are sequennce containers that representing arrays that can change in size
    // allocated in continous blocks of memory, can be aaccessed with pointers and []
    // pretty efficient in adding and removing from the end
    // you will get undefined behavior using at() getting std::out_of_range exception
    // Cons: 
    // not so good at insertions and deletions at arbitrary positions
    // they are dynamically allocated arrays that if a vector growa beyond capacity it will reallocate and copy all the content again before insertion can occur
    // this can cause at times, penalties if a proper starting size was not detemined
    // in general, realocating should happen at logarithmically growing internals of size


    std::vector<int> numbers;
    std::vector<std::string> strings{"Hello", "how", "are", "you", "doing", "?"};

    numbers.push_back(100);
    numbers.push_back(200);
    numbers.push_back(32);

    printVector(numbers);
    printVector(strings);

    strings.resize(3);
    printVector(strings);

    strings.resize(10, "XXXX");
    printVector(strings);

    numbers[0] = 43;
    numbers.push_back(400);
    numbers.push_back(500);
    printVector(numbers);

    
    for(int* p = &numbers[0]; p < &numbers[0] + numbers.size(); ++p) {
        std::cout << *p << "\n";
    }

    // Bad access
    std::cout << numbers[10] << std::endl;

    try{
        std::cout << numbers.at(10) << std::endl;
    } catch (std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}