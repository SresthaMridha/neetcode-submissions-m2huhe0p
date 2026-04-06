class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        result.reserve(n);
        for(int i = 0; i<n-1;i++){
            if(i > 0 && nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = n-1;
            while(left<right){
                int total = nums[i]+nums[left]+nums[right];
                if(total == 0 ){
                    result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(total > 0){
                    right--;
                } else if(total < 0){
                    left++;
                }
            }
        }
        return result;
    }
};
