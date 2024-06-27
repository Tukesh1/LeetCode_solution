class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        bitset<100000>visited=0;
        for(auto &e:edges){
            int u = e[0];
            int v= e[1];
            if(visited[u]) return u;
            if(visited[v]) return v;
            visited[v] = visited[u] = 1;
        }
        return -1;
    }
};