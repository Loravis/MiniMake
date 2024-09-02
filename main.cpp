//Compile using; g++ -std=c++2c -o minimake main.cpp init.cpp compile.cpp auto.cpp misc.cpp

#include <iostream>
#include <fstream>
#include "help.h"
#include "misc.h"

void init();
int compile();
int autosearch();

int main(int argc, char* argv[]) {

    // Argument interpretation
    if (argc < 2) {
        std::cerr << "Missing arguments!\n";
        return 1;
    }
    else {
        if (std::string(argv[1]) == "init") {
            init();
            return 0;
        }
        else if (std::string(argv[1]) == "help") {
            std::cout << HELP_STRING;
            return 0;
        } else if (std::string(argv[1]) == "build"){
            if (compile() == 1) {
                return 1;
            }
        } else if (std::string(argv[1]) == "auto") {
            if (autosearch() == 1) {
                return 1;
            }
        } else if (std::string(argv[1]) == "--version" or std::string(argv[1]) == "-v") {
            std::cout << "MiniMake 1.0\n";
        }
    }

    return 0;
}