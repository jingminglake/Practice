#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
using namespace std;


int main() {
  string fileName = "1.txt";
  fstream fin(fileName);
  unordered_set<string> s;
  string line;
  while (getline(fin, line)) {
    istringstream iss(line);
    string url = line.substr(line.find_first_of('"'), line.find_last_of('"') - line.find_first_of('"')  + 1);
    //cout << url << endl;
    string cur;
    while (getline(iss, cur, ' ')) {
      if (cur == "200") {
	//cout << url << endl;
	string gifName = url.substr(url.find_first_of(' ') + 1, url.find_last_of(' ') - url.find_first_of(' ') - 1);
	//cout << gifName << endl;
	//cout << gifName.substr(gifName.find_last_of('.') + 1) << endl;
	if (gifName.substr(gifName.find_last_of('.') + 1) == "gif")
	  s.insert( gifName.substr(gifName.find_last_of('/') + 1) );
      }
    }
  }
  ofstream out("2.txt");
  for (string ss : s) {
    out << ss << endl;
  }
  out.close();
  return 0;
}
