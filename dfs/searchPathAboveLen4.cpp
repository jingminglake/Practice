#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool DFS(int node, int d, unordered_map<int, vector<int> >& m, vector<bool>& visited){  
  if (d == 3){  
    return true;  
  }  
  visited[node] = true;
  for (int neighbor : m[node]){ 
    if (!visited[neighbor]){
      visited[neighbor] = true;
  
      if (DFS(neighbor, d+1, m, visited)){
	cout << neighbor << "  "; 
	return true;  
      }
      
      //visited[neighbor] = false;  
  
    }
  }  
  return false;
}

int main () {
  unordered_map<int, vector<int> > m;
  m[0] = {1, 2, 3};
  m[1] = {0, 2};
  m[2] = {0, 1};
  m[3] = {0, 4, 5};
  m[4] = {3};
  m[5] = {3, 6};
  m[6] = {5};
  vector<bool> visited(m.size(), false);
  cout << DFS(0, 0, m, visited) << endl;
  return 0;
}
