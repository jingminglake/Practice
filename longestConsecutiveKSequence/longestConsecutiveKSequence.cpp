#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutiveSequence(vector<int>& nums) {
    int res = 0;
    if (nums.size() == 0)
      return res;
    vector<int> temp(nums.rbegin(), nums.rend());
    res = max (longestConsecutiveSequenceHelper(nums), longestConsecutiveSequenceHelper(temp));
    return res;
  }
  int longestConsecutiveSequenceHelper(vector<int>& nums) {
    int res = 0;
    int curMin = nums[0];
    int d = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < curMin)
	curMin = nums[i];
      d = max (d, nums[i] - curMin);
    }
    vector<vector<int> > dp(nums.size(), vector<int>(d + 1, 1));
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
	int diff = nums[i] - nums[j];
	if (diff >= 0) {
	  dp[i][diff] = max (dp[i][diff], dp[j][diff] + 1);
	  res = max (res, dp[i][diff]);
	}
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 2, 3, 1, 1, 4, 5, 6, 1, 1, 1, 1, 7, 8, 7,6,5,4,3,2,1,0,-1,-2};
  //vector<int> nums = {1, 1, 1, 1, 1};
  cout << s.longestConsecutiveSequence(nums);
  cout << endl;
  return 0;
}
