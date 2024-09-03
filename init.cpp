#include <iostream>
#include <fstream>
#include <filesystem>
#include "misc.h"

namespace fs = std::filesystem;

// minimake init functionality
void init() {
    fs::path configPath{std::string(fs::current_path()) + "/minimake.conf"};
    fs::path mainPath{std::string(fs::current_path()) + "/main.cpp"};

    std::cout << "Initializing MiniMake in path; " << std::string(fs::current_path()) << "...\n";
    
    // Check if minimake.conf already exists in directory
    if (fs::exists(configPath)) {
        std::cout << "Config file already exists in the specified directory. Skipping...\n";
    } 

    // Create minimake.conf if it doesn't exist yet
    else {
        std::ofstream file(configPath);

        file << CONFIG_TEMPLATE;
        std::cout << "Created config file.\n";
    }

    // Check if main.cpp already exists in directory
    if (fs::exists(mainPath)) {
        std::cout << "Main code file already exists in the specified directory. Skipping...\n";
    } 

    // Create main.cpp if it doesn't exist yet
    else {
        std::ofstream file(mainPath);

        file << MAIN_TEMPLATE;
        std::cout << "Created main code file.\n";

        file.close();
    }

    std::cout << "Initialization finished!\n";
}