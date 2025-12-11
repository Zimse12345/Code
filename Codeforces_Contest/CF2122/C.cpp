#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,f[N];

struct node{
    int v,id;
    node(int v=0,int id=0):v(v),id(id){}
    bool operator < (const node& _)const{return v<_.v;}
}a[N],b[N];
vector<int> g[4];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1,x,y;i<=n;i++){
            cin>>x>>y;
            a[i]=node(x,i);
            b[i]=node(y,i);
            f[i]=0;
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for(int i=1;i<=n/2;i++){
            f[a[i].id]+=1;
            f[b[i].id]+=2;
        }
        for(int i=1;i<=n;i++){
            g[f[i]].push_back(i);
        }
        for(unsigned i=0;i<g[0].size();i++)printf("%d %d\n",g[0][i],g[3][i]);
        for(unsigned i=0;i<g[1].size();i++)printf("%d %d\n",g[1][i],g[2][i]);
        for(int i=0;i<4;i++){
            g[i].resize(0);
        }
    }
    return 0;
}


