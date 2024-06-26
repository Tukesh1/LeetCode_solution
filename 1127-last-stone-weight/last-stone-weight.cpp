class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(auto i:stones){
            q.push(i);
        }
        // now you have queue with stones in decreasing order
        while(q.size() != 1){
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            q.push(y-x);
        }
        return q.top();
    }
};