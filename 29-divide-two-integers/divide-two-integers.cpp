class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long dd = llabs((long long)dividend);
        long long dv = llabs((long long)divisor);

        long long res = 0;  // <-- must be long long
        while (dv <= dd) {
            long long mul = dv;
            long long tmp = 1;
            while ((mul << 1) <= dd) {
                mul <<= 1;
                tmp <<= 1;
            }
            dd -= mul;
            res += tmp;
        }

        if ((dividend < 0) ^ (divisor < 0))
            res = -res;  // <-- safe now

        return (int)res;
    }
};
