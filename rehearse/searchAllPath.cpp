#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void DFS(int start, int dest, unordered_map<int, vector<int> >& m, vector<bool>& visited,  vector<vector<int> >& allPath, vector<int>& path){  
    if (start == dest) {
        allPath.push_back(path);
        return;
    }
    for (int neighbor : m[start]){ 
        if (!visited[neighbor]) {
            path.push_back(neighbor);
            visited[neighbor] = true;
            DFS (neighbor, dest, m, visited, allPath, path);
            path.pop_back();
            visited[neighbor] = false;
        }
    }
}

int main () {
  unordered_map<int, vector<int> > m;
  m[0] = {1, 2};
  m[1] = {0, 3, 5};
  m[2] = {0, 3};
  m[3] = {1, 2, 4};
  m[4] = {3, 5};
  m[5] = {1};
  vector<bool> visited(m.size(), false);
  vector<vector<int> > allPath;
  vector<int> path;
  path.push_back(0);
  visited[0] = true;
  DFS(0, 5, m, visited, allPath, path);
  for (auto& vec : allPath) {
      for (int i : vec)
          cout << i << " ";
      cout << endl;
  }
  return 0;
}
