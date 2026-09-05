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
    int solve(TreeNode* root,int& count,int & value,int k){
        if(root==NULL) return 0;

        solve(root->left,count,value,k);
        count++;

        if(count==k){
            value=root->val;
            return value;
        }

        solve(root->right,count,value,k);
        return value;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int value=INT_MIN;

        solve(root,count,value,k);
        return value;
    }
};
