class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  // no product < 1 possible

        long long product = 1;
        int start = 0;
        int count = 0;

        for (int end = 0; end < nums.size(); end++) {
            product *= nums[end];

            // shrink window until product < k
            while (product >= k) {
                product /= nums[start];
                start++;
            }
            count += (end - start + 1);
        }

        return count;
    }
};
