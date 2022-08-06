class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int v[n+m];
        int i=0, j=0, k=0;
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]){
                v[k++] = nums1[i++];
            }
            else v[k++] = nums2[j++];
        }
        while(i < n) {
            v[k++] = nums1[i++];
        }
        while(j < m) {
            v[k++] = nums2[j++];
        }
        
        int len = n+m;
        double hi = k-1;
        double lo = 0;
        double res;
        
        if( len % 2 != 0){
            int mid = lo + (hi - lo) / 2.0;
            res = v[mid];
        }
        else {
            int mid = lo + (hi - lo) / 2;
            double ans = (v[mid] + v[mid+1]) / 2.0;
            cout<< ans <<endl;
            res = ans;
        }
        return res;
    }
};