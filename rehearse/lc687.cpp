#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int l_child(int index, unordered_map<int, pair<int, int> >& m) {
    if (!m.count(index))
        return -1;
    else
        return m[index].first;
}

int r_child(int index, unordered_map<int, pair<int, int> >& m) {
    if (!m.count(index))
        return -1;
    else
        return m[index].second;
}

int getEqual(int root, int& res, vector<int>& nodes, unordered_map<int, pair<int, int> >& m) {
    if (root == -1)
        return 0;
    int left_res = getEqual(l_child(root, m), res, nodes, m);
    int right_res = getEqual(r_child(root, m), res, nodes, m);
    res = max (res, left_res);
    res = max (res, right_res);
    int left_equal_res = 0, right_equal_res = 0;
    if (l_child(root, m) != -1 && nodes[l_child(root, m)] == nodes[root])
        left_equal_res = left_res + 1;
    if (r_child(root, m) != -1 && nodes[r_child(root, m)] == nodes[root])
        right_equal_res = right_res + 1;
    res = max (res, left_equal_res + right_equal_res);
    return max (left_equal_res, right_equal_res);
}

int main() {
    vector<int> nodes = {1,1,1,2,2};
    vector<int> edges = {1,2,1,3,2,4,2,5}; // 1->2 1->3,...
    unordered_map<int, pair<int, int> > m;
    for (int i = 0; i < edges.size() - 1; i += 2) {
        if (!m.count(edges[i] - 1))
            m[edges[i] - 1].first = edges[i + 1] - 1;
        else
            m[edges[i] - 1].second = edges[i + 1] - 1;
    }
    int res = 0;
    // for (auto& p : m) {
    //    cout << p.first << "->(" << p.second.first << "," << p.second.second << ")" << endl;
    //}
    getEqual(0, res, nodes, m);
    cout << res << endl;
    return 0;
}
