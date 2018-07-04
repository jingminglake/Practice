/*
  A card game that gives you two non-negative integers: totalProfit, totalCost, and n cards'information. The ith card has a profit value a[i] and a cost value b[i].It is possible to select any number of cards from these cards, form a scheme. Now we want to know how many schemes are satisfied that all selected cards' profit values are greater than totalProfit and the costs are less than totalCost.

  Since this number may be large, you only need to return the solution number mod 1e9 + 7.
  0 ≤ n ≤ 100
  0 ≤ a[i] ≤ 100
  0 ≤ b[i] ≤ 100
  0 ≤ totalProfit ≤ 100
  0 ≤ totalCost ≤ 100
*/

#include <iostream>
#include <vector>
using namespace std;

int numOfPlan(int n, int totalProfit, int totalCost, vector<int> &a, vector<int> &b) {
    const int modNum = 1e9 + 7;
    vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(totalCost + 1, vector<int>(totalProfit + 2, 0)) );
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= totalCost; j++) {
            for (int k = 0; k <= totalProfit + 1; k++) {
                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k]) % modNum;
                int minP = min (totalProfit + 1, k + a[i - 1]);
                if (j >= b[i - 1]) {
                    dp[i][j][minP] = (dp[i][j][minP] + dp[i - 1][j - b[i - 1]][k]) % modNum;
                }
            }
        }
    }
    long res = 0;
    for (int j = 0; j <= totalCost - 1; j++) {
        res = (res + dp[n][j][totalProfit + 1]) % modNum;
    }
    return res;
}

int main() {
    int n = 2, totalProfit = 3, totalCost = 5;
    vector<int> a = {2, 3}, b = {2, 2};
    cout << numOfPlan(n, totalProfit, totalCost, a, b) << endl;
    return 0;
}
