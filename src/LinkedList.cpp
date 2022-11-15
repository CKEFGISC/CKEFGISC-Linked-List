// 
//  LinkedList.cpp
//  CKEFGISC-Linked-List
//  
//  Copyright(c) 2022-present, AaronWu-train & CKEFGISC contributors.  
//  This code is licensed under MIT license (see LICENSE.txt for details)
// 

#include <iostream>
// 在專案中不要using namespace std，會容易混淆namespace

namespace AaW {  // use a namespace under your name
    
    // 宣告區
    struct LinkedList {
        struct node {
            int val;    // 我們目前只支持int存在node當中，之後多形時會教怎麼做萬用版的 linked list
            node* next;
            node* prev; // 雙向 linked list 

            // constructor & deconstructor
            node(int val);
            ~node();
        }; // struct node;
        
        // constructor & deconstructor
        LinkedList();       // 建立新的 linked list，並且初始化兩個
        ~LinkedList();

        // member variables
        int listSize = 0;
        node* startNode;    // 頭的虛節點
        node* endNode;      // 尾的虛節點

        // methods
        node* begin();      // 回傳第一個"實"節點，若 list 為空則回傳 endNode
        node* end();        // 回傳最後一個節點，也就是 endNode
        node* rbegin();     // 回傳反向第一個"實"節點，若 list 為空則回傳 startNode
        node* rend();       // 回傳反向最後一個節點，也就是startNode
        int size();         // 回傳 list 大小
        bool empty();       // 回傳 list 是否為空
        void insert(int val, node* pos);  //  在 pos 前方插入一項
        void erase(node* pos);            //  傳入指標，刪除該位置
        node* find(int val);              //  尋找第一個 val 出現的位置並且回傳指標
        void print();        // 輸出整個LinkedList (之後會教要怎麼讓自定義物件可以cout)

    }; // struct LinkedList  (在結尾標記這個大括號是誰是個好習慣！)

    // 函數實作區 
    // (我們會發現把實作和宣告放在一起好像有點亂，因此之後教標頭檔時，
    //  會告訴大家要如何把實作和宣告放進不同檔案當中)

    int _________::size() {
        return this->_________;
    }

    bool _________::empty() {
        return (this->_________ == 0);
    }

    _________::node* LinkedList::begin() {  // 回傳第一個"實"節點，若 list 為空則回傳 endNode
        return this->_________->_____;  // 為空時startNode->next就是endNode
    } // LinkedList::begin()

    LinkedList::node* LinkedList::end() {  // 回傳最後一個節點，也就是 endNode
        return this->_________;
    } // LinkedList::end()

    LinkedList::node* LinkedList::rbegin() {   // 回傳反向第一個"實"節點，
                                               // 若 list 為空則回傳 startNode
        return this->_______->____;  // 為空時endNode->prev就是startNode
    } // LinkedList::rbegin()

    LinkedList::node* LinkedList::rend() {
        return this->_________;
    } // LinkedList::rend()

    void LinkedList::insert(int val, LinkedList::node* pos) {   //  在 pos 前方插入一項
        // 節點原本長相： beforeNode => pos
        // 插入後新長相： beforeNode => newNode => pos
        
        // 先取得beforeNode
        // 如果pos為startNode時丟出錯誤 (不該再)
        if (___ == this->_________) {
            throw "ERROR: trying to insert at startNode (a virt. node before .begin()).";
        }
        LinkedList::node* beforeNode = pos->____;

        // 建立新節點
        LinkedList::node* newNode = n__ __________::____(___);

        // 將新節點和pos連結
        pos->prev = _________;
        newNode->next = _________;

        // 將新節點和beforeNode連結
        newNode->prev = _________;
        beforeNode->next = _________;

        // 更改LinkedList大小
        this->listSize _______;

        return;
    } // LinkedList::insert()

    void LinkedList::erase(LinkedList::node* pos) {  //  傳入指標，刪除該位置
        // 如果 pos 為 startNode 或是 endNode時報錯
        if (pos == _________ || pos == _________) {
            throw "ERROR: erasing a virt. node.";
        }

        // 取得pos前後的節點
        LinkedList::node* beforeNode = _________;
        LinkedList::node* afterNode = _________;

        // 連結 beforeNode 和 afterNode
        beforeNode->next = _________;
        afterNode->prev = _________;

        // 刪除 pos
        d_____ ___;

        // 更改LinkedList大小
        this->listSize ______;

    } // LinkedList::erase()

    LinkedList::node* LinkedList::find(int val) {  //  尋找第一個 val 出現的位置並且回傳指標
        // cur 為迭代整個linked list要使用的指標
        auto cur = this->begin();

        // 當cur的值和我們要找得不一樣時，將cur指向下一個位置
        while (cur->___ != ___ /*判斷值*/ && cur != _________ /*判斷是否到結尾*/ ) { 
            cur = cur->____;
        }

        // 回傳找到的結果
        return ___;
    } // LinkedList::find()

    void LinkedList::print() {  // 輸出整個LinkedList
        // cur 為迭代整個linked list要使用的指標
        auto cur = this->begin();

        // 迭代整個linked list
        while (cur != this->end()) {
            std::cout << cur->val << " ";
        }
        std::cout << std::endl;

        return;
    } // LinkedList::print()

} // namespace AaW (在結尾標記這個大括號是誰是個好習慣！)
