#include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;
  const int N=1010;
 
  vector<char>G[N];
  int n,m;
   vector<vector<int>>visited(N,vector<int>(N,0));
 
   void dfs(int i,int j)
  {
      if((i>=n) || (j>=m)||(i<0)||(j<0))
      {
        return;
 
      }
 
      if(G[i][j]=='#')
      {
        return;
      }
 
      visited[i][j]=1;;
 
      vector<int>x={-1,1,0,0};
      vector<int>y={0,0,-1,1};
      for(int k=0;k<4;k++)
      {
           int i1=i+x[k];int j1=j+y[k];
           if(((i1<n) && (i1>=0))&&((j1<m )&& (j1>=0)))
             { if(!visited[i1][j1]) 
                 {
                    dfs(i1,j1);
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
 
 
   
   cin>>n>>m;
  // memset(visited,0,sizeof(visited));
 
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         char x;
         cin>>x;
         G[i].push_back(x);
      }
   }
 
   int count=0;
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<m;j++)
        {
            if(G[i][j]=='.')
            {  
                if(!visited[i][j])
                { count++;
                    dfs(i,j);
                }
            }
        }
   }
   
   cout<<count<<endl;
 
   
 
 
      return 0;
  }
