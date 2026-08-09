class Solution {

    int height = 0 ;

    long long help( int node , int par , int d , vector<vector<int>> & adj , vector<int> &  nums){

        height = max( height , d );

        long long ans = 0 ;
        for(auto & a : adj[node]){
            if( a == par ) continue;

            ans +=  help( a , node , d+1 , adj , nums);
        }

        return ans + ( d *  1LL* nums[node]);

    }
    
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        long long sum = nums[0];

        for(int i = 1 ; i < n ; i++){
            sum += 1LL*nums[i];
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        long long t =  help( 0 , -1 , 1 , adj , nums) ;

        return (height + 1 ) * sum - t  ;

    }
};