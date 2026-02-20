class Solution {
public:
    string sortVowels(string s) {
    string vowel="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            vowel.push_back(s[i]);
            s[i]='*';
        }
    }
    sort(vowel.begin(), vowel.end());
    int index=0;
    for(int j=0;j<s.length();j++){
        if(s[j]=='*'){
            s[j]=vowel[index++];
        }
    }
    return s;
    }
};
  
