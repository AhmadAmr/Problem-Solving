#include <bits/stdc++.h>

using namespace std;
const int N = 2e3+5, M = 1e5+5, OO = (int)1E9;

int n, m, srcR, srcC,nn=0,s=0,p=0;
string a,b;
int grid[9][9];
int dr[] = {2, 1, 2, 1,  -1, -2, -1, -2};
int dc[] = {1, 2, -1, -2, 2, 1, -2, -1};
bool valid(int r, int c){
  return r >= 0 && r < 8 && c >= 0 && c < 8 ;
}

void BFS(int srcR, int srcC){

  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
        grid[i][j]=OO;
  grid[srcR][srcC] = 0;
  queue<pair<int, int> > q;
  q.push({srcR, srcC});
  while(!q.empty()){
    int ur = q.front().first, uc = q.front().second;
    q.pop();
    for(int k = 0 ; k < 8 ; ++k){
      int nr = (ur + dr[k]), nc = uc + dc[k];
      if(valid(nr,nc)&& grid[nr][nc] == OO ){
        grid[nr][nc] = grid[ur][uc]+1;
        q.push({nr, nc});
      }
    }
  }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
    cin>>a>>b;
  int r=a[1]-'1';
  int c=a[0]-'a';
  int row=b[1]-'1';
  int col=b[0]-'a';
  BFS(r,c);
  cout<<grid[row][col]<<endl;
 }
 return 0;
}
