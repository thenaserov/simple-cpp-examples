#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector>  

void checkAndTrimFileLines(const std::string& filepath, std::size_t maxFileSize, std::size_t linesToRemove) {  
    // Check the size of the log file  
    std::ifstream infile(filepath, std::ios::ate | std::ios::binary);  
    if (infile.is_open()) {  
        std::size_t fileSize = infile.tellg(); // Get the current size of the file  
        infile.close();  

        // If the file size exceeds the maximum limit, trim it  
        if (fileSize > maxFileSize) {  
            // Read current content into a vector of lines  
            std::ifstream file(filepath);  
            std::vector<std::string> lines;  
            std::string line;  

            while (std::getline(file, line)) {  
                lines.push_back(line);  
            }  
            file.close();  

            // Determine the number of lines we want to keep  
            std::size_t totalLines = lines.size();  

            // If there are more lines than the specified lines to remove  
            if (totalLines > linesToRemove) {  
                // Create a new file with the remaining lines  
                std::ofstream outfile(filepath, std::ios::binary | std::ios::trunc);  

                // Write only the lines we want to keep (excluding the oldest ones)  
                for (std::size_t i = linesToRemove; i < totalLines; ++i) {  
                    outfile << lines[i] << std::endl;  
                }  
                outfile.close();  

                std::cout << "Removed the oldest " << linesToRemove << " lines." << std::endl;  
            } else {  
                // If there are not enough lines, just truncate the file  
                std::ofstream outfile(filepath, std::ios::binary | std::ios::trunc);  
                outfile.close(); // Empty the file  
                std::cout << "Not enough lines to remove. File has been emptied." << std::endl;  
            }  
        } else {  
            std::cout << "File size is within limit. No action taken." << std::endl;  
        }  
    } else {  
        std::cerr << "Error opening file to check its size." << std::endl;  
    }  
}  

// Example usage  
int main() {  
    std::string filepath = "example.txt";  
    std::size_t maxFileSize = 1024 * 1024; // 1 MB  
    std::size_t linesToRemove = 1000;  
    checkAndTrimFileLines(filepath, maxFileSize, linesToRemove);  
    return 0;  
}
