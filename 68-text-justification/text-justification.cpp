class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size(),curr=words[0].length();
        stack<string> s;
        vector<string> ans;
        s.push(words[0]);
        for(int i=1;i<n;i++){
            if(curr+1+words[i].length()>maxWidth){
                int m=s.size()-1,x=maxWidth-curr;
                string t="";
                while(!s.empty()){
                    t=s.top()+t;
                    if(m==0) while(x--) t+=" ";
                    else{
                        int e=x/(m==0?1:m);
                        x-=e;
                        while(e--) t=" "+t;
                    }
                    m--;
                    s.pop();
                }
                ans.push_back(t);
                if(i!=n){
                    s.push(words[i]);
                    curr=words[i].length();
                }
            }
            else{
                s.push(" "+words[i]);
                curr+=1+words[i].length();
            }
        }
        string t="";
        while(!s.empty()){
            t=s.top()+t;
            s.pop();
        }
        while(t.length()<maxWidth) t+=" ";
        ans.push_back(t);
        return ans;
    }
};