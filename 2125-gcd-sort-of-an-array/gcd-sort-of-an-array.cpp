class DSU{
    int n;
    vector<int> rank, par;
public:
    DSU(int m){
        n = m;
        rank.resize(n, 1);
        par.resize(n, -1);
    }
    int findd(int a){
        if(par[a] == -1)
            return a;
        return par[a] = findd(par[a]);
    }
    void unionn(int a, int b){
        int s1 = findd(a), s2 = findd(b);
        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                par[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                par[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        DSU ds(100001);
        int n = nums.size();
        for(int i: nums){
            for(int j=2;j*j<i;j++){
                if(i%j == 0){
                    ds.unionn(i,j);
                    ds.unionn(i,i/j);
                }
            }
            if(ceil(sqrt(i)) == floor(sqrt(i)))
                ds.unionn(i, sqrt(i));
        }
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for(int i=0;i<n;i++){
            if(sorted[i] != nums[i] and ds.findd(sorted[i]) != ds.findd(nums[i]))
                return false;
        }
        return true;
    }
};