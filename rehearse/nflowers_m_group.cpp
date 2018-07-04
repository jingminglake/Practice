#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> generateFlowers() {
   vector<int> flowers;
    unordered_set<int> used;
    srand(time(0));
    for (int i = 0; i < 7; i++) {
        int num = rand() % 7 + 1;
        if (!used.count(num)) {
            flowers.push_back(num);
            used.insert(num);
        }
        else {
            i--;
        }
    }
    return flowers;
}

unordered_map<int, int> parent;
unordered_map<int, int> component_size;
unordered_set<int> cur_components;

int find_op(int node) {
    if (!parent.count(node)) {
        component_size[node] = 1;
        return parent[node] = node;
    } else if (parent[node] == node) {
        return node;
    } else {
        return parent[node] = find_op(parent[node]);
    }
}

void union_op(int node_1, int node_2) {
    int p_1 = find_op(node_1);
    int p_2 = find_op(node_2);
    if (p_1 != p_2) {
        component_size[p_1] += component_size[p_2];
        parent[p_2] = p_1;
        cur_components.erase(p_2);
    }
}

int querySize(int node) {
    int parent = find_op(node);
    return component_size[parent];
}

int getDay(vector<int>& flowers, int K, int M) {
    int day = -1;
    for (int i = 0; i < flowers.size(); i++) {
        cur_components.insert(flowers[i]);
        parent[flowers[i]] = flowers[i];
        component_size[flowers[i]] = 1;
        if (parent.count(flowers[i] - 1)) {
            union_op(flowers[i], flowers[i] - 1);
        }
        if (parent.count(flowers[i] + 1)) {
            union_op(flowers[i], flowers[i] + 1);
        }
        if (cur_components.size() >= M) {
            bool flag = true;
            for (int node : cur_components) {
                if (querySize(node) < K) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                day = i + 1;
        }
    }
    return day;
}

int main() {
    vector<int> flowers = generateFlowers();
    for (int i = 0; i < flowers.size(); i++) {
        cout << flowers[i] << ",";
    }
    cout << endl;
    cout << getDay(flowers, 2, 2) << endl;
    return 0;
}
