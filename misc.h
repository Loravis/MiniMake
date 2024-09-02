#ifndef MISC
#define MISC
#include <vector>
#include <filesystem>

bool replace(std::string& str, const std::string& from, const std::string& to);

class ConfigFile{
    private:
        std::vector<std::string> lines;
        std::string text;
        std::string configFilePath;

        bool readingInclude = false;
        bool readingLibs = false;

        std::string standard;
        std::string output;
        std::vector<std::string> include;
        std::vector<std::string> libraries;
    public: 
        ConfigFile(std::string confPath);
        std::string getStandard();
        std::string getOutput();
        std::vector<std::string> getInclude();
        std::vector<std::string> getLibraries();
        void setInclude(std::vector<std::string> files);
};

#endif