#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int parent[N];
int size[N];

void make(int v)
{
 parent[v]=v;
 size[v]=1;
}

int find(int v)
{
 if(v==parent[v])
  return v;
 parent[v]=find(parent[v]);
 return parent[v];
 
}

void Union(int a,int b)
{
 a=find(a);
 b=find(b);
 if(a!=b)
 {
   if(size[a]<size[b])
     swap(a,b);
     parent[b]=a;
   size[a]=size[a]+size[b];
 }
}

int main()
{ 
 int ver,ed;
 cout<<"enter vertices and edges"<<endl;
 cin>>ver>>ed;
 vector<pair<int,pair<int,int>>>vec;
 for(int i=0;i<ed;i++)
 {
   int u,v,wt;
   cout<<"enter edges and weight="<<endl;
   cin>>u>>v>>wt;
   vec.push_back({wt,{u,v}});
  }
sort(vec.begin(),vec.end());
for(int i=1;i<=ver;i++)
{
 make(i);
}
int totalcost=0;
for(auto &a:vec)
{
  int u,v,wt;
  wt=a.first;
  u=a.second.first;
  v=a.second.second;
if(find(u)==find(v))
 continue;
 Union(u,v);
totalcost=totalcost+wt;
cout<<u<<" "<<v<<endl;
}
cout<<totalcost<<endl;
}
  
 
