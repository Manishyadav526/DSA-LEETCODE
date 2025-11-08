class Solution {
public:
    string sortVowels(string s) {
        string vowels = "";  // to store all vowels

        // Step 1: Collect vowels and replace them with a placeholder
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vowels += s[i];   // store vowel
                s[i] = '#';       // mark position
            }
        }

        // Step 2: Sort the vowels
        sort(vowels.begin(), vowels.end());

        // Step 3: Put sorted vowels back in original string
        int j = 0; // index for vowels
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }

    // Helper function to check vowel
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
};
