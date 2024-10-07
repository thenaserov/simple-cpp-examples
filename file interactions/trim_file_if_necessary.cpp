void trim_file_if_necessary(const std::string& filepath, size_t max_size) {  
    std::ifstream infile(filepath, std::ios::ate | std::ios::binary);  
    
    if (!infile) {  
        std::cerr << "Error opening file: " << filepath << std::endl;  
        return;  
    }  
    
    size_t current_size = infile.tellg();  
    infile.close();  

    if (current_size > max_size) {  
        std::ifstream input(filepath);  
        std::ofstream temp("temp_file.txt");  

        if (!input || !temp) {  
            std::cerr << "Error opening file for trimming." << std::endl;  
            return;  
        }  

        // Skip the first 200 MB  
        input.seekg(max_size, std::ios::beg);  

        // Write the rest to a temporary file  
        temp << input.rdbuf();  

        input.close();  
        temp.close();  

        // Replace the original file with the trimmed file  
        std::remove(filepath.c_str());  
        std::rename("temp_file.txt", filepath.c_str());  
    }  
}
