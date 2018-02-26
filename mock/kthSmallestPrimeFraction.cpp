#include <iostream>
#include <vector>
using namespace std;

class Compare {
public:
  bool operator()(const vector<int>& p1, const vector<int>& p2) const {
    return (p1[0] * 1.0) / p1[1] < (p2[0] * 1.0) / p2[1];
  }
};

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    vector<int> res;
    vector<vector<int> > pairs;
    for (int i = 0; i < A.size(); i++) {
      for (int j = i + 1; j < A.size(); j++) {
	vector<int> temp = {A[i], A[j]};
	pairs.push_back(temp);
      }
    }
    sort(pairs.begin(), pairs.end(), Compare());
    return pairs[K - 1];
  }
  
};

int main() {
  Solution s;
  vector<int> A = {1,2,3,5};
  for (int& ss : s.kthSmallestPrimeFraction(A, 3)) {
    cout << ss << " ";
  }
  cout << endl;
  return 0;
}
