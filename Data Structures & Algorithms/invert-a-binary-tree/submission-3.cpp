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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* front=st.top();
            st.pop();

            if(front->left){
                st.push(front->left);
            }

            if(front->right){
                st.push(front->right);
            }

            TreeNode* temp=front->left;
            front->left=front->right;
            front->right=temp;
        }

        return root;

    }
};
