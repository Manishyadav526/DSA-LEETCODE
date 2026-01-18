class Solution {
public:
    bool isValid(int day, int &m, int &k, int &n, vector<int> &bloomDay) {
        
        int boquets = 0;
        int numOfFlowers = 0;
        for(int i=0; i<n; i++) {
            
            if(bloomDay[i] <= day) {
                numOfFlowers += 1;
                if(numOfFlowers == k) {
                    boquets += 1;
                    numOfFlowers = 0;
                }
            } else {
                numOfFlowers = 0;
            }
        }

        return boquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        int ans = -1;

        if(m > (n / k))
            return ans;
        
        int start = INT_MAX;
        int end = INT_MIN;

        for(int i=0; i<n; i++) {
            end = max(end, bloomDay[i]);
            start = min(start, bloomDay[i]);
        }
        
        while(start <= end) {
            
            int mid = start + (end - start) / 2;
            if(isValid(mid, m, k, n, bloomDay)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};