

// dijkstra ka question h only dijkstra 



#include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;
  
int N=1e5+10;
   int INF=1e18+10;
   vector<pair<int,int>>G[100010];
    int n1;
    vector<int>dist(N,INF);

   int dijkstra(int source)
   {
       vector<int>visited(N,0);
        vector<int>dist(N,INF);
       set<pair<int,int>>st;
       st.insert({0,source});
         //cout<<"yha aya"<<endl;
       dist[source]=0;
       while(st.size()>0)
       {
           auto node=*st.begin();
           int v=node.second;int node_d=node.first;st.erase(st.begin());
           if(visited[v])continue;
           visited[v]=1;

           for(auto child:G[v])
           {
               int child_v=child.first;
               int wt=child.second;
               if(dist[v]+wt < dist[child_v]){
                   dist[child_v]=dist[v]+wt;
                   st.insert({dist[child_v],child_v});
               }
           }

       }
       
       int mx=-1;
        for(int i=1;i<=n1;i++)
        {  cout<<dist[i]<<" ";
            mx=max(mx,dist[i]);
        }


     return mx;

   } 

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
   
   int n,m; 
   cin>>n>>m;n1=n;
   map<pair<int,int>,int>mp;
   for(int i=0;i<m;i++)
   {
      int a,b,c;
      cin>>a>>b>>c;
      if(mp[{a,b}])
      mp[{a,b}]=min(mp[{a,b}],c);
      else
        mp[{a,b}]=c;
   }


   for(auto it :mp)
   {
      G[it.first.first].push_back({it.first.second,it.second});
   }

    int y=dijkstra(1);
    // for(int i=1;i<=n1;i++)
    // {
    //     cout<<dist[i]<<" ";
    // }cout<<endl;






   
        return 0;
}
