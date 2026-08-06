using pp = tuple< long long  , int , int> ;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair< int , int>>> adj( n );

        for( auto & ed : edges){
            int u = ed[0];
            int v = ed[1];

            int w = ed[2];

            adj[u].push_back({v , w });
        }

        int const INF = 1e9 ;

        vector<vector<long long >> dis( n , vector<long long > (  k+1 , INF )) ;

        priority_queue<pp, vector<pp> , greater<pp>> pq;

        pq.push({ 0 , 1 , 0  });

        while(!pq.empty()){

            auto [ d , cnt  , node] = pq.top();

            pq.pop();

            if( d > dis[node][cnt]) continue;
            if( node == n-1) return d;

            for(auto & [a , w] : adj[node]){

                int nxtCnt = (labels[a] == labels[node]) ? cnt +1 : 1 ;
                if( nxtCnt > k ) continue;

                long long nd = d + w ;

                if( nd  < dis[a][nxtCnt]){
                        dis[a][nxtCnt] = 1LL *  nd  ;
                        pq.push({ nd , nxtCnt , a});
                }

            }
        }


        long long  ans = INF;
        for( int i = 0 ; i <= k   ; i++){
            if( dis[n-1][i] == INF ) continue;
            ans = min(dis[n-1][i] , ans );
        }


        return ans == INF ? -1 : ans;

    }
};