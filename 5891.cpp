/* 每位同學成績之範例如下表，請計算每一科目的平均分數並輸出，且輸出個人平均最高分

範例：
姓名 國文 英文 數學 自然 社會
65 85 78 75 69
66 55 52 92 47
75 99 63 73 86
77 88 99 91 100
85 87 90 94 63
91 62 64 78 86

答案應為：
76.5 79.3 74.3 83.3 75.16
91

系統輸入：
30個int型態的數值（6*5的矩陣）

結果輸出：
5個float型態的數值（小數點後一位）
1個int型態的數值*/
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
