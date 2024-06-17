class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 1)
            return 1;
        int end = static_cast<long long>(sqrt(c));;
        int i = 0;
        while (i <= end) {
            if (pow(i, 2) + pow(end, 2) > c) {
                end--;

            } else if (pow(i, 2) + pow(end, 2) < c) {
                i++;

            } else {
                return true;
            }
        }
        return false;
    }
};