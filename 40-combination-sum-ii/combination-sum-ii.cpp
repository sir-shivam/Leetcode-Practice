class Solution {

    // dont take , take 

    vector<vector<int>> ans;

    set<vector<int>> spp;

    int n ;
    vector<int> curr , can;

    void help( int idx , vector<int> & curr , int tar  ){

        if( tar == 0 ){
            ans.push_back(curr);
            return ;
        }
        // dont take
       for( int i = idx ; i < n ; i++){
        if( i > idx && can[i] == can[i-1]) continue;

        if( can[i] > tar ) break;

        curr.push_back(can[i]);

        help( i+1 , curr ,  tar - can[i] );

        curr.pop_back();
        
       }

    }


    
public:
    vector<vector<int>> combinationSum2(vector<int>& cann, int target) {
        can = cann;
        n = can.size();

        sort(can.begin() , can.end());
        help( 0 , curr , target);
        return ans;

    }
};