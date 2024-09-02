#include <iostream>
#include <filesystem>
#include <vector>
#include "misc.h"

namespace fs = std::filesystem;

// minimake auto functionality
int autosearch() {
    std::vector<std::string> files;

    const std::string currentPath = fs::current_path();

    if (fs::exists(currentPath + "/minimake.conf") == false) {
        std::cout << "Couldn't find minimake.conf in your current working directory. Did you forget to run minimake init?\n";
        return 1;
    }

    std::cout << "Searching .cpp/.cc files...\n";
    for (const fs::directory_entry& entry : fs::recursive_directory_iterator(currentPath)) {
        std::string file = entry.path();
        const std::string currentPath2 = currentPath + "/";
        const std::string toReplace = "";
        replace(file, currentPath2, toReplace);
        
        if (file.find(".cpp") != std::string::npos or file.find(".cc") != std::string::npos) {
            std::cout << "Found " << file << "\n";
            files.push_back(file);
        }
    }

    fs::path configPath{std::string(fs::current_path()) + "/minimake.conf"};
    std::string configPathString = std::string(configPath);

    ConfigFile cf(configPathString);
    cf.setInclude(files);
    
    return 0;
}