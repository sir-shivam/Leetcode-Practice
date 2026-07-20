class Solution {

    vector<vector<int>> ans;

    void help(int i ,  vector<int> &  curr , vector<int> & nums ){

        if( i == nums.size()) return ;
        // take this i


        curr.push_back( nums[i]);
        ans.push_back(curr);

        help( i + 1 , curr , nums ); 


        // remove this i and move forword 

        curr.pop_back();
        // ans.push_back(curr);

        help( i+1 , curr , nums);

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> curr = {};
        ans.push_back({});
        help( 0 , curr , nums );



        return ans;


    }
};