/*    Matrix Walking Problem
Given an 01 matrix gird of size n*m, 1 is a wall, 0 is a road, now you can turn a 1 in the grid into 0, Is there a way to go from the upper left corner to the lower right corner? If there is a way to go, how many steps to take at least?
 */
/*
  下面的solution是一种多维度bfs，把图复制一份，然后原来图结点为1的地方
  都可以走到新图相同位置的1，bfs过程中，遇到1可以进行升维。

  另外，还有一种很巧妙的解法，就是当作大洋水那一题来解：分别从
  起始点(0, 0)和终点(m - 1, n - 1)进行bfs计算它到所有格子的最短距离
  （bfs的过程中一旦遇到1就return，把1当作墙来看），
  然后所有格子中两者和最小的那个就是最短路径
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    /**
     * @param grid: The gird
     * @return: Return the steps you need at least
     */
    
    int getBestRoad(vector<vector<int>> &grid) {
        int res = 0;
        if (grid.size() == 0 || grid[0].size() == 0)
            return res;
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool> > > visited(m, vector<vector<bool> >(n, vector<bool>(2, false)));
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<tuple<int ,int, int> > q;
        q.emplace(0, 0, 0);
        visited[0][0][0] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                tuple<int, int, int> t = q.front();
                q.pop();
                int level = get<2>(t);
                if (get<0>(t) == m - 1 && get<1>(t) == n - 1)
                    return res;
                for (auto& dir : dirs) {
                    int next_i = get<0>(t) + dir.first;
                    int next_j = get<1>(t) + dir.second;
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || visited[next_i][next_j][level])
                        continue;
                    if (level == 0 && grid[next_i][next_j] == 1) {
                        q.emplace(next_i, next_j, 1);
                        visited[next_i][next_j][1] = true;
                    } else if (grid[next_i][next_j] == 0) {
                        q.emplace(next_i, next_j, level);
                        visited[next_i][next_j][level] = true;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int> > M = {{0,1,0,0,0},{0,0,0,1,0},{1,1,1,0,0},{1,1,1,1,1},{1,1,1,0,0}};
    cout << s.getBestRoad(M) << endl;
    return 0;
}
