class Solution {

    bool help( int per ,int gr ,  vector<vector<int>>& adj  , vector<int>  & group ){


        if(group[per] != 0 ){
            return gr == group[per];
        }

        group[per] = gr;

        for( auto & a : adj[per]){
            if(!help( a , gr == 1 ? 2 : 1 , adj  , group ) ){
                return false;
            }
        }

        return true;

    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> group( n+1 , 0 );

        vector<vector<int>> adj( n +1);

        for( auto & ed : dislikes){
            int u = ed[0];
            int v = ed[1];

            adj[u].push_back( v );
            adj[v].push_back(u);
        }

        for( int i = 0 ; i < n ; i++){
            if( group[i] == 0  ){
                if(!help( i , 1 , adj  , group)){
                    return false;
                }
            }
        }

        return true;
    }
};