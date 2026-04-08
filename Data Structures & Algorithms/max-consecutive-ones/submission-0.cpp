class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        int result=INT_MIN;
        for(auto x: nums){
            if(x == 1){
                count++;
            } else{
                count = 0;
            }
            result = max(result,count);
        }
        return result;
    }
};