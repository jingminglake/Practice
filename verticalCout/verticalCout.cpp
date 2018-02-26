#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  string input = "abcdefghijklm";
  map<int, vector<char> > m;
  int remain = (int)input.size() % 3;
  int row = (int)(input.size() - 1) / 3;
  int i = 0;
  int rowSizeElementNum = (row + 1) * remain;
  for (i; i < rowSizeElementNum; i++) {
    m[i % (row + 1)].push_back(input[i]);
  }
  
  for (i; i < input.size(); i++) {
    if (remain != 0)
      m[(i - rowSizeElementNum) % row].push_back(input[i]); // i - rowSizeElementNum means start from 0 again
    else
      m[i % (row + 1)].push_back(input[i]);
  }
  
  for (auto& p : m) {
    for (char c : p.second) {
      cout << c << " ";
    }
    cout << endl;
  }
  return 0;
}
