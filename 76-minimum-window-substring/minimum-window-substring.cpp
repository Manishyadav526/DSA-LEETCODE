class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) return "";

        // frequency map
        vector<int> m(128, 0);

        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }

        int start = 0, end = 0;
        int ans = INT_MAX;
        int index = -1;
        int total = t.size();   // total chars needed

        while (end < s.size()) {

            m[s[end]]--;
            if (m[s[end]] >= 0) {
                total--;
            }

            // When all chars matched → try shrinking window
            while (total == 0 && start <= end) {

                if (ans > end - start + 1) {
                    ans = end - start + 1;
                    index = start;
                }

                m[s[start]]++;
                if (m[s[start]] > 0) {
                    total++;
                }

                start++;
            }

            end++;  // end++
        }

        if (ans == INT_MAX) return "";
        return s.substr(index, ans);
    }
};
