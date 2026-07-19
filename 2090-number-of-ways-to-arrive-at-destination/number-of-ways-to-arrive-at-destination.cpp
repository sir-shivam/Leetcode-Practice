using pp = tuple<long long  , int > ;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7 ;

        vector<vector<pair<int , int>>> adj( n );

        for( auto & r : roads){
            int u = r[0];
            int v = r[1];
            int w = r[2];

            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }
        
        vector<pair<int , long long >> dist(n , { 0 , LLONG_MAX});


        priority_queue<pp , vector<pp> , greater<pp>> pq;




        pq.push({ 0 , 0  });
        dist[0].second = 0 ;
        dist[0].first = 1;

        while( !pq.empty()){
            auto [ d , node  ] = pq.top();

            pq.pop();
             if (d > dist[node].second)
        continue;

            for( auto & [a , w ] : adj[node]){

                if( (long long )w + d < dist[a].second){
                    dist[a].second = w + d;
                    dist[a].first = dist[node].first;
                    pq.push({dist[a].second, a});
                }else if((long long ) w + d == dist[a].second){
                    dist[a].first = (dist[a].first +dist[node].first) %MOD;
                    // dist[a].first %= MOD;
                    // pq.push({ w + d , a });
                }
            }
        }

        // cout << dist[n-1].second;

        return dist[n-1].first;

    }
};