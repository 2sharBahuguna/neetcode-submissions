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
private:
    bool solve(TreeNode* root,long min,long max)
    {
        if(root==NULL)
        {
            return true;
        }

        if(root->val<=min || root->val>=max) return false;

        bool leftAns=solve(root->left,min,root->val);
        bool rightAns=solve(root->right,root->val,max);

        return leftAns && rightAns;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(solve(root,LLONG_MIN,LLONG_MAX)==true)
        {
            return true;
        }
        return false;
        
    }
};
