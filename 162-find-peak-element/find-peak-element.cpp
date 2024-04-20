class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        // peak number Ex for arr[i-1] < arr[i]> arr[i+1]
        int n = arr.size();
        int ans= 0;
        for(int i =1 ;i< n ;i++){
            if ((i == 0 || arr[i - 1] < arr[i])
                && (i == n - 1 || arr[i] > arr[i + 1])) {
            return i;
        }
        }
        return 0;
    }
};