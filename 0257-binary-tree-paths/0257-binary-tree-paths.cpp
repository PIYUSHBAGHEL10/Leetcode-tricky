/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void PreOrder(TreeNode* root,
                  vector<string>& ans,
                  string path)
    {
        if(root == nullptr) return;

        path += to_string(root->val);

        if(root->left == nullptr &&
           root->right == nullptr)
        {
            ans.push_back(path);
            return;
        }

        PreOrder(root->left, ans, path + "->");
        PreOrder(root->right, ans, path + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        PreOrder(root, ans, "");

        return ans;
    }
};