
// Round Trip :ye variation h cycle detection ki jisme hume kewal ek cycle find pta krni thi




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
  vector<int>parent(N,0);
  vector<vector<int>>cycles;
  int sv=-1,ev=-1;

  bool dfs(int i,int par)
  {
     visited[i]=1;
     parent[i]=par;
     for(auto it:Graph[i])
     {
        if(it==par)continue;
        if(visited[it])
        {
            ev=i;
            sv=it;
            return true;
        }else{
            bool ans=dfs(it,i);
            if(ans)return true;
        }
     }

     return false;
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

   
   bool res = false;

    for(int i=1;i<=n;i++)
    { if(!visited[i])
         { if( dfs(i,i))
            { res=true;
             break;
            }
         }

    
    }

  // cout<<cycles.size()<<endl;

   if(!res){cout<<"IMPOSSIBLE"<<endl;}
   else{
    
     int tv=ev;
     vector<int>ans;
     ans.push_back(ev);
     while(tv!=sv)
     {
        ans.push_back(parent[tv]);
        tv=parent[tv];
     }
     ans.push_back(ev);

     cout<<ans.size()<<endl;
     for(int i=0;i<ans.size();i++){cout<<ans[i]<<" ";}cout<<endl;



   }
   









 
    
 
      return 0;
  }
