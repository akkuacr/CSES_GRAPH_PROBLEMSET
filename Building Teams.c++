
// ye ek bipartite ki variation h jisme hum ye dekhte  h ki qa hum graph ko different color se color kr skte h qa




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
  vector<int>Graph[N];
  vector<int>color(N,0);
  vector<int>visited(N,0);

  bool dfs(int i,int col,int par)
  {

       color[i]=col;
       for(auto it:Graph[i])
       {
          if(!color[it])
          {
            bool ans=dfs(it,3-(col%3),i);
            if(!ans){return false;}
          }else{

            if((color[it]==color[i]))
            {
                return false;
            }
          }
       }
      
      return true;
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
      int x,y;cin>>x>>y;
      Graph[x].push_back(y);
      Graph[y].push_back(x);
   }

   
   bool res =true;

  for (int i = 1; i <=n; ++i)
  {  if(!color[i])
     res=dfs(i,1,-1);
  }







   if(!res){cout<<"IMPOSSIBLE"<<endl;}
   else{
    for(int i=1;i<=n;i++)
    {
        cout<<color[i]<<" ";
    }cout<<endl;
   }


 
    
 
      return 0;
  }
