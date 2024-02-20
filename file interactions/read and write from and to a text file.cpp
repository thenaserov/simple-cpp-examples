// *************************************************************************
// ****************************** 2023.03.09 *******************************
// ****************** simple C++ examples By Naser Rezayi ******************
// ***************** READ AND WRITE FROM AND TO A TXT FILE *****************
// *************************************************************************
#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::fstream file;

	// WRITE OPERTATION
	file.open("file.txt", std::ios::out);
	if (file.is_open()) {
		file << "my keyboard is great\n";
		file.close();
	}

	// READ OPERATION
	file.open("file.txt", std::ios::in);
    	if (file.is_open()) {
        std::string text;
        while (std::getline(file, text)) {
            std::cout << text << "\n";
        }
        file.close();
    }
	return 0;
}
