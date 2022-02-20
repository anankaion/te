#include <iostream>
#include <fstream>
#include <string>
#include <list>

std::list<std::string> read_file(std::string filename){
    std::ifstream file(filename);
    std::list<std::string> file_contents;
    std::string line;

    while (getline(file, line)) {
        file_contents.push_back(line);
    }

    file.close();

    return file_contents;
}

void write_file(std::string filename, std::list<std::string>& file_contents){
    std::ofstream file(filename);
    std::list<std::string>::iterator it;

    for (it = file_contents.begin(); it != file_contents.end(); it++) {
        file << *it << "\n";
    }

    file.close();
}