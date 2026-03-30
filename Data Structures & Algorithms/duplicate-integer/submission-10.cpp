class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()<2){
            return false;
        }
        unordered_set<int> seen;
        seen.reserve(2*nums.size());
        for(auto x : nums){
            if(seen.count(x)){
                return true;
            }
            seen.insert(x);
        }
        return false;
    }
};