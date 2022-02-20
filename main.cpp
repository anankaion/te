#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

#include "split_string.h"
#include "read_write_file.h"

void print_file(std::list<std::string>& file_contents){
    std::list<std::string>::iterator it;
    int line_count = 0;

    for (it = file_contents.begin(); it != file_contents.end(); it++) {
        std::cout << line_count << " " << *it << "\n";

        line_count++;
    }
}

void add(std::string& string, int& pos, std::list<std::string>& file_contents){
    std::list<std::string>::iterator it = file_contents.begin();

    for (int i = 0; i < pos; i++) {
        it++;
    }

    //delete quotation marks
    string.erase(string.begin());
    string.pop_back();

    file_contents.insert(it, string);
    pos++;
}

void rm(int& pos, std::list<std::string>& file_contents){
    std::list<std::string>::iterator it = file_contents.begin();

    for (int i = 0; i < pos; i++) {
        it++;
    }

    file_contents.erase(it);
    pos--;
}

void parse_instruction(std::string& instruction, int &pos, std::list<std::string>& file_contents){
    std::vector<std::string> parts;

    //if no space to split at -> commands without arguments
    if (instruction.find(" ") == std::string::npos) {
        if (instruction == "rm") {
            rm(pos, file_contents);
        } else if (instruction == "print") {
            print_file(file_contents);
        }
    } 
    // commands with arguments
    else {
        parts = split_string(instruction, ' ');

        if (parts.at(0) == "add") {
            add(parts[1], pos, file_contents);
        } else if (parts.at(0) == "set") {
            pos = stoi(parts.at(1));
        } else if (parts.at(0) == "load") {
            file_contents = read_file(parts.at(1));
        } else if (parts.at(0) == "write") {
            write_file(parts.at(1), file_contents);
        }
    }
}

int main(){
    std::string input;
    std::list<std::string> file_contents;
    int pos = 0;

    while (input != "quit") {
        std::cout << ">";
        std::getline(std::cin, input);

        parse_instruction(input, pos, file_contents);     
    }

    return 0;    
}