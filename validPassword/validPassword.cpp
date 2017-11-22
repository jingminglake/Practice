#include <iostream>
using namespace std;

class Solution {
public:
  int solution(string s) {
    int size = s.length();
    if ( size == 0) {
      return -1;
    }  
    int upper = 0, maxLen = -1;
    bool fromDigit = false;
    int lo = 0, hi = 0;   
    while (hi < size) {
      if (s[hi] >= '0' && s[hi] <= '9') {
	lo = hi;
	upper = 0;
	fromDigit = true;
      } else {
	if (s[hi] >= 'A' && s[hi] <= 'Z') {
	  upper++;
	}
	if (upper >= 1) {
	  maxLen = max(maxLen, fromDigit ? (hi - lo) : (hi - lo + 1));
	}
      }
      hi++;
    }
    return maxLen;
  }
};

int main() {
  Solution s;
  cout << s.solution("asdxDasad1") << endl;
  cout << s.solution("1asssdxDasad1") << endl;
  return 0;
}
