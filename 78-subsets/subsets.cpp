class Solution {
public:
       void generateSubsets(vector<int>& nums, int index, vector<int>& temp,    
       vector<vector<int>>& ans) {
        // base case: when we have considered all elements
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // CASE 1: include temp element
        temp.push_back(nums[index]);
        generateSubsets(nums, index + 1, temp, ans);


        // CASE 2: exclude temp element (backtrack)
        temp.pop_back();
        generateSubsets(nums, index + 1, temp, ans);
    }
   
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateSubsets(nums, 0, temp, ans);
        return ans;
    }
};
