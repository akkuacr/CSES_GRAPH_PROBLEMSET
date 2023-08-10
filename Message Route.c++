   #include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;
  
  const int N=1e5+10;
  const int INF=1e9+10;
  vector<int>Graph[N];
  vector<int>visited(N,INF);
  vector<int>dist(N,INF);
  vector<int>parent(N,-1);

  void bfs(int i)
  {

        visited[i]=1;
        queue<int>q;
        q.push(i);
        dist[i]=0;
        while(q.size()>0)
        {
            int tp=q.front();
            q.pop();
             

            for(auto it:Graph[tp])
            {
                if((dist[tp]+1)<dist[it])
                {
                    q.push(it);
                    dist[it]=dist[tp]+1;
                    parent[it]=tp;
                }
            }
          
        }
  }





  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif
  




  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    Graph[x].push_back(y);
    Graph[y].push_back(x);
  }


  bfs(1);

  if(dist[n]>=INF)
  {
    cout<<"IMPOSSIBLE"<<endl;
  }else{

  
      cout<<dist[n]+1<<endl;
      vector<int>res;
      // for(int i=0;i<=n;i++)
      // {
      //   cout<<parent[i]<<" ";
      // }cout<<endl;
      while(n!=-1)
      {
         res.push_back(n);n=parent[n];
      }
      reverse(res.begin(),res.end());
      for(int i=0;i<res.size();i++)
      {
        cout<<res[i]<<" ";
      }cout<<endl;
   }
 
    
 
      return 0;
  }
