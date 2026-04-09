class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right = m+n-1;
        int mid = m-1;
        int left = n-1;
        while(mid>=0 && left >=0){
            if(nums1[mid]>=nums2[left]){
                nums1[right]=nums1[mid];
                mid--;
                right--;
            } else{
                nums1[right]=nums2[left];
                left--;
                right--;
            }
        }
        while(left >=0){
            nums1[right]=nums2[left];
            left--;
            right--;
        }
    }
};