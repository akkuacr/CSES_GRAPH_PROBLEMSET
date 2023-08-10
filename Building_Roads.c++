// isme mera intution ye tha ki sbke parent nikal lo lo aur unhe aapas m connect kr lo bss

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
  vector<int>visited(N,0);
  map<int,int>mp;
     vector<int>parent(N,-1);
 
  void dfs(int i,int par)
  {
 
       visited[i]=1;parent[i]=par;
       for(auto it:Graph[i])
       {
          if(!visited[it])
          {
            dfs(it,par);
          }
       }
      
      return;
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
        Graph[x].pb(y);
        Graph[y].push_back(x);
   }
   
 
   for(int i=1;i<=n;i++)
   {
         if(!visited[i])
         {
            dfs(i,i);
         }
   }
   
 
   for(int i=1;i<=n;i++)
   {
       mp[parent[i]]++;
   }
 
 
 
    cout<<mp.size()-1<<endl;
    vector<int>vec;
    if(mp.size()>1){
    for(auto it:mp)
    {
       vec.push_back({it.first});
    }}
 
    if(vec.size()>1)
    {
        for(int i=0;i<vec.size()-1;i++)
        {
            cout<<vec[i]<<" "<<vec[i+1]<<endl;
        }
 
    }
 
   
 
    
 
      return 0;
  }
