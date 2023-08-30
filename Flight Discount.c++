// it is something like range query using dijkstra




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
   vector<pair<int,int>>G1[100010],G2[100010];
    int n1;
    vector<int>dp(N,0);
     

   int dijkstra(int source,vector<int>&dist,vector<pair<int,int>>* G)
   {
       vector<int>visited(N,0); 
         
       set<pair<int,int>>st;
       st.insert({0,source});
         
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
               if((dist[v]+wt) < dist[child_v]){
                   dist[child_v]=dist[v]+wt;
                   dp[child_v]=max(dp[v],wt);
                   st.insert({dist[child_v],child_v});
               }else if((dist[v]+wt)==dist[child_v])
               {
                 dp[child_v]=max(dp[child_v],max(dp[v],wt));
               }
           }

       }
       
       int mx=-1;
        for(int i=1;i<=n1;i++)
        {
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
  cin>>n>>m;
   vector<int>dist1(N,INF),dist2(N,INF);
   vector<vector<int>>edges;


  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    G1[a].push_back({b,c});
    G2[b].push_back({a,c});
    edges.push_back({a,b,c});
  }

 int y= dijkstra(1,dist1,G1);
 y=dijkstra(n,dist2,G2);
 
int mx=INF;
 for(int i=0;i<edges.size();i++)
 {

    int a=edges[i][0],b=edges[i][1],c=edges[i][2];
   // cout<<a<<" "<<dist1[a]<<" "<<b<<" "<<dist2[b]<<" "<<c<<endl;

    mx=min(mx,dist1[edges[i][0]]+dist2[edges[i][1]]+edges[i][2]/2);
       
 }

 cout<<mx<<endl;


     return 0;
 }



























 
