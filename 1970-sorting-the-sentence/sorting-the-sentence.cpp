class Solution {
public:
    string sortSentence(string s) {
    int n=s.length();
    unordered_map<int , string>mpp; //index and word

    string word = "";
    int index;
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            index=word[word.size()-1]-'0';
            word.pop_back();
            mpp[index]=word;
            word="";
        }
        else{
            word=word+s[i];
        }

    }
    index=word[word.size()-1]-'0';
    word.pop_back();
    mpp[index]=word; //last word bhi dal diya map me

    string ans="";
    for(int i=1;i<=mpp.size();i++){
        ans=ans+mpp[i]+" ";
    }
    ans.pop_back(); // Remove trailing space
    return ans;     
    }
};