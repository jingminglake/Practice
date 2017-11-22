#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
  Solution(vector<int>& w, vector<int>& f, int m) : weight(w), floor(f), maxCap(m) {
    int preSum = 0;
    for (int i = 0; i < w.size(); i++) {
      preSum += w[i];
      preSumWeight.push_back(preSum);
    }
    
    infoMap = vector<vector<int> >(w.size() + 1, vector<int>(w.size() + 1, 0));
    caculateInfo();
    cout << "The least stop numbers: " << calculateLeastStop(0, w.size() - 1) << endl;
  }
  int calculateLeastStop(int start, int end) {
    vector<vector<pair<int, int> >> ans;
    vector<pair<int, int> > path;
    backtrack(path, ans, 0);
    int leastStop = INT_MAX;
    for (vector<pair<int, int> >& vec : ans) {
      int totalStop = 0;
      for (pair<int, int>& p : vec) {
	//cout << p.first << " " << p.second << endl;
	totalStop += infoMap[p.first][p.second];
      }
      leastStop = min(leastStop, totalStop);
    }
    return leastStop;
  }
  void backtrack(vector<pair<int, int> >& path, vector<vector<pair<int, int> >>& ans, int start) {
    if (start == weight.size()) {
      ans.push_back(path);
      return;
    }
    for (int i = start; i < weight.size(); i++) {
      if (canInOneTrip(start, i)) {
	path.push_back(make_pair(start, i));
	backtrack(path, ans, i + 1);
	path.pop_back();
      }
    }
  }
  vector<int> weight;
  vector<int> floor;
  int maxCap;
  vector<vector<int> > infoMap;
  vector<int> preSumWeight;
private:
  void caculateInfo() {
    int size = weight.size();
    for (int i = 0; i < size; i++) {
      for (int j = i; j < size; j++) {
	infoMap[i][j] = caculateFloorStop(i, j);
      }
    }
  }
  int caculateFloorStop(int start, int end) {
    if (start > end)
      return 0;
    unordered_set<int> s;
    for (int i = start; i <= end; i++) {
      s.insert(floor[i]);
    }
    //cout << start << "-->" << end << " " << s.size() + 1 << endl;
    return s.size() + 1;
  }
  bool canInOneTrip(int i, int j) {
    int sum = preSumWeight[j] - preSumWeight[i] + weight[i];
    return (sum <= maxCap) ? true : false;
  }
};

int main() {
  //vector<int> weight = {70, 60, 50, 80, 100, 40, 70, 75};
  //vector<int> floor = {5, 4, 3, 3, 1, 1, 1, 2};
  vector<int> weight = {1, 1, 1, 1, 1, 1, 1, 2, 3};
  vector<int> floor = {1, 1, 1, 1, 1, 1, 1, 2, 3};
  int maxCap = 6;
  Solution(weight, floor, maxCap);
  return 0;
}
