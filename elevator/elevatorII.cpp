#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  Solution(vector<int>& w, vector<int>& f, int m, int n) : weight(w), floor(f), maxCap(m), numLimit(n) {
     
  }
  int caculateFloorStop() {
    int res = 0;
    while (oneTrip(res));
    return res;
  }
  bool oneTrip(int& res) {
    unordered_map<int, int> trip;
    int size = weight.size();
    if (size == 0)
      return false;
    int total = 0;
    for (int i = size - 1; i >= size - numLimit && i >= 0; i--) {
      int temp = weight[i];
      total += temp;
      weight.pop_back();
      trip[floor[i]]++;
      if (total > maxCap) {
	weight.push_back(temp);
	trip[floor[i]]--;
      }
    }
    unordered_map<int, int>::iterator it = trip.begin();
    while (it != trip.end()) {
      if (it->second > 0)
	res++;
      ++it;
    }
    res++;
    return true;
  }
  vector<int> weight;
  vector<int> floor;
  int maxCap;
  int numLimit;
};

int main() {
  //vector<int> weight = {70, 60, 50, 80, 100, 40, 70, 75};
  //vector<int> floor = {5, 4, 3, 3, 1, 1, 1, 2};
  vector<int> weight = {40, 40, 100, 80, 20};
  vector<int> floor = {3, 3, 2, 2, 3};
  int maxCap = 200;
  int numLimit = 3;
  reverse(weight.begin(), weight.end());
  reverse(floor.begin(), floor.end());
  Solution s(weight, floor, maxCap, numLimit);
  cout << "res: " << s.caculateFloorStop() << endl;
  return 0;
}
