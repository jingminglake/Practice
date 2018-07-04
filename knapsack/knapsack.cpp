// 01 knapsack problem : "01" way to choose from array of numbers, how many ways equal/less/above target?

#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int sum = 0;
    for (int n : nums)
        sum += n;
    int target = 55;
    vector<vector<int> > dp(nums.size() + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= nums.size(); i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j >= nums[i - 1])
                dp[i][j] += dp[i - 1][j - nums[i - 1]];
        }
    }
    cout << "# of equal to target: " << dp[nums.size()][target] << endl;
    int less_than_target_num = 0;
    for (int i = 0; i <= target - 1; i++) {
        less_than_target_num += dp[nums.size()][i];
    }
    cout << "# of less than target: "<< less_than_target_num << endl;

    int above_than_target_num = 0;
    for (int i = target + 1; i <= sum; i++) {
        above_than_target_num += dp[nums.size()][i];
    }
    cout << "# of above than target: "<< above_than_target_num << endl;
    return 0;
}
