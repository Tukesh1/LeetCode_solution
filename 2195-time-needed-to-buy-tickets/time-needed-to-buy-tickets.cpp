class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ct = 0;
        for(int i = 0;i< tickets.size();i++){
            if(i <= k){
                ct += min(tickets[i], tickets[k]);
            }
            else{
                ct += min(tickets[i], tickets[k]-1);
            }
        }
        return ct;
    }
};