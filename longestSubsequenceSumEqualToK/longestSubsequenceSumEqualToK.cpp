#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestSubsequenceSumEqualToK(vector<int>& nums, int k) {
      if (nums.size() == 0)
	return 0;
      int res = 0;
      vector<int> path;
      dfs(nums, path, 0, k, res);
      return res;
  }
  void dfs(vector<int>& nums, vector<int>& path, int start, int target, int& res) {
    if (target == 0) {
      res = max (res, (int)path.size());
      return;
    }
    for (int i = start; i < nums.size(); i++) {
      if (nums[i] <= target) {
	path.push_back(nums[i]);
	dfs(nums, path, i + 1, target - nums[i], res);
	path.pop_back();
      }
    }
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 2, 2, 3, 1, 4, 5};
  cout << s.longestSubsequenceSumEqualToK(nums, 3);
  cout << endl;
  return 0;
}
