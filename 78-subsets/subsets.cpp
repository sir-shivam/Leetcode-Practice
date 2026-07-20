class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>> ans;

        for( int x = 0 ; x < ( 1 << n ) ; x++){

            vector<int> curr;

            for( int i = 0 ; i < n ; i++){
                if( x & ( 1 << i )){
                    curr.push_back(nums[i]);
                }

            }
                ans.push_back(curr);
        }

        return ans;
    }
};