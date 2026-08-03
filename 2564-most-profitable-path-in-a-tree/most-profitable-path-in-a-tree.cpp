class Solution {

    // trying backtrack first

    int help( int alice , int par , int cnt , vector<vector<int>> & adj , vector<int> & dis , vector<int> & amount ){

        bool isLeaf = true;
        int next = -1e9 ;
        for( auto & a : adj[alice]){
            if( par == a) continue;
            isLeaf = false;
            next = max(next ,  help( a , alice , cnt +1 , adj , dis , amount ));
        }

        if(isLeaf){
            return (dis[alice] == cnt ? (amount[alice] / 2) : dis[alice] < cnt ? 0 : amount[alice] );
        }

        return next + (dis[alice] == cnt ? (amount[alice] / 2) : dis[alice] < cnt ? 0 : amount[alice] )   ;

    }

    bool dfs( int bob ,int par ,  int cnt ,  vector<vector<int>> & adj , vector<int> & dis){
        
        if( bob == 0 ) {
            dis[bob] = cnt;
            return true;
        }
        for(auto & a : adj[bob]){
            if( par == a) continue;
           if(dfs( a ,bob ,  cnt +1 , adj , dis)){
                dis[bob] = cnt;
                return true;
           }
        }

        return false;
    }


public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n = amount.size();

        vector<int> dis( n , n  );
        vector<vector<int>> adj(n );

        for( auto & ed : edges){
            int u = ed[0];
            int v = ed[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs( bob , -1 , 0 , adj , dis);


        // for( auto & a : dis){
        //     cout << a << endl;
        // }

        return help( 0 , -1 , 0 , adj , dis , amount);

        return 0 ;

    }
};