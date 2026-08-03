class Solution {

    int N ;
    int help( int node , int par  , int dist ,  vector<vector<int> > &  adj  , vector<int> & child){

        int ans = 0 ;

        for( auto & a: adj[node]){
            if(a == par) continue;

            ans +=  help( a , node   , dist +1 , adj , child);
            // child[node] += child[a];
            child[node] += child[a];

        }

        return dist +  ans;

    }

    void dfs( int node , int par , vector<int> & ans , vector<int> & child , vector<vector<int> > &  adj ){

        for(auto & a: adj[node]){
            if( a == par ) continue;

            ans[a] = ans[node] - child[a] + ( N - child[a]);

            dfs( a , node , ans , child , adj);

        }

    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n ;
        vector<vector<int> > adj( n );

        for( auto & ed : edges){
            int u = ed[0];
            int v = ed[1];

            adj[u].push_back(v);

            adj[v].push_back(u );
        }

        vector<int> ans( n , 0 );

        vector<int> child( n , 1 );

        int t = help( 0 , -1 , 0 , adj , child);

        ans[0] = t ;


        dfs(0 , -1 , ans , child , adj );

        return ans;
    }
};