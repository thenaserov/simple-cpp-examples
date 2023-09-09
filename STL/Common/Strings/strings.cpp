#include <iostream>
#include <string>

int main() {
    // initialization of std::strings

    // anything between double qoutes are considred const character pointer
    std::string name = "Naser Rezayi";
    // explicit
    std::string n2("Naser Rezayi");
    // copying name to n3
    std::string n3(name);
    // char array
    std::string n4{ 'N', 'a', 's', 'e', 'r' };
    // along with offset position
    std::string last(name, 6, 6);
    // fill constructor
    std::string line(20, '-');
    // reverse of a string with reverse begin and end
    std::string reverse(name.rbegin(), name.rend());

    // finding std::string
    std::size_t pos = name.find(n4);
    // std::string::npos mean not found
    if (pos != std::string::npos) {
        std::cout << "found firstname at : " << pos << std::endl;

    }
    // this s after our Hello, How are you? is a string literal technique to force the compiler to see this data as std::string 
    //("Hello, How are you?"s)
    std::cout << "Comma at :" << (std::string("Hello, How are you?")).find(",") << std::endl;

    std::cout << line << std::endl;

    // append to strings
    std::string about = "is a programmer";
    name.push_back(' ');
    for (auto c : about) {
        name.push_back(c);
    }
    std::cout << name << std::endl;

    // to insert into string
    name.insert(0, "I have heard that ");
    std::cout << name << std::endl;

    // Replace some string
    pos = name.find("programmer");
    name.replace(pos, std::string("programmer").length(), "snowboarder");

    pos = name.find("heard");
    name.erase(pos, std::string("heard").length());
    name.insert(pos, "read somewhere");
    std::cout << name << std::endl;


    return 0;
}
