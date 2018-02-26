#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> res;
    if (S.length() == 0)
      return res;
    string path;
    dfs(res, 0, S, path);
    return res;
  }
  void dfs(vector<string>& res, int start, string& S, string path) {
    if (start >= S.length()) {
      if (path.length() > 0)
	res.push_back(path);
      //path = "";
      return;
    }
    int i = start;
    for ( i ; i < S.length(); i++) {
      if (S[i] >= '0' && S[i] <= '9') {
	path += S[i];
	continue;
      } else {
	break;
      }
    }
    if (i == S.length()) {
      if (path.length() > 0)
	res.push_back(path);
      cout << "path-->" << path << endl;
      return;
    }
    dfs (res, i + 1, S, path + S[i]);
    if (S[i] >= 'A' && S[i] <= 'Z') {
      path += (char)tolower(S[i]);
    } else if (S[i] >= 'a' && S[i] <= 'z') {
      path += (char)toupper(S[i]);
    }
    dfs (res, i + 1, S, path);
  }
};

int main() {
  Solution s;
  string S = "03fH";
  for (string& ss : s.letterCasePermutation(S)) {
    cout << ss << " ";
  }
  cout << endl;
  cout << s.letterCasePermutation(S).size() << endl;
  return 0;
}
