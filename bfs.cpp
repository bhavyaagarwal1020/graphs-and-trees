#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>g[N];
int visited[N];
int level[N];

void bfs(int source)
{
 queue<int>q;
 q.push(source);
 visited[source]=1;
 while(q.empty()==false)
 {
  int curver=q.front();
  q.pop();
  cout<<curver<<" ";
  for(int child:g[curver])
  {
   if(visited[child]==0)
   {
     q.push(child);
     visited[child]=1;
     level[child]=level[curver]+1;
   }
  }
}
} 

int main()
{
 int v,e;
 cout<<"enter number of vertices and edges="<<endl;
 cin>>v>>e;
 for(int i=0;i<e;i++)
 {
  int x,y;
  cout<<"enter edges="<<endl;
  cin>>x>>y;
  g[x].push_back(y);
  g[y].push_back(x);
 }
 bfs(1);
 for(int i=1;i<v;i++)
 {
  cout<<i<<": level= "<<level[i]<<endl;
 }
}
