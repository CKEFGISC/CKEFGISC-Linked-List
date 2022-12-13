//
//  LinkedList.h
//  CKEFGISC-Linked-List
//
//  Copyright(c) 2022-present, AaronWu-train, VerstandTsai & CKEFGISC contributors.
//  This code is licensed under MIT license (see LICENSE.txt for details)
//

#include <iostream>

namespace AaW {  // use a namespace under your name
    // 宣告區
    class LinkedList {
    public: // 方法作為「介面」，當然要公開存取
        class node {
        public:
            int val;    // 我們目前只支持int存在node當中，之後多形時會教怎麼做萬用版的 linked list
            node* next;
            node* prev; // 雙向 linked list
            // constructor & deconstructor
            node(int _val) : val(_val) { }
            ~node() = default; // 用內建deconstructor就好
        }; // struct node;

        // constructor & deconstructor
        LinkedList();       // 建立新的 linked list，並且初始化兩個虛節點
        ~LinkedList();      // 刪除每一個建立的節點

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
    private: // 內部的零件，用 private 防止存取
        // member variables
        int listSize = 0;
        node* startNode;    // 頭的虛節點
        node* endNode;      // 尾的虛節點
    }; // struct LinkedList 
    
} // namespace AaW
