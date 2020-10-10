// find tree diameter using BFS twice !! 



#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5, M = 1e5+5, OO = (int)0x3f3f3f3f;
vector<int>adj[N];
int n, m,mx=0,node=0;
int dis[N];


void BFS(int s)
{
    memset(dis,OO,sizeof dis);
    mx=node=0;
    dis[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
       int u = q.front();
       q.pop();
       for(int v : adj[u])
       {
           if(dis[v] == OO){
             q.push(v);
            dis[v]=dis[u]+1;
            if(dis[v]>mx){
                mx=dis[v];
                node=v;
            }
        }
      }
    }

}

int main(){
  int u,v;
  cin>>m;
  for(int i=1;i<m;i++){
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  BFS(1);
  BFS(node);
  cout<<mx<<endl;
}
