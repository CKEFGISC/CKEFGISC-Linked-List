cd build
g++ -g -Wall -std=c++17 -c ../src/LinkedList.cpp
g++ -g -Wall -std=c++17 -c ../src/main.cpp
g++ -g -Wall -std=c++17 -o run.exe ./main.o ./LinkedList.o