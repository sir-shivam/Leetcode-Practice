class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();

        if( n == 0 ) return {};

        vector<pair<int , int>> nums( n );
        for(int i = 0 ; i < n ; i++){
            nums[i] = {arr[i] , i };
        }

        sort(nums.begin() , nums.end());
        vector<int> ans( n );

        

        int rank = 1;
        ans[nums[0].second] = rank;

        for( int i = 1 ; i < n ; i++ ){

            if( nums[i].first == nums[i-1].first ){
                ans[nums[i].second] = rank;
            }else{
                rank ++;
                ans[nums[i].second] = rank;
            }
        }

        return ans;
    }
};