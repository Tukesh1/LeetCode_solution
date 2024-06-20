class Solution {
public:
    bool isPossibletoPlace(int force, vector<int>& position, int ball) {
        int prevForce = position[0];
        int count = 1;
        for (int i = 1; i < position.size(); i++) {
            int curr = position[i];
            // check curr
            if (curr - prevForce >= force) {
                count++;
                prevForce = curr;
            }
            if (count == ball)
                break;
        }
        return count == ball;
    }
    int maxDistance(vector<int>& position, int ball) {
        sort(position.begin(), position.end());
        // use binary search
        int n = position.size();
        // i,2,3,4,5,1000000
        int minForce = 1;
        int result = 0;
        int maxForce = position[n - 1] - position[0];
        while (minForce <= maxForce) {
            int midForce = minForce + (maxForce - minForce) / 2;
            if (isPossibletoPlace(midForce, position, ball)) {
                // yes then
                result = midForce;
                minForce = midForce + 1;
            } else {
                maxForce = midForce - 1;
            }
        }
        return result;
    }
};