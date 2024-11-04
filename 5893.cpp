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
