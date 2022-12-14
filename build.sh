cd build
g++ -g -Wall -std=c++17 -I../include -c ../src/LinkedList.cpp
g++ -g -Wall -std=c++17 -I../include -c ../src/main.cpp
g++ -g -Wall -std=c++17 -o run.exe ./main.o ./LinkedList.o