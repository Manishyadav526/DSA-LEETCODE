class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back() == '(' && c == ')') {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack.size();
    }
};