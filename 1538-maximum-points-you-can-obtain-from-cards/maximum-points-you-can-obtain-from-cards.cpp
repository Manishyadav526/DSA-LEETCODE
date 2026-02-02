class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftsum = 0, rightsum = 0, maxsum = 0;

        for(int i = 0; i < k; i++) 
            leftsum += cardPoints[i];

        maxsum = leftsum;
        int index = n - 1;

        for(int i = k - 1; i >= 0; i--) {
            leftsum -= cardPoints[i];
            rightsum += cardPoints[index--];
            maxsum = max(maxsum, leftsum + rightsum);
        }

        return maxsum;
    }
};