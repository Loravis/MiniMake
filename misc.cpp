#include <iostream>
#include "misc.h"
#include <vector>
#include <fstream>
#include <filesystem>
#include <cstdio>

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

ConfigFile::ConfigFile(std::string confPath) {
    configFilePath = confPath;
    std::ifstream confFile(confPath);
    while(getline (confFile, text)) {
        lines.push_back(text);
    }

    for(int i=0; i < lines.size(); i++){
        std::string line = lines[i];
        if (replace(line, "std=", "")) {
            standard = line;
        } else if (replace(line, "output=", "")) {
            output = line;
        } else if (line == "[include]") {
            readingLibs = false;
            readingInclude = true;
        } else if (line == "[libraries]") {
            readingLibs = true;
            readingInclude = false;
        } else if (readingInclude) {
            if ((line != "") && (line.find("#") == std::string::npos)) {
                include.push_back(line);
            }
        } else if (readingLibs) {
            if ((line != "") && (line.find("#") == std::string::npos)) {
                libraries.push_back(line);
            }
        }
    }
}

std::string ConfigFile::getStandard() {
    return standard;
}
std::string ConfigFile::getOutput() {
    return output;
}
std::vector<std::string> ConfigFile::getInclude() {
    return include;
}
std::vector<std::string> ConfigFile::getLibraries() {
    return libraries;
}

void ConfigFile::setInclude(std::vector<std::string> files) {
    for(int i=0; i < lines.size(); i++){
        std::string line = lines[i];
        if (line == "[include]"){
            for (int r = i + 1; r < lines.size(); r++) {
                if (lines[r].find(".cpp") == std::string::npos and lines[r].find(".cc") == std::string::npos) 
                    break;

                lines.erase(lines.begin() + r);
            }

            for(int j=0; j < files.size(); j++) {
                lines.insert(lines.begin() + i + 1 + j, files[j]);
            }
            break;
        }
    }

    std::remove(configFilePath.c_str());
    std::ofstream configFile(configFilePath);
    for(int i=0; i < lines.size(); i++){
        configFile << lines[i] << "\n";
    }
    configFile.close();
}