//
//  LinkedList.cpp
//  CKEFGISC-Linked-List
//
//  Copyright(c) 2022-present, AaronWu-train, VerstandTsai & CKEFGISC contributors.
//  This code is licensed under MIT license (see LICENSE.txt for details)
//

#include <iostream>
// 在專案中不要using namespace std，會容易混淆namespace

namespace Verstand {  // use a namespace under your name
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
    }; // struct LinkedList  (在結尾標記這個大括號是誰是個好習慣！)

    // 函數實作區
    // (我們會發現把實作和宣告放在一起好像有點亂，因此之後教標頭檔時，
    //  會告訴大家要如何把實作和宣告放進不同檔案當中)


    LinkedList::LinkedList() {
        // 創立startNode和endNode
        this->startNode = new LinkedList::node(0);
        this->endNode = new LinkedList::node(0);

        // 連接startNode和endNode
        startNode->next = endNode;
        endNode->prev = startNode;

        // 初始化大小
        this->listSize = 0;
        return;
    } // LinkedList::LinkedList()

    LinkedList::~LinkedList() {
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
    } // LinkedList::~LinkedList()

    int LinkedList::size() {
        return this->listSize;
    }

    bool LinkedList::empty() {
        return (this->listSize == 0);
    }

    LinkedList::node* LinkedList::begin() {  // 回傳第一個"實"節點，若 list 為空則回傳 endNode
        return this->startNode->next;  // 為空時startNode->next就是endNode
    } // LinkedList::begin()

    LinkedList::node* LinkedList::end() {  // 回傳最後一個節點，也就是 endNode
        return this->endNode;
    } // LinkedList::end()

    LinkedList::node* LinkedList::rbegin() {   // 回傳反向第一個"實"節點，
                                               // 若 list 為空則回傳 startNode
        return this->endNode->prev;  // 為空時endNode->prev就是startNode
    } // LinkedList::rbegin()

    LinkedList::node* LinkedList::rend() {
        return this->startNode;
    } // LinkedList::rend()

    void LinkedList::insert(int val, LinkedList::node* pos) {   //  在 pos 前方插入一項
        // 節點原本長相： beforeNode => pos
        // 插入後新長相： beforeNode => newNode => pos

        // 先取得beforeNode
        // 如果pos為startNode時丟出錯誤 (不該再)
        if (pos == this->startNode) {
            throw "ERROR: trying to insert at startNode (a virt. node before .begin()).";
        }
        LinkedList::node* beforeNode = pos->prev;

        // 建立新節點
        LinkedList::node* newNode = new LinkedList::node(val);

        // 將新節點和pos連結
        pos->prev = newNode;
        newNode->next = pos;

        // 將新節點和beforeNode連結
        newNode->prev = beforeNode;
        beforeNode->next = newNode;

        // 更改LinkedList大小
        this->listSize += 1;

        return;
    } // LinkedList::insert()

    void LinkedList::erase(LinkedList::node* pos) {  //  傳入指標，刪除該位置
        // 如果 pos 為 startNode 或是 endNode時報錯
        if (pos == startNode || pos == endNode) {
            throw "ERROR: erasing a virt. node.";
        }

        // 取得pos前後的節點
        LinkedList::node* beforeNode = pos->prev;
        LinkedList::node* afterNode = pos->next;

        // 連結 beforeNode 和 afterNode
        beforeNode->next = afterNode;
        afterNode->prev = beforeNode;

        // 刪除 pos
        delete pos;

        // 更改LinkedList大小
        this->listSize -= 1;

    } // LinkedList::erase()

    LinkedList::node* LinkedList::find(int val) {  //  尋找第一個 val 出現的位置並且回傳指標
        // cur 為迭代整個linked list要使用的指標
        auto cur = this->begin();

        // 當cur的值和我們要找得不一樣時，將cur指向下一個位置
        while (cur->val != val && cur != endNode) {
            cur = cur->next;
        }

        // 回傳找到的結果
        return cur;
    } // LinkedList::find()

    void LinkedList::print() {  // 輸出整個LinkedList
        // cur 為迭代整個linked list要使用的指標
        auto cur = this->begin();

        // 迭代整個linked list
        while (cur != this->end()) {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;

        return;
    } // LinkedList::print()

} // namespace Verstand (在結尾標記這個大括號是誰是個好習慣！)

/////////////////////////////////////////////////////////////////////
// 測試執行區域

int main() {
    Verstand::LinkedList ls;
    std::cout << ls.size() << std::endl;

    ls.insert(10, ls.begin());
    ls.print();
    ls.insert(20, ls.begin());
    ls.insert(50, ls.end());
    ls.print();
    auto ret = ls.find(10);
    ls.insert(12, ret);
    ls.print();
    ls.erase(ret);
    ls.print();
    std::cout << ls.size() << std::endl;

}
