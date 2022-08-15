class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int ans[n+m];
        int i=0, j=0, k=0;
        
        while(i < m and j < n) {
            if(nums1[i] <= nums2[j]){
                ans[k++] = nums1[i++];
            }
            else{
                ans[k++] = nums2[j++];
            }
        }
        while(i < m) {
            ans[k++] = nums1[i++];
        }
        while(j < n) {
            ans[k++] = nums2[j++];
        }
        for(int x: ans) cout<<x<<" ";
        k=0;
        for(int l=0; l<n+m; l++)
            nums1[l] = ans[k++];
        
    }
};