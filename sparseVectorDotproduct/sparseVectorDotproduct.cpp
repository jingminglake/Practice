#include <iostream>
#include <vector>
using namespace std;

// element --> (index, element)
// A[] {0, 0, 0, 0, 5, ..., 100, 0, 0, 0}   --> {(4, 5), (1000, 100)}
// B[] {1, 0, 0, 0, 4, ..., 100, 101, 0, 0} --> {(0, 1), (4, 4), (1000, 100), (1001, 100)}


int main() {
  vector<pair<int, int> > vecA = {make_pair(4, 5), make_pair(1000, 100)};
  vector<pair<int, int> > vecB = {make_pair(0, 1), make_pair(4, 4), make_pair(1000, 100), make_pair(1001, 100)};
  int pA = 0, pB = 0;
  int res = 0;
  while (pA < vecA.size() && pB < vecB.size()) {
    if (vecA[pA].first < vecB[pB].first)
      pA++;
    else if (vecA[pA].first == vecB[pB].first) {
      res += vecA[pA].second * vecB[pB].second;
      pA++;
      pB++;
    }
    else
      pB++;
  }
  cout << res << endl;
  return 0;
}

