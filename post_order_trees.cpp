#include <algorithm>
#include <vector>
#include "Tree.h"

// store post-order traversal of tree in vector
void postOrder(TreeNode* root, vector<int>& v)
{
	if (!root) return;
	inOrder(root->left, v);
	inOrder(root->right, v);
	v.push_back(root);
}
