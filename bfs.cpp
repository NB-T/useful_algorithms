#include <vector>
#include <Tree.h>

using namespace std;

void bfs(TreeNode* root)
{
     vector<TreeNode*> current;
     vector<TreeNode*> next;
     if (root) current.push_back(root);
     while (current.size() > 0)
     {
          for (TreeNode* n : current)
          {
               // do something
               if (n->left) next.push_back(n->left);
               if (n->right) next.push_back(n->right);
          }
          current = next;
          next.clear();
     }
}
