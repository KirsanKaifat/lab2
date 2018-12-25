#include <iostream>
#include <fstream>
#include "Stack.h"
#include "Validator.h"

int main(int argc, char* argv []) {

    if (argc != 2){
        std::cout << "USAGE: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    std::ifstream inputFile (argv[1]);

    if (!inputFile.is_open()) {
        std::cout << "File not found" << std::endl;
        return 2;
    }

    Validator *validator = new Validator(&inputFile);

    if (validator->Validate()) {
        std::cout << "File valid" << std::endl;
    } else {
        std::cout << "File invalid" << std::endl;
    }

    inputFile.close();
    return 0;
}