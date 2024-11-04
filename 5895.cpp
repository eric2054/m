/*每位同學成績之範例如下表，請計算每一科目的平均分數並輸出，且輸出個人平均最低分

範例：
姓名 國文 英文 數學 自然 社會
李小明 65 85 78 75 69
王小華 66 55 52 92 47
劉小花 75 99 63 73 86
陳小學 77 88 99 91 100

答案應為：
70.8 81.8 73.0 82.8 75.5
62


系統輸入：
20個int型態的數值（4*5的矩陣）

結果輸出：
5個float型態的數值（小數點後一位）
1個int型態的數值*/

#include <iostream>
#include <iomanip> 
using namespace std;

int main(int argc, char* argv[]) {
    int Score[4][5] = {};
    float avg;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            cin >> Score[i][j];

    for(int j = 0; j < 5; j++) {
        float sum = 0;
        for(int i = 0; i < 4; i++){
            sum += Score[i][j];
        }
        avg= sum/4;
        cout << fixed << setprecision(1) << avg << " ";
    }
    int min = 100;
    for(int i = 0; i < 4; i++){
        float sum = 0;
        for(int j = 0; j < 5; j++){
            sum += Score[i][j];
        }
        avg= sum/5;
        if(avg < min){
            min = avg;
        }
    }
    cout << min;
}
    

