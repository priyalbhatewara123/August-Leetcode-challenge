class Solution {
    void helper(TreeNode* root, int targetSum , vector<vector<int>>& ans , vector<int>& path) {
        //base case
        if (root == NULL)
            return;

        path.push_back(root->val);
        targetSum -= root->val;
        if (!(root->right) and !(root->left) and targetSum == 0)
            ans.push_back(path);

        helper(root->left, targetSum, ans, path);
        helper(root->right, targetSum, ans, path);

        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        helper(root , targetSum , ans, path);
        return ans;
    }
};