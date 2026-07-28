class Solution {

    bool help(int node , vector<vector<int>> & adj , vector<int> & vis , vector<int> & visDfs){

        if(visDfs[node]) return false;

        if (vis[node]) return true;

        vis[node] = 1;
        visDfs[node] = 1;

        for(auto & a : adj[node]){
            if(!help(a , adj , vis , visDfs)){
                return false;
            }
        }
        
        visDfs[node] = 0 ;
        return true;

    }
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        
        // lets try dfs 
        vector<int> vis( num , 0 );
        vector<int> visDfs( num , 0 );

        vector<vector<int>> adj( num );

        for(auto & ed : pre){
            int u = ed[0];
            int v = ed[1];

            adj[u].push_back(v);
        }

        for( int i = 0 ; i < num ; i++){
            if(vis[i] == 0 ){
                if(!help( i , adj , vis , visDfs)){
                    return false; 
                }
            }
        }

        return true;

        
        
    }
};