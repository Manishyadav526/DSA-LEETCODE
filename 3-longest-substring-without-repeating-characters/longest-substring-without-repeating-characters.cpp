class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> arr(128, 0);
        int maxLen = 0, l = 0, r = 0;

        while (r < s.size()) {
            if (!arr[s[r]]) {
                arr[s[r]] = 1;
                maxLen = max(maxLen, r - l + 1);
                r++;
            } else {
                arr[s[l]] = 0;
                l++;
            }
        }
        return maxLen;
    }
};