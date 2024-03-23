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

    std::map<std::string, SimpleObject> mMap;
    // insert in pair constructor
    mMap.insert(std::pair<std::string, SimpleObject>("first", SimpleObject(4, 8, "Hello")));
    // bracket notation init
    mMap["second"] = SimpleObject();
    // overwrite the "second"
    mMap["second"] = SimpleObject(0, 0, "overwritten");
    // auto 
    mMap["third"] = SimpleObject(1, 6, "world");
    // auto
    mMap.insert({"fourth", SimpleObject(1, 1, "number")});

    // use structured bindings to get a pair if a pair with the key "third" has been already inserted
    
    return 0;
}