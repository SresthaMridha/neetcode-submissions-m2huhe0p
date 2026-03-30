class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size()+nums.size());
        int i = 0;
        int j = nums.size();
        while(i<nums.size()&&j<(nums.size()+nums.size())){
            ans[i]=nums[i];
            
            ans[j]=nums[i];
            j++;i++;
        }
        return ans;
    }
};