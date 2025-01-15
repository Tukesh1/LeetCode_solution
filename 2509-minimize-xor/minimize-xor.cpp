class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int sbits = __builtin_popcount(num2);// set count
        cout<<sbits;
        int x = 0;

        // Copy bits from num1 to x, prioritizing higher bits
        for (int i = 31; i >= 0; --i) { // Assume 32-bit integers
            if (num1 & (1 << i)) {      // Check if the i-th bit is set in num1
                if (sbits > 0) {
                    x |= (1 << i); // Set the i-th bit in x
                    sbits--;
                }
            }
        }
        for (int i = 0; i < 32 && sbits > 0; ++i) {
            if (!(x & (1 << i))) { // Check if the i-th bit is unset in x
                x |= (1 << i);
                sbits--;
            }
        }
        return x;
    }
};