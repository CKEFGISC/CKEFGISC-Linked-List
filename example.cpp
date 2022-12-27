#include <iostream>
#include "LinkedList.hpp"

int main() {
    AaW::LinkedList<double> ls;
    // 填入 1~10，故意少一個
    for (double i=0.1; i<=1.0; i+=0.1) {
        if (i != 0.4) ls.insert(i, ls.end());
    }
    ls.print();
    // 找出少哪個
    try {
        for (double i=0.1; i<=1.0; i+=0.1) {
            ls.find(i);
        }
    } catch (double num) {
        std::cout << num << '\n';
    }
    return 0;
}
