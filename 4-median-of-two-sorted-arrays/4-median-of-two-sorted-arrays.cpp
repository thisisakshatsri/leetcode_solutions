class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> v;
        for(int i=0; i<n; i++){
            v.push_back(nums1[i]);
        }
        for(int i=0; i<m; i++){
            v.push_back(nums2[i]);
        }
        sort(v.begin(), v.end());
        
        int k = v.size();
        double hi = k-1;
        double lo = 0;
        double res;
        
        if( k % 2 != 0){
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