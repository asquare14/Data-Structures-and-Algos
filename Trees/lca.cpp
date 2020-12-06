/**
 * https://www.youtube.com/watch?v=13m9ZCB8gjw&t=1s
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
    TreeNode* lca(TreeNode* root, TreeNode* n1, TreeNode* n2)
    {
        if(root == NULL) 
            return NULL;
        if(root == n1 || root ==n2) return root;
        TreeNode* l = lca(root->left,n1,n2);
        TreeNode* r = lca(root->right,n1,n2);
        if(l && r) return root;
        return l != NULL ? l : r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }rr
};
