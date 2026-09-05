class Solution {
private:
    int solve(TreeNode* root, int k, int& count, int& value) {
        if (root == nullptr) {
            return 0;
        }
        int leftAns = solve(root->left, k, count, value);
        count++;
        if (count == k) {
            value = root->val; // Update value when kth element is found
            return value;
        }
        int rightAns = solve(root->right, k, count, value);
        return value;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int value = INT_MIN; // Initialize value with INT_MIN

        solve(root, k, count, value);

        return value;
    }
};
