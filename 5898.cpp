/*一個簡單的「堆疊管理器」處理著兩個堆疊A和B，堆疊的資料型態為int，容量大小為100。對堆疊管理器輸入指令，可對A或B進行操作。請編寫一個程式，該程式模擬堆疊管理器的工作情況。

系統輸入：
第一行包含一個整數N，N表示接下來會有多少個指令。第二行開始，每行代表一個指令，每個指令第一個數字表示指令ID，後面接著該指令的參數，每個參數以空格分隔。以下為堆疊管理器的指令：
●[1 X Y]
對堆疊進行Push。參數X為要進行Push的堆疊代號，X=1時表示堆疊A，X=2時表示堆疊B。Y表示Push的數值（1 ≤ Y ≤ 99）。
●[2 X]
對堆疊進行Pop。參數X為要進行Pop的堆疊代號，X=1時表示堆疊A，X=2時表示堆疊B。
●[3 X]
列印出堆疊的名稱，接著從索引0開始列印堆疊全部的元素內容。每個列印請以空格分隔，結束時換下一行。堆疊A的名稱請列印'A'，堆疊B的名稱請列印'B'。參數X為要進行列印的堆疊代號，X=1時表示堆疊A，X=2時表示堆疊B。

結果輸出：
根據指令來列印，請參考輸出範例。


輸入範例：
12
1 1 5
1 2 10
1 1 20
1 1 40
3 1
3 2
2 1
2 2
1 1 80
1 2 160
3 1
3 2

輸出範例：
A 5 20 40
B 10
A 5 20 80
B 160*/

#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char* argv[]) {
    int N;
    cin >> N;
    
    stack<int> stackA;
    stack<int> stackB;
    
    for (int i = 0; i < N; ++i) {
        int command;
        cin >> command;
        
        if (command == 1) { 
            int stackId, value;
            cin >> stackId >> value;
            if (stackId == 1) {
                stackA.push(value);
            } else if (stackId == 2) {
                stackB.push(value);
            }
        } else if (command == 2) { 
            int stackId;
            cin >> stackId;
            if (stackId == 1 && !stackA.empty()) {
                stackA.pop();
            } else if (stackId == 2 && !stackB.empty()) {
                stackB.pop();
            }
        } else if (command == 3) { 
            int stackId;
            cin >> stackId;
            if (stackId == 1) {
                cout << "A";
                stack<int> temp;
                while (!stackA.empty()) {
                    temp.push(stackA.top());
                    stackA.pop();
                }
                while (!temp.empty()) {
                    cout << " " << temp.top();
                    stackA.push(temp.top());
                    temp.pop();
                }
                cout << endl;
            } else if (stackId == 2) {
                cout << "B";
                stack<int> temp;
                while (!stackB.empty()) {
                    temp.push(stackB.top());
                    stackB.pop();
                }
                while (!temp.empty()) {
                    cout << " " << temp.top();
                    stackB.push(temp.top());
                    temp.pop();
                }
                cout << endl;
            }
        }
    }
}