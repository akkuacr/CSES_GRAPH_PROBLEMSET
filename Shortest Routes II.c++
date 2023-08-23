





// ye floyd warshall ki variation h






#include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;
   
   const int N=510;

   int INF=1e18+10;
    
   int dist[510][510];    

  

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
   
    



    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {   if(i==j)
            dist[i][j]=0;
            else
                dist[i][j]=INF;
        }
    }

    int n,m,q;cin>>n>>m>>q;
    map<pair<int,int>,int>mp;
    for(int i=0;i<m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
       if( mp[{a,b}])mp[{a,b}]=min(mp[{a,b}],c);
       else mp[{a,b}]=c;
         
    }//cout<<"yes"<<endl;
    

    for(auto it:mp){

        dist[it.first.first][it.first.second]=min(dist[it.first.first][it.first.second],it.second);
        dist[it.first.second][it.first.first]=min(dist[it.first.first][it.first.second],it.second);
    }


    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }

        }

    }

    while(q--)
    {
        int x,y;cin>>x>>y;
        if(dist[x][y]==INF)cout<<"-1"<<endl;
        else
        cout<<dist[x][y]<<endl;

    }









   
        return 0;
}
