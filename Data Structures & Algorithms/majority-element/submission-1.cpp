class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //boyer moore voting algo
        int candidate =  0;
        int voting = 0;
        for(auto x: nums){
            if(voting == 0){
                candidate = x;
            }
            if(candidate == x){
                voting++;
            }
            else{
                voting--;
            }
        }
        return candidate;
    }
};