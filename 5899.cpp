#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int n;
    int arr[151] = {};
    bool first = false;
    cin >> n;
    
    while (n != 0) {
        for (int i = 0; i < n / 2; i++) {
            int ai, bi;
            cin >> ai >> bi;

            arr[ai] += bi;
        }

        cin >> n;
    }

    
    for (int i = 150; i >= 0; i--) {
        if (arr[i] != 0) {
            if (arr[i] > 0 && first == true)
                cout << "+";

            first = true;
            if (i == 0)
                cout << arr[i];
            else if (arr[i] == 1)
                cout << "x^" << i;
            else if (arr[i] == -1)
                cout << "-x^" << i;
            else {
                if (i != 1)
                    cout << arr[i] << "x^" << i;
                else
                    cout << arr[i] << "x";
            }
        }
    }
}