class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //mayer boore voting algo

        int candidate = 0;
        int voting = 0;

        for(auto x : nums){
            if(voting == 0){
                candidate = x;
            }
            if(x == candidate){
                voting++;
            }
            else{
                voting--;
            }
        }
        return candidate;
    }
};