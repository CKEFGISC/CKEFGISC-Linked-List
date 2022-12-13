#include <iostream>
#include "LinkedList.h"

int main() {
    Verstand::LinkedList ls;
    // 填入 1~10，故意少一個
    for (int i=1; i<=10; i++) {
        if (i != 4) ls.insert(i, ls.end());
    }
    ls.print();
    // 找出少哪個
    try {
        for (int i=1; i<=10; i++) {
            ls.find(i);
        }
    } catch (int num) {
        std::cout << num << '\n';
    }
    return 0;
}
