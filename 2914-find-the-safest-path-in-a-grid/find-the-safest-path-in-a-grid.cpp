class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    bool possible(vector<vector<int>>& dist,int val){
        int n=dist.size();

        if(dist[0][0]<val) return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));

        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            if(x==n-1 && y==n-1)
                return true;

            for(auto &[dx,dy]:dir){
                int nx=x+dx;
                int ny=y+dy;

                if(nx<0||ny<0||nx>=n||ny>=n)
                    continue;

                if(vis[nx][ny])
                    continue;

                if(dist[nx][ny]<val)
                    continue;

                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n=grid.size();

        vector<vector<int>> dist(n,vector<int>(n,-1));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            auto [x,y]=q.front();
            q.pop();

            for(auto &[dx,dy]:dir){
                int nx=x+dx;
                int ny=y+dy;

                if(nx<0||ny<0||nx>=n||ny>=n)
                    continue;

                if(dist[nx][ny]!=-1)
                    continue;

                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }

        int low=0;
        int high=2*n;
        int ans=0;

        while(low<=high){

            int mid=(low+high)/2;

            if(possible(dist,mid)){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }

        return ans;
    }
};