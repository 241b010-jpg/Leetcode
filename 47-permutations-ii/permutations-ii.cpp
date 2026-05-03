class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip used elements
            if (used[i]) continue;

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            // Choose
            used[i] = true;
            path.push_back(nums[i]);

            // Explore
            backtrack(nums, path, used);

            // Undo
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1: sort
        vector<int> path;
        vector<bool> used(nums.size(), false);

        backtrack(nums, path, used);
        return result;
    }
};