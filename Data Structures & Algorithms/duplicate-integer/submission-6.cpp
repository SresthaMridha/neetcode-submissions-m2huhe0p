class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()<2){
            return false;
        }
        unordered_map<int,int> freq;
        for(int i = 0; i<nums.size();i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>1){
                return true;
            }
        }
        return false;
    }
};