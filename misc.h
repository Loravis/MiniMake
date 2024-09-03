#ifndef MISC
#define MISC
#include <vector>
#include <filesystem>

const std::string VERSION = "1.0.1";
const std::string HELP_STRING = "MINIMAKE" + VERSION + ", by Loravis\n\n- minimake help : Display this information\n- minimake init : Initialize current working directory \n- minimake auto : Detect C++ code files within working directory and sub folders and insert them into minimake.conf \n- minimake build : Build a project within the current working directory\n\n";

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