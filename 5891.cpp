
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int Score[6][5] = {};
    float avg;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 5; j++)
            cin >> Score[i][j];

    for(int j = 0; j < 5; j++) {
        float sum = 0;
        for(int i = 0; i < 6; i++){
            sum += Score[i][j];
        }
        avg= sum/6;
        cout << fixed << setprecision(1) << avg << " ";
    }

    int max = 0;
    for(int i = 0; i < 6; i++){
        float sum = 0;
        for(int j = 0; j < 5; j++){
            sum += Score[i][j];
        }
        avg= sum/5;
        if(avg > max){
            max = avg;
        }
    }
    cout << max;
}
