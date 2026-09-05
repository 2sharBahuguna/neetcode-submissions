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
    void dfs(TreeNode* root,int &count,int maxCurr)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->val>=maxCurr)
        {
            count++;
            maxCurr=root->val;
        }

        dfs(root->left,count,maxCurr);
        dfs(root->right,count,maxCurr);
    }
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        int maxCurr=root->val;
        dfs(root,count,maxCurr);
        return count;            
    }
};
