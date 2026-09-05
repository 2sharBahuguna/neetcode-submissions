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
    int solve(TreeNode* root,int& diameter){
        if(root==NULL) return 0;

        int leftAns= solve(root->left,diameter);
        int rightAns= solve(root->right,diameter);
        diameter= max(diameter,leftAns+rightAns);
        return 1+max(leftAns,rightAns);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        solve(root,diameter);
        return diameter;
    }
};
