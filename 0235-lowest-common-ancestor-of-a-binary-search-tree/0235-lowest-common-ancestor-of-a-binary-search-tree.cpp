/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         // Start our search at the root of the tree
        TreeNode* current = root;
        
        // Traverse down the tree
        while (current != nullptr) {
            
            // If both p and q are greater than the current node, 
            // the LCA must be in the right subtree.
            if (p->val > current->val && q->val > current->val) {
                current = current->right;
            }
            // If both p and q are less than the current node, 
            // the LCA must be in the left subtree.
            else if (p->val < current->val && q->val < current->val) {
                current = current->left;
            }
            // If they split (one is greater, one is less), or if 
            // current equals p or q, we've found our LCA!
            else {
                return current;
            }
        }
        
        // This is just a fallback, though standard BST LCA problems 
        // guarantee that p and q exist in the tree.
        return nullptr;
    }
};