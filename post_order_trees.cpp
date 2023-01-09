#include <algorithm>
#include <vector>
#include "Tree.h"

// store post-order traversal of tree in vector
void postOrder(TreeNode* root, vector<int>& v)
{
	if (!root) return;
	postOrder(root->left, v);
	postOrder(root->right, v);
	v.push_back(root->val);
}
