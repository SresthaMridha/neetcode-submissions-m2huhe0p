class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int mid;
        int left = 0;
        int right = n-1;
        while(left < right){
            mid = (left + right)/2;
            if(nums[mid]>nums[right]){
                left = mid+1;
            }
            else { 
                right = mid;
            }
        }
        return nums[left];//or return nums[right]

    }
};
