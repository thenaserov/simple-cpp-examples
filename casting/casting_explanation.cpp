#include <iostream>

int main()
{
    // implicit : automatic casting
    // explicit : you need to prepare the casting
    // 
    // implicit casting example
    int a = 2;
    double b = 3.14;
    double c = 0;
    c = a + b;
    std::cout << c << std::endl;

    // explicit casting
    int aa = 20;
    float bb = (float)aa / 10;
    std::cout << bb << std::endl;

    // static_cast
    // static_cast < new_type >( the_variable )
    // this casting tells the compiler to two different data types (built-in)
    // we may have loss of precision
    // pointer conversion RELATED pointer types
    float aaa = static_cast<float>(aa);

    // const_cast 
    // const_cast < new_type > ( the_vasriable )
    // the most least used casts
    // does not cast between different types
    // it changes the constness of the variables
    // switch between changable and not
    // it's not offered to be used ! ! !
    
    // reinterpret_cast< new_type > ( the_variable )
    // this casting, casts everything
    // from anytype to anytype
    // from any pointer type to any pointer type
    // *** it does not interfear with the constness
    // you don't have type safety
    int finalNumber = 1;
    int *finalInt = &finalNumber;
    int *finalDouble = reinterpret_cast<int*>(finalInt);
    std::cout << *finalDouble << std::endl;

    // we new an int with the value of 65
    int* p = new int(65); // A
    // we convert 65 to a character (the memory address will be swapped)
    char* ch = reinterpret_cast<char*>(p);
    std::cout << *ch << std::endl;
    return 0;
}