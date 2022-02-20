#ifndef READ_WRITE_FILE_H_
#define READ_WRITE_FILE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <list>

std::list<std::string> read_file(std::string filename);
void write_file(std::string filename, std::list<std::string>& file_contents);

#endif