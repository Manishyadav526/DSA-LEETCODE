string sort(string s) {
    // complete the function here
    int freq[26]={0};
    int index;
    for(int i=0;i<s.length();i++){
        index=s[i]-'a';
        freq[index]++;
    }
    string ans="";
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            while(freq[i]--){
                ans.push_back(i+'a');
            }
        }
    }
    return ans;
    
}