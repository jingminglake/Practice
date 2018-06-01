#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
  stack<int> s;
  s.push(100);
  for (int i = 0; i < 3; i++)
    --s.top();
  cout << s.top() << endl;
  queue<int> q;
  q.push(100);
  for (int i = 0; i < 4; i++)
    --q.front();
  cout << q.front() << endl;
  return 0;
}
