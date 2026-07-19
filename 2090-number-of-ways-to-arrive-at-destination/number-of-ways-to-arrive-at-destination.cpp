#define p pair< long long , int> 
class Solution {

    int const MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // int n = roads.size();
        vector<vector<pair< int , int>>> adj(n);

        for(auto r : roads){
            int u = r[0];
            int v = r[1];
            int w = r[2];

            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }

        priority_queue< p , vector<p> , greater<p>> pq;

        pq.push({0 , 0 });

        vector<pair< long long , int>> node( n , {LLONG_MAX , 0});

        node[0].first = 0;
        node[0].second = 1;

        while(!pq.empty()){
            auto [x , y] = pq.top();
            pq.pop();

            for( auto [a , w] : adj[y]){
                
                if((long long)w + x < node[a].first ){
                    node[a].first = w+x;
                    node[a].second = node[y].second;
                    pq.push({w+x , a});
                }else if( w+x == node[a].first){
                    node[a].second = (node[y].second + node[a].second) % MOD;
                }

                
            }

        }

        return node[n-1].second;


    }
};