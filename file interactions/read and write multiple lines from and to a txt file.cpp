// *************************************************************************
// ****************************** 2023.03.09 *******************************
// ****************** simple C++ examples By Naser Rezayi ******************
// ********* READ AND WRITE MULTIPLE LINES FROM AND TO A TXT FILE **********
// *************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::fstream file;
	std::vector<std::string> data_container;
	data_container.push_back("my keyboard is awesome");
	data_container.push_back("I love typing on it");
	// WRITE OPERTATION
	file.open("file.txt", std::ios::out);
	if (file.is_open())
	{
	    for (std::string element: data_container)
	    {
		file << element << "\n";
	    }
            file << "my keyboard is great\n";
	    file.close();
	}

	// READ OPERATION
	file.open("file.txt", std::ios::in);
	std::vector<std::string> in_data_container;
  	if (file.is_open()) {
        std::string text;
        while (std::getline(file, text)) {
            std::cout << text << "\n";
	    in_data_container.push_back(text);
        }
        file.close();
    }
	return 0;
}
