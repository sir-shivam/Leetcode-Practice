class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        
        int n = coins.size();
        vector<vector<int>> adj( n );
        vector<int> deg( n , 0 );

        for( auto & ed :edges){
            int u = ed[0];
            int v = ed[1];

            adj[u].push_back(v);
            adj[v].push_back( u);

            deg[u] ++;
            deg[v] ++;
        }

        queue<int> q;

        for( int i = 0 ; i < n ; i++){
            if( deg[i] == 1 && coins[i] == 0 ){
                q.push( i );
            }
        }

        while(!q.empty()){

            auto node = q.front();

            q.pop();

            deg[node] --;

            for( int & a : adj[node]){
                if( deg[a] == 0 ) continue;
                deg[a] -- ;

                if( deg[a] == 1 && coins[a] == 0 ){

                    q.push(a);
                }
            }
            
        }

        for( int i = 0 ; i < n ; i++){
            if(deg[i] == 1){
                q.push(i);
            }
        }

        int round = 2;

        while( round --){
            int sz = q.size();

            while(sz --){
                int u = q.front();

                q.pop();
                deg[u] --;

                for( int v : adj[u]){
                    if(deg[v] == 0) continue;

                    deg[v] --;

                    if(deg[v] == 1){
                        q.push(v);
                    }
                }
            }
        }

        int rem = 0 ;
        for( auto & ed : edges){
            if( deg[ed[0]] > 0 && deg[ed[1]] > 0 ){
                rem ++;
            }
        }

        return rem * 2;
    }
};