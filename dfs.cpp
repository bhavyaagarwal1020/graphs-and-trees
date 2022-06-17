#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>g[N];
int visited[N];
void dfs(int vertex)
{
  cout<<vertex<<endl;
 visited[vertex]=1; //take action on vertex before entering child.
 
 for(int child:g[vertex])
 {
  cout<<"parent: "<<vertex<<" and child: "<<child<<endl;
  if(visited[child]==1)
   continue;
  
   dfs(child);
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
 dfs(1);
}
