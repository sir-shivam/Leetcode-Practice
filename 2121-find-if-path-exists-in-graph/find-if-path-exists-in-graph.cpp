class Solution {

    bool dfs( int node , int par , vector<vector<int>> & adj , int des  , vector<int>  &vis){

        if( vis[node]) return false;
        if( des == node) return true;
        vis[node] = 1 ;

        for( auto & a : adj[node]){

            if( a == par ) continue;
            if(dfs(a , node , adj , des , vis)){
                return true;
            }
        }
    
        return false;
    }
public:

    bool validPath(int n, vector<vector<int>>& edges , int src , int des) {
        
        vector<vector<int>> adj( n );

        for( auto &  ed : edges){
            int u = ed[0];
            int v = ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n , 0 );

        return dfs( src , -1 , adj , des , vis );

    }
};