#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],b[N],S,T;
map<int,int> dis;
queue<int> q;

inline int f(vector<int> w){
    vector<int> vis(n+1,0);
    int num=0,res=0;
    for(int i=1;i<=n;i++){
        if(!vis[w[i]])vis[w[i]]=++num;
    }
    for(int i=1;i<=n;i++)res=res*10+vis[w[i]];
    return res;
}

signed main(){
    freopen("socialin.txt","r",stdin);
    freopen("socialout.txt","w",stdout);
    
    cin>>n;
    int cnt=0,id=0;
    vector<int> w(n+1,0);
    while(cnt<n){
        int x=0;
        ++id;
        cin>>x;
        while(x!=0){
            ++cnt;
            w[x]=id;
            cin>>x;
        }
    }
    S=f(w);
    cnt=0,id=0;
    while(cnt<n){
        int x=0;
        ++id;
        cin>>x;
        while(x!=0){
            ++cnt;
            w[x]=id;
            cin>>x;
        }
    }
    T=f(w);
    q.push(S),dis[S]=0;
    while(!q.empty()){
        int u=q.front(),_u=u;
        q.pop();
        if(u==T)break;
        vector<int> t[n+1],_w;
        for(int i=n;i>=1;i--)w[i]=u%10,u/=10,t[w[i]].push_back(i);
        for(int i=1;i<=n;i++)if(t[i].size())sort(t[i].begin(),t[i].end());
        for(int i=1;i<=n;i++)if(t[i].size()){
            for(int j=i+1;j<=n;j++)if(t[j].size()){
                _w=w;
                for(unsigned p=0;p<t[j].size();p++)_w[t[j][p]]=i;
                int v=f(_w);
                if(!dis[v])dis[v]=dis[_u]+1,q.push(v);
                
                _w=w;
                swap(_w[t[i][0]],_w[t[j][t[j].size()-1]]);
                v=f(_w);
                if(!dis[v])dis[v]=dis[_u]+1,q.push(v);
                
                _w=w;
                swap(_w[t[i][t[i].size()-1]],_w[t[j][0]]);
                v=f(_w);
                if(!dis[v])dis[v]=dis[_u]+1,q.push(v);
            }
            _w=w;
            for(unsigned j=0;j<=(t[i].size()-1)/2;j++)_w[t[i][j]]=n;
            int v=f(_w);
            if(!dis[v])dis[v]=dis[_u]+1,q.push(v);
        }
    }
    printf("%d\n",dis[T]);
    return 0;
}


