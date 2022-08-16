class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=0, j=0;
        int arr[n+m];
        int k=0;
        
        while(i < m and j < n) {
            if(nums1[i] <= nums2[j]) {
                arr[k++] = nums1[i++];
            }
            else arr[k++] = nums2[j++];
        }
        while(i < m) {
            arr[k++] = nums1[i++];
        }
        while(j  < n){
            arr[k++] = nums2[j++];
        }
        k=0;
        for(int i=0; i<(n+m); i++) {
            nums1[i] = arr[k++];
        }
    }
};