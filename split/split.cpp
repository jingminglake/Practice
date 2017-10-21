// clang++ split.cpp -std=c++11
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(const string &str, char delim) {
  istringstream iss(str);
  vector<string> tokens;
  string token;
  while (getline(iss, token, delim)) {
    tokens.push_back(move(token));
  }
  return tokens;
}

int main() {
  string str = "1,2,3,4,5,6,7,8,9";
  vector<string> vec = split(str, ',');
  for (string &s : vec)
    cout << s << " ";
  cout << endl;
  return 0;
}
