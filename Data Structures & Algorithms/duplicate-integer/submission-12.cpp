class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()<2){
            return false;
        }
        if(nums.size()==2 && nums[0]==nums[1]) return true;
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