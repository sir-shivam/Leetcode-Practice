class Solution {

    void dfs( int node , vector<vector<int>> & adj , vector<int> & vis , int & v , int & e){
        vis[node] = 1;

        v ++;

        e += adj[node].size();

        for(auto & a : adj[node]){
            if(!vis[a]){
                dfs(a , adj , vis , v , e);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> vis(n , 0 );

        vector<vector<int>> adj( n );

        for(auto & ed : edges){
            int u = ed[0];
            int v = ed[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                int v = 0 ;
                int e = 0 ;

                dfs(i , adj , vis , v , e);
                cout << v << " - " << e << endl;
                if( v == 1){
                    cnt ++;
                }
                else if(v * ( v -1 ) == ( e )){
                    cnt ++;
                }
            }
        }

        return cnt;
    }
};