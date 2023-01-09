#include <algorithm>
#include <vector>
#include "Tree.h"

using namespace std;

// store pre-order traversal of tree in vector
void preOrder(TreeNode* root, vector<int>& v)
{
	if (!root) return;
	v.push_back(root->val);
	preOrder(root->left, v);
	preOrder(root->right, v);
}
