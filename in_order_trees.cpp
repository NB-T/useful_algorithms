#include <algorithm>
#include <vector>
#include <Tree.h>

using namespace std;

// store in-order traversal of tree in vector
void inOrder(TreeNode* root, vector<int>& v)
{
	if (!root) return;
	inOrder(root->left, v);
	v.push_back(root);
	inOrder(root->right, v);
}


// convert vector representing in-order traversal of tree to binary search tree
TreeNode* inOrderToBST(vector<int>& v, int start, int end)
{
	if (start > end) return nullptr;
	int mid = (start + end) / 2;
	TreeNode* root = v[mid];
	root->left = inOrderToBST(start, mid - 1);
	root->right = inOrderToBST(mid + 1, end);
	return root;
}