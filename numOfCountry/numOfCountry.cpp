#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        if (m == 0)
            return res;
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    pair<int, int> startPoint = make_pair(i, j);
                    bfs(grid, m, n, startPoint);
                    res++;
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<char> >& grid, int m, int n, pair<int, int>& startPoint) {
        queue<pair<int, int> > q;
        q.push(startPoint);
        vector<pair<int, int> > directions = {make_pair(0, 1), make_pair(1, 0), make_pair(0,-1), make_pair(-1, 0)};  
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (pair<int, int>& dir : directions) {
                int i = p.first + dir.first;
                int j = p.second + dir.second;
                if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
                    continue;
                if (grid[i][j] == '1') {
                   pair<int, int> temp = make_pair(i, j);
	               q.push(temp);
                   grid[i][j] = '0'; 
                }
            }
        }
    }
};

int main()
{
  Solution s;
  char a1[5] = {'1','1','0','0','0'};
  char a2[5] = {'1','1','0','0','0'};
  char a3[5] = {'0','0','1','0','0'};
  char a4[5] = {'0','0','0','1','1'};
  vector<char> vec1(a1, a1+5);
  vector<char> vec2(a2, a2+5);
  vector<char> vec3(a3, a3+5);
  vector<char> vec4(a4, a4+5);
  vector<vector<char> > grid;
  grid.push_back(vec1);
  grid.push_back(vec2);
  grid.push_back(vec3);
  grid.push_back(vec4);
  cout << s.numIslands(grid) << endl;
  return 0;
}
