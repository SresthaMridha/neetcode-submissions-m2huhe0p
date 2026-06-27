class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i-1]==nums[i]){
                continue;
            }
            int target = -1 * nums[i];

            int left = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left]==nums[left-1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
                else if(sum > target){
                    right--;
                }
                else{
                    left++;
                }

            }

        }
        return res;
    }
};
