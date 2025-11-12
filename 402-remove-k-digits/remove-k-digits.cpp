class Solution {
public:
    string removeKdigits(string&s, int k) {
        int n = s.size();
        string st = "";
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(st.size()==1 && st.back()=='0'){
                st.pop_back();
                st.push_back(s[i]);
            }else if(st.empty() || st.back()<=s[i] || cnt>=k)st.push_back(s[i]);
            else if(st.back()>s[i]){
                while(!st.empty() && st.back()>s[i] && cnt<k){
                    st.pop_back();
                    cnt++;
                }
                st.push_back(s[i]);
            }
        }
        if(st.empty())return "0";
        while(!st.empty() && cnt<k){
            st.pop_back();
            cnt++;
        }
        return st.empty()?"0":st;
    }
};