class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int  left = 0;
        int right = m;

        while(left <= right){
            //partition of nums1
            int i = (left + right) / 2;
            //partition of nums2;
            int j  = (m + n + 1) / 2 - i;

            //assigning values of l1 r1 l2 r2
            int l1 = (i == 0) ? INT_MIN : nums1[i-1];
            int r1 = (i == m) ? INT_MAX : nums1[i];

            int l2 = (j == 0) ? INT_MIN : nums2[j-1];
            int r2 = (j == n) ? INT_MAX : nums2[j];

            if(l1 <= r2 && l2 <= r1){
                //if odd elements
                if((m + n) % 2 == 1){
                    return max(l1, l2);
                }
                return (max(l1,l2) + min(r1, r2)) / 2.0;
            }
            if(l1 > r2){
                //too many elemenst on left. move left
                right = i-1;
            }
            if(l2 > r1){
                //too less on left, move right
                left = i+1;
            }
        }
        return 0.0;
    }
};
