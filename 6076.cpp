#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> getPasswordTable(int number)
{
    srand(number);
    vector<vector<int>> PasswordTable(10, vector<int>(10));
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            PasswordTable[i][j] = rand() % 100;
        }
    }

    return PasswordTable;
}

vector<int> getCipertext(int HTCode, vector<vector<int>> PasswordTable)
{
    vector<int> ans;
    while (HTCode > 0)
    {
        int index = HTCode % 100;
        ans.push_back(PasswordTable[index % 10][index / 10]);
        HTCode /= 100;
    }

    return ans;
}

void HanoiTowerCode(int n, int &k, int &total)
{
    if (n == 1)
    {
        k++;
        total += k;
        return;
    }
    HanoiTowerCode(n - 1, k, total);
    k++;
    total += k;
    HanoiTowerCode(n - 1, k, total);
}

int main()
{
    int Plaintext, k, total = 0;
    cin >> Plaintext;
    
    Plaintext += 2;
    k = 3;
    
    HanoiTowerCode(Plaintext, k, total);

    vector<vector<int>> PasswordTable = getPasswordTable(total);

    vector<int> ans = getCipertext(total, PasswordTable);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
    }
}
