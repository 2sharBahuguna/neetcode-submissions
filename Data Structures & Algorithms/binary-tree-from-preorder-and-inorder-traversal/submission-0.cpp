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
    int find(vector<int>& inorder,int element)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==element)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int start,int end,int& index)
    {
        if(start>end || start>inorder.size())
        {
            return NULL;
        }
        int element=preorder[index++];
        int position=find(inorder,element);
        TreeNode* root=new TreeNode(element);
        root->left=solve(preorder,inorder,start,position-1,index);
        root->right=solve(preorder,inorder,position+1,end,index);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorder_start=0;
        int preorder_end=preorder.size()-1;
        int index=0;
        TreeNode* root=solve(preorder,inorder,preorder_start,preorder_end,index);
        return root;
    }
};
