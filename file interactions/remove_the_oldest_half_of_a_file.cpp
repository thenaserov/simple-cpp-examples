#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>  

void checkAndTrimFileSize(const std::string& filepath, std::size_t maxFileSize) {  
    // Check the size of the log file  
    std::ifstream infile(filepath, std::ios::ate | std::ios::binary);  
    if (infile.is_open()) {  
        std::size_t fileSize = infile.tellg(); // Get the current size of the file  
        infile.close();  

        // If the file size exceeds the maximum limit, trim it  
        if (fileSize > maxFileSize) {  
            // Read current content  
            std::ifstream file(filepath);  
            std::ostringstream buffer;  
            buffer << file.rdbuf();  
            std::string content = buffer.str();  
            file.close();  

            // Calculate the number of bytes to keep (newest half)  
            std::size_t bytesToKeep = fileSize / 2;  

            // Create a new file with only the newest half of the content  
            std::ofstream outfile(filepath, std::ios::binary | std::ios::trunc);  
            outfile.write(content.data() + (fileSize - bytesToKeep), bytesToKeep);  
            outfile.close();  

            std::cout << "Trimmed the file to keep the newest half." << std::endl;  
        } else {  
            std::cout << "File size is within limit. No action taken." << std::endl;  
        }  
    } else {  
        std::cerr << "Error opening file to check its size." << std::endl;  
    }  
}  
