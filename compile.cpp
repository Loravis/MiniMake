#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "misc.h"

namespace fs = std::filesystem;

// minimake compile functionality
int compile() {
    fs::path configPath{std::string(fs::current_path()) + "/minimake.conf"};

    std::cout << "Searching minimake.conf...\n";

    if (fs::exists(configPath) == false) {
        std::cerr << "Config file not found! Did you forget to run minimake init?\n";
        return 1;
    } 

    std::cout << "Building...\n";
    std::string configPathString = std::string(configPath);
    
    ConfigFile cf(configPathString);
    
    std::string command = "g++ -std=" + cf.getStandard();
    std::string output = cf.getOutput();
    std::vector<std::string> libraries = cf.getLibraries();
    std::vector<std::string> include = cf.getInclude();

    if(libraries.size() > 0) {
        command = command + " -l";
        for(int i=0; i < libraries.size(); i++){
            command = command + " " + libraries[i];
        }
    }

    command = command + " -o " + output;

    if (include.size() == 0) {
        std::cerr << "ERROR: No code files specified. Ensure you include at least one code file in minimake.conf.";
        return 1;
    }

    for(int i=0; i < include.size(); i++){
        command = command + " " + include[i];
    }

    std::cout << "Executing: " << command << "\n";

    const char *cstr = command.c_str();
    if (std::system(cstr) != 0) {
        return 1;
    }

    std::cout << "Build finished successfully.\n";

    return 0;
}