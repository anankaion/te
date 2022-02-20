output: main.o split_string.o read_write_file.o
	g++ main.o split_string.o read_write_file.o -o output

main.o: main.cpp
	g++ -c -g main.cpp

split_string.o: split_string.cpp split_string.h
	g++ -c -g split_string.cpp

read_write_file.o: read_write_file.cpp read_write_file.h
	g++ -c -g read_write_file.cpp

clean:
	rm *.o output
