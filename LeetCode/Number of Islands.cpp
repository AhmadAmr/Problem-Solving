class Solution {
public:
 
    
     bool valid(int r, int c,int n,int m){
     return r >= 0 && r < n && c >= 0 && c < m;
     }
    void BFS(int srcR, int srcC,vector<vector<char>>& grid,bool (*vis)[500]){
        int n=grid.size();
        int m=grid[0].size();
    int dr[] = {0,0 ,1,-1};
    int dc[] = {1,-1,0,0};
  grid[srcR][srcC] = 0;
  queue<pair<int, int> > q;
  q.push({srcR, srcC});
    vis[srcR][srcC]=true;
  while(!q.empty()){
    int ur = q.front().first, uc = q.front().second;
    q.pop();
    for(int k = 0 ; k < 4 ; ++k){
      int nr = ur + dr[k], nc = uc + dc[k];
      if(valid(nr, nc,n,m) && !vis[nr][nc] && grid[nr][nc]=='1'){
       // grid[nr][nc] = grid[ur][uc]+1;
        q.push({nr, nc});
          vis[nr][nc]=true;
      }
    }
  }
}
     
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
       int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        bool vis[500][500]={};
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
               if(!vis[i][j] && grid[i][j]=='1'){
                  ans++;
                BFS(i,j,grid,vis);
            }
        return ans;
      }
   

};
