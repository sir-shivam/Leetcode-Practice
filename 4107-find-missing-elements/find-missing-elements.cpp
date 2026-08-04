class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        sort( nums.begin(), nums.end());

        vector<int> ans;

        set<int> spp( nums.begin() , nums.end());

        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[n-1];

        for( int i = mini ; i <= maxi ; i++){
            if(!spp.count(i)){
                ans.push_back(i);
            }
        }
        

        return ans;
    }
};