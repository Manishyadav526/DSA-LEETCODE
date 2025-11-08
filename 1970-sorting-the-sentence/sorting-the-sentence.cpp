class Solution {
public:
    string sortSentence(string s) {
        vector<string>ans(10);
        string temp;
        int count=0;//to check only the no.of words present no need to traverse upto 9 
        int index=0;

        while(index<s.size()){

            if(s[index]==' '){
                int pos=temp[temp.size()-1]-'0';//for changing into int
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                count++;
                index++;

            }
            else{
                temp=temp+s[index];
                index++;
            }
        }
              int pos=temp[temp.size()-1]-'0';//for changing into int 
              //for the last word which does not have any space
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                count++;

                for(int i=1;i<=count;i++){
                    temp=temp+ans[i];
                    temp=temp+" ";
                }
        temp.pop_back();
        return temp;   
    }
};