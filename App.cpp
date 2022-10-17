#include <iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int minDepth(TreeNode* root) {
        // there are no nodes
        if (root == NULL)
        {
            return 0;
        }

        // if left sub tree is null, find the min depth for right sub tree
        // + 1 for the current layer
        if (root->left == NULL)
        {
            return 1 + minDepth(root->right);
        }
        // if right sub tree is null, find the min depth for left sub tree
        // + 1 for the current layer
        else if (root->right == NULL)
        {
            return 1 + minDepth(root->left);
        }

        // left sub tree AND right sub tree are not null
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
int main()
{
    Solution solution;

    TreeNode fifteen(15);
    TreeNode seven(7);
    TreeNode twenty(20, &fifteen, &seven);

    TreeNode nine(9);

    TreeNode root(3, &nine, &twenty);


    cout << "Example One : " << solution.minDepth(&root) << endl;
 
	return 0;
}
