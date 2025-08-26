class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // left product and right product
        int n = nums.size();
        //[1,2,3,4]
        vector<int> left(n, 1), right(n, 1), res(n, 1);
        int prod = 1;
        for (int i = 0; i < n; i++) {
            prod = nums[i] * prod;
            left[i] = prod;
        }
        // left = [1,2,6,24]
        prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            prod = nums[i] * prod;
            right[i] = prod;
        }
        for(int i=0;i<n;i++) cout<<right[i]<<" ";
        // right = [24,12,8,6]
        // res[0] = right[1]; res[n - 1] = left[n - 2]; for(I = 1 to n-1
        // )res[i]= left[i-1]*right[i+1]
        res[0] = right[1];
        res[n - 1] = left[n - 2];
        for (int i = 1; i < n - 1; i++) {
            res[i]= left[i-1] *right[i+1];
        }
        return res;
    }
};