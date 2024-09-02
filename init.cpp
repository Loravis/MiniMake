#include <iostream>
#include <fstream>
#include <filesystem>

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

        std::ifstream templateFile("minimake.template.conf");
        std::string templateContent;
        std::string line;

        while (std::getline(templateFile, line)) {
            templateContent.append(line + "\n");
        }

        file << templateContent;
        std::cout << "Created config file.\n";
    }

    // Check if main.cpp already exists in directory
    if (fs::exists(mainPath)) {
        std::cout << "Main code file already exists in the specified directory. Skipping...\n";
    } 

    // Create main.cpp if it doesn't exist yet
    else {
        std::ofstream file(mainPath);

        std::ifstream templateFile("main.template.cpp");
        std::string templateContent;
        std::string line;

        while (std::getline(templateFile, line)) {
            templateContent.append(line + "\n");
        }

        file << templateContent;
        std::cout << "Created main code file.\n";
    }

    std::cout << "Initialization finished!\n";
}