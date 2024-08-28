class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        /*
         2 3 4 7 11
         1 5 6 8 9 10 12...
        */
       int ind = 0, ans = 1, n = arr.size();
        priority_queue<int> maxHeap;

        while (maxHeap.size() != k) {
            if ((ind < n && ans < arr[ind]) || ind >= n) maxHeap.push(ans);
            if (ind < n && ans == arr[ind]) ind++;
            ans++;
        }
        return maxHeap.top();


    }
};