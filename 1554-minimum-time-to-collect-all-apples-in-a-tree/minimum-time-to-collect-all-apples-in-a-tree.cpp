class Solution {

    int help( int node , int par , int time ,  vector<vector<int>>  & adj , vector<bool>& hasApple  ){

        int child = 0 ;
        for(auto & a : adj[node]){
            if(par == a) continue;
            int tme = help( a , node , time +1 , adj , hasApple );

            if(tme) {
                child += ( tme - time  );
            }
        }

        if(child == 0 ){
            return hasApple[node] ? time : 0 ;
        }

        return child + time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>>  adj( n );

        for( auto & ed : edges){
            int u = ed[0];
            int v = ed[1];

            adj[u].push_back(v);
            adj[v].push_back(u );
        }

        return 2 * help( 0 , -1 , 0 , adj , hasApple);

    }
};