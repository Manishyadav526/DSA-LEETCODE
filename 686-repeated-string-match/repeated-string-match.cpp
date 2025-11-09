class Solution {
public:
    vector<int> buildLPSLength(string pattern) {
        vector<int> lpsLength(pattern.size(), 0);
        int len = 0;
        int j = 1;
        
        while (j < pattern.size()) {
            if (pattern[j] == pattern[len]) {
                len++;
                lpsLength[j] = len;
                j++;
            } else {
                if (len > 0) {
                    len = lpsLength[len - 1];
                } else {
                    lpsLength[j] = 0;
                    j++;
                }
            }
        }
        
        return lpsLength;
    }
    
    int kmp(string text, string pattern) {
        vector<int> lpsLength = buildLPSLength(pattern);
        int i = 0;
        int j = 0;
        
        while (i < text.size()) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            } else {
                if (j > 0) {
                    j = lpsLength[j - 1];
                } else {
                    i++;
                }
            }
            
            if (j == pattern.size()) {
                return i - j;
            }
        }
        return -1;
    }
    
    int repeatedStringMatch(string a, string b) {
        string aRepeated = a;
        while (aRepeated.size() < a.size() + b.size()) {
            aRepeated += a;
        }
        
        int startIdx = kmp(aRepeated, b);
        if (startIdx == -1) {
            return -1;
        }
        
        return ceil(float(startIdx + b.size()) / a.size());
    }
};