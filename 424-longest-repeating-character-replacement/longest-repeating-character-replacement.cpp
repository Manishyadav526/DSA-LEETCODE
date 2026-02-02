class Solution {
public:
 int characterReplacement(string s, int k) {
     int n = s.size();
     int l = 0;
     int maxi = 0;
     int maxfreq = 0;
     vector<int> hash(26, 0);

     for (int r = 0; r < n; r++) {
        hash[s[r] - 'A']++;
        maxfreq = max(maxfreq, hash[s[r] - 'A']);

         while ((r - l + 1 - maxfreq) > k) {
            hash[s[l] - 'A']--;
            l++;
         }

        maxi = max(maxi, r - l + 1);
     }

    return maxi;
 }
};