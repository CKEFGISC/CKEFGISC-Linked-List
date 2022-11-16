# CKEFGISC-Linked-List
## 2022/11/16 專案小社課填空branch
練習把 [LinkedList.cpp](src/LinkedList.cpp) 裡面的空格(________)都填滿吧！ <br>
回到main branch: https://github.com/CKEFGISC/CKEFGISC-Linked-List/tree/main <br>
前往答案branch: https://github.com/CKEFGISC/CKEFGISC-Linked-List/tree/2022-11-16-answer <br>

## 編譯方式
本週只會有一個檔案而已，編譯方式如下：<br>
首先，先將資料夾切換到專案家路徑當中。<br>
``` 
cd PATH_TO_FOLDER
```
此時若執行`ls`指令，應該可以看到有`src`一個資料夾，以及`.gitignore`、`README.md`等檔案
再來，創立build資料夾：<br>
```
mkdir build
```
並且執行g++指令：<br>
```
g++ -std=c++14 -o build/LinkedList.out src/LinkedList.cpp
```
這行指令的意思是我將src/LinkedList.cpp以c++14編譯並且輸出成執行檔build/LinkedList.out <br>
之後便可以用以下指令來執行<br>
```
./build/LinkedList.out
```
