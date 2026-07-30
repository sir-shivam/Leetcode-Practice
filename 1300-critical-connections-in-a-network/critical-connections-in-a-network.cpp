class Solution {

    int timer = 1;

    vector<vector<int>> ans;

    void dfs(int node , int par , vector<vector<int>> & adj , vector<pair<int , int>> & time ){

        
        time[node] = {timer , timer};
        timer ++;

        for(auto & a : adj[node]){
            if(a == par ) continue;
            if(time[a].first == -1){
                dfs( a , node , adj , time);

                time[node].second = min(time[node].second , time[a].second);
                if(time[a].second > time[node].first ){
                    ans.push_back({ a , node});
                }
            }else{
                time[node].second = min(time[node].second , time[a].second);
            }
        }

    }


public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj( n );

        vector<pair<int , int>>  time( n , {-1 , -1});

        for(auto & ed : connections){
            int u = ed[0];
            int v = ed[1];

            adj[u].push_back( v );
            adj[v].push_back(u );
        }

        dfs(0 , -1 , adj , time);

        return ans;

    }
};