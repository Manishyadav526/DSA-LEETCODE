class Solution {
public:
    string caseSort(string s) {
        
        int lower[26] = {0};
        int upper[26] = {0};
        
        // Step 1: Count + mark
        for(int i = 0; i < s.length(); i++){
            if(islower(s[i])){
                lower[s[i] - 'a']++;
                s[i] = '*';
            }
            else{
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }
        
        // Step 2: Build sorted strings
        string sortedLower = "", sortedUpper = "";
        
        for(int i = 0; i < 26; i++){
            while(lower[i]--){
                sortedLower += char(i + 'a');
            }
        }
        
        for(int i = 0; i < 26; i++){
            while(upper[i]--){
                sortedUpper += char(i + 'A');
            }
        }
        
        // Step 3: Replace back
        int l = 0, u = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                s[i] = sortedLower[l++];
            }
            else if(s[i] == '#'){
                s[i] = sortedUpper[u++];
            }
        }
        
        return s;
    }
};