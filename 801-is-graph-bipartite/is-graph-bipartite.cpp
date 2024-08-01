class Solution {
public:
    bool CheckBipartite(vector<int>adj[], int u,int currClr, vector<int>& color) {
        color[u]= currClr;

        for(auto &v:adj[u]){
            if(color[v]== currClr){
                return false; //parent and child node have same color
            }
            if(color[v]==-1){
                int newClr = 1- currClr;
                if (CheckBipartite(adj, v, newClr, color) == false)
                    return false;
            }
        }
        return true;



    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> color(n, -1);
       
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        int currClr = 1;
        // clr 0, 1

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (CheckBipartite(adj, i, currClr, color) == false)
                    return false;
            }
        }
        return true;
    }
};