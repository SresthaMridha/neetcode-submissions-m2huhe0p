class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto x: nums){
            if(++freq[x]>1){
                return true;
            }
        }
        return false;
    }
};