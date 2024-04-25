class Solution {
public:

int solve(int &k,int n){
    if(n==1 ) return 0;
    n--;
    int st_num;
    int n_partial = n;
    while(k >= n_partial && n>1){
        n_partial = n_partial*(n-1);
        n--;
    }
    
    st_num = k/(n_partial);
    k = k% n_partial;
    return st_num;
}
    string getPermutation(int n, int k) {
        string ans="";
    set<int> s;
    for(int i =1 ;i<=n ;i++){
        s.insert(i);
    }
    set<int>::iterator itr;
    itr = s.begin();
    k= k-1;
    for(int i =0;i< n;i++){
        int indx = solve(k,n-i);
        advance(itr,indx);
        ans =ans + to_string(*itr);
        s.erase(itr);
       itr = s.begin();
    }
    return ans;
    }
};

