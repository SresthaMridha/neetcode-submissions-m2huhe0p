class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> curr;
    void myfun(vector<int>& nums, int index, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (target < 0 || index >= nums.size()) {
            return;
        }

        curr.push_back(nums[index]);

        myfun(nums, index, target - nums[index]);

        curr.pop_back();

        myfun(nums, index + 1, target);
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        myfun(nums, 0, target);
        return ans;
    }
};
