class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // frefix common array
        vector<int> ans;
        int n= A.size();
        int mp[51] ={0};
        int cnt =0;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if(mp[A[i]] == 2) cnt++;
            
            mp[B[i]]++;
            if(mp[B[i]]==2) cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};