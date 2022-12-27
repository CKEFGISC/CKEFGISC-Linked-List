//
//  LinkedList.cpp
//  CKEFGISC-Linked-List
//
//  Copyright(c) 2022-present, AaronWu-train, VerstandTsai & CKEFGISC contributors.
//  This code is licensed under MIT license (see LICENSE.txt for details)
//

#include <iostream>

namespace AaW {  // use a namespace under your name
    template<typename T> // template 宣告
    class LinkedList {
    public:
        class node {
        public:
            T val;    // T = 萬用型別
            node* next;
            node* prev; // 雙向 linked list
            // constructor & deconstructor
            node(T _val) : val(_val) { }
            ~node() = default; // 用內建deconstructor就好
        }; // struct node;

        // 函數實作區
        LinkedList() {
            // 創立startNode和endNode
            this->startNode = new node(0);
            this->endNode = new node(0);

            // 連接startNode和endNode
            startNode->next = endNode;
            endNode->prev = startNode;

            // 初始化大小
            this->listSize = 0;
            return;
        } // LinkedList()

        ~LinkedList() {
            // 刪除startNode和中間所有實節點
            auto cur = startNode;
            while (cur != endNode) {
                auto toDelete = cur;
                cur = cur->next;
                delete toDelete;
            }

            // 刪除endNode
            delete endNode;
            return;
        } // ~LinkedList()

        int size() {
            return this->listSize;
        }

        bool empty() {
            return (this->listSize == 0);
        }

        node* begin() {  // 回傳第一個"實"節點，若 list 為空則回傳 endNode
            return this->startNode->next;  // 為空時startNode->next就是endNode
        } // begin()

        node* end() {  // 回傳最後一個節點，也就是 endNode
            return this->endNode;
        } // end()

        node* rbegin() {   // 回傳反向第一個"實"節點，
                                                   // 若 list 為空則回傳 startNode
            return this->endNode->prev;  // 為空時endNode->prev就是startNode
        } // rbegin()

        node* rend() {
            return this->startNode;
        } // rend()

        void insert(T val, node* pos) {   //  在 pos 前方插入一項
            // 節點原本長相： beforeNode => pos
            // 插入後新長相： beforeNode => newNode => pos

            // 先取得beforeNode
            // 如果pos為startNode時丟出錯誤 (不該再)
            if (pos == this->startNode) {
                throw "ERROR: trying to insert at startNode (a virt. node before .begin()).";
            }
            node* beforeNode = pos->prev;

            // 建立新節點
            node* newNode = new node(val);

            // 將新節點和pos連結
            pos->prev = newNode;
            newNode->next = pos;

            // 將新節點和beforeNode連結
            newNode->prev = beforeNode;
            beforeNode->next = newNode;

            // 更改LinkedList大小
            this->listSize += 1;

            return;
        } // insert()

        void erase(node* pos) {  //  傳入指標，刪除該位置
            // 如果 pos 為 startNode 或是 endNode時報錯
            if (pos == startNode || pos == endNode) {
                throw "ERROR: erasing a virt. node.";
            }

            // 取得pos前後的節點
            node* beforeNode = pos->prev;
            node* afterNode = pos->next;

            // 連結 beforeNode 和 afterNode
            beforeNode->next = afterNode;
            afterNode->prev = beforeNode;

            // 刪除 pos
            delete pos;

            // 更改LinkedList大小
            this->listSize -= 1;

        } // erase()

        node* find(T val) {  //  尋找第一個 val 出現的位置並且回傳指標
            // cur 為迭代整個linked list要使用的指標
            auto cur = this->begin();

            // 當cur的值和我們要找得不一樣時，將cur指向下一個位置
            while (cur->val != val && cur != endNode) {
                cur = cur->next;
            }

            // 如果最後 cur 是 endNode，代表沒找到
            if (cur == endNode) {
                throw val; // 表明「哪個沒找到」
            }

            // 回傳找到的結果
            return cur;
        } // find()

        void print() {  // 輸出整個LinkedList
            // cur 為迭代整個linked list要使用的指標
            auto cur = this->begin();

            // 迭代整個linked list
            while (cur != this->end()) {
                std::cout << cur->val << " ";
                cur = cur->next;
            }
            std::cout << std::endl;

            return;
        } // print()
    private: // 內部的零件，用 private 防止存取
        // member variables
        int listSize = 0;
        node* startNode;    // 頭的虛節點
        node* endNode;      // 尾的虛節點
    }; // class LinkedList
} // namespace Verstand (在結尾標記這個大括號是誰是個好習慣！)

