class Solution {

    void help( int node , vector<vector<int>> & adj , vector<int> & faulty ){
        if(faulty[node]) return ;
        faulty[node] =1 ;

        for(auto & a : adj[node]){
            help( a , adj , faulty);
        }
    }


    bool dfs( int node , vector<vector<int>> & adj , vector<int> & vis , vector<int> & faulty){
        

        if(vis[node]) return false;
        vis[node] = 1;


        if( faulty[node]) return true;

        for(auto & a : adj[node] ){
            if(dfs(a , adj , vis , faulty)){
                return true;
            }
        }

        return false;
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj( n );
        vector<int> faulty( n , 0 );
        vector<int> inDeg( n  , 0 );

        for( auto &  ed : invocations ){
            int u = ed[0];
            int v = ed[1];

            adj[u].push_back(v);

        }


        
        help( k , adj , faulty);

        vector<int> vis( n , 0 );

        bool all = false;
        for(auto a = 0 ; a < n ; a++ ){

            if(faulty[a] == 0 && vis[a] == 0 ){
                if(dfs( a , adj , vis ,  faulty )){
                    all = true;
                    break;
                }
            }
        }

        vector<int> ans;

        for( int i = 0 ; i < n ; i++){
            if(all || faulty[i] == 0){
                ans.push_back( i );
            }
        }

        return ans;;
    }
};