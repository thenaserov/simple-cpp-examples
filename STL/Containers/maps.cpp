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
    // I don't understand this peace of code my self!
    // UPDATE : When the insert is called a pair will be returned!
    // the first of our retuened pair is an iterator and the second is
    // boolean saying if our item was inserted!
    const auto [iterator, inserted] = mMap.insert({"third", SimpleObject});

    if (inserted) {
        std::cout << "item inserted" << std::endl;
    } else {
        std::cout << "key exists, item not inserted!" << std::endl;
    } // In this case it won't allow us to insert the key cause the key already exists

    // How to go through all the data in our map
    for(auto &x: mMap){
        std::cout << x.first() << " " << x.second() << std::endl;
    }

    // To remove an element
    mMap.erase("second");

    // To find a key
    auto ptr = mMap.find("second");
    
    return 0;
}
