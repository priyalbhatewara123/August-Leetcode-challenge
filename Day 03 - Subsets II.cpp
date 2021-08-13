class Solution {

    void helper(vector<int>& nums , int i , vector<int>& temp, vector<vector<int>>& ans) {

        //base case
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        //recursive case

        //1. Include the present element
        temp.push_back(nums[i]);
        helper(nums, i + 1, temp, ans);

        //2. Don't include current element
        int x = temp.back();
        temp.pop_back();
        while (i < nums.size() - 1 and nums[i + 1] == x) {
            i++;
        }
        helper(nums, i + 1, temp, ans);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans; //not definig it global this time
        sort(nums.begin(), nums.end());
        vector<int> temp;
        helper(nums, 0, temp, ans);
        return ans;
    }
};