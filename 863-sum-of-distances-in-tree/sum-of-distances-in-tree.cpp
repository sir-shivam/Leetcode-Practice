class Solution {

    int N ;
    int help( int node , int par , int d  ,  vector<vector<int>> & adj , vector<int>  & child ){

        
        int res = d  ;
        for( auto & a :  adj[node]){
            if( a == par ) continue;
            res += help( a , node , d+1 , adj , child);
            child[node] += child[a];
        }

        return res ;
    }   

    void dfs( int node , int par ,vector<int> & child,  vector<vector<int>> & adj , vector<int> & ans ){

        for( int & a : adj[node]){
            if( a == par ) continue;
            
            ans[a] = ans[node] - child[a] + ( N - child[a]);

            dfs( a , node , child, adj , ans);
            
        }
    }


public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // wow  lets solve it again 

        N = n ;
        vector<vector<int>>  adj( n );

        for( auto & ed : edges){
            int u = ed[0];
            int v = ed[1];

            adj[u].push_back(v );
            adj[v].push_back(u );
        }

        vector<int> dis( n ) , ans(n , -1) , child( n , 1);

        ans[0] = help( 0 , -1 , 0 , adj , child);

        dfs( 0 , -1 , child , adj , ans);
        
        return ans;

    }
};