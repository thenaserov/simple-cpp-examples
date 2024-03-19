#include <iostream>
#include <map>

struct SimpleObject{
    int x;
    int y;
    std::string z;

    SimpleObject() : x(1), y(2), z("Something"){

    }
    SimpleObject(int x, int y, std::string z): x(x), y(y), z(z){

    }
};


int main()
{
    std::cout << "Maps" << std::endl;
    std::map<std::string, std::string> stringMap;
    stringMap.insert({"Hello", "World"});
    std::cout << stringMap["Hello"] << std::endl;
    
    return 0;
}
