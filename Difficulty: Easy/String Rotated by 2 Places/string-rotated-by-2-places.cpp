class Solution {
  public:
  
    void rotate_clockwise(string &s){
        int n = s.length();
        char temp = s[n-1];
        for(int i = n-1; i >= 1; i--){
            s[i] = s[i-1];
        }
        s[0] = temp;
    }
    
    void rotate_anticlockwise(string &s){
        int n = s.length();
        char temp = s[0];
        for(int i = 0; i < n-1; i++){
            s[i] = s[i+1];
        }
        s[n-1] = temp;
    }
    
    bool isRotated(string& s1, string& s2) {
        
        // Length different → never possible
        if(s1.length() != s2.length())
            return false;
        
        // If string length < 2
        if(s1.length() < 2)
            return s1 == s2;
        
        string clockwise = s1;
        rotate_clockwise(clockwise);
        rotate_clockwise(clockwise);
        
        if(clockwise == s2)
            return true;
        
        string anticlockwise = s1;
        rotate_anticlockwise(anticlockwise);
        rotate_anticlockwise(anticlockwise);
        
        if(anticlockwise == s2)
            return true;
            
        return false;
    }
};