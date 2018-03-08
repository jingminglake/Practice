#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  bool isCompleteBinaryTree(TreeNode *root) {
    if (!root)
      return true;
    queue<pair<TreeNode *, int> > q;
    q.push(make_pair(root, 1));
    int prev = 0;
    while (!q.empty()) {
      pair<TreeNode*, int> temp = q.front();
      q.pop();
      if (temp.second - prev != 1)
	return false;
      prev = temp.second;
      if (temp.first->left)
	q.push(make_pair(temp.first->left, temp.second * 2));
      if (temp.first->right)
	q.push(make_pair(temp.first->right, temp.second * 2 + 1));
    }
    return true;
  }
};

int main()
{
  Solution s;
  int tree[11] = {3,9,20,1,2,15,7,9,10,9999,100};
  int size = sizeof(tree)/sizeof(tree[0]);
  vector<TreeNode *> vec;
  for (int i = 0; i < size; i++) {
    if (tree[i] != 9999) {
      vec.push_back(new TreeNode(tree[i]));
    } else {
      vec.push_back(NULL);
    }
  }
  for (int i = 0; i < size/2; i++) {
    if(!vec[i])
      continue;
    if (i*2 + 1 < size)
      vec[i]->left = vec[i*2 + 1];
    if (i*2 + 2 < size)
      vec[i]->right = vec[i*2 + 2];
  }
  cout << s.isCompleteBinaryTree(vec[0]);
  cout << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
