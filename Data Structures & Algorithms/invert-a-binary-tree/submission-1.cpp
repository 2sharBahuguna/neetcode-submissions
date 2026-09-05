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
            TreeNode* frontNode=st.top();
            st.pop();

            if(frontNode->left){
                st.push(frontNode->left);
            }
            if(frontNode->right) {
                st.push(frontNode->right);
            }

            TreeNode* temp=frontNode->left;
            frontNode->left=frontNode->right;
            frontNode->right=temp;
        }

        return root;
    }
};
