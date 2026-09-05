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
    bool solve(long mini,long maxi,TreeNode* root){
        if(root==NULL) return true;


        if(root->val<=mini || root->val >=maxi){
            return false;
        }


        bool leftAns=solve(mini,root->val,root->left);
        bool rightAns=solve(root->val,maxi,root->right);

        return leftAns && rightAns;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!solve(LLONG_MIN,LLONG_MAX,root)){
            return false;
        }
        return true;
    }
};
