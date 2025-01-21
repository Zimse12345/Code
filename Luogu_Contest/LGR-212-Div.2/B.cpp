#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,m,fa[N];
set<int> E;

inline int eg(int u,int v){
    if(v<u)swap(u,v);
    return u*(n+1)+v;
}

inline int F(int x){
    if(fa[x]!=x)fa[x]=F(fa[x]);
    return fa[x];
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    if(!m){
        printf("No\n");
        return 0;
    }
    int U=0,V=0;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        E.insert(eg(u,v));
        U=u,V=v;
        u=F(u),v=F(v);
        if(u==v){
            printf("No\n");
            return 0;
        }
        fa[v]=u;
    }
    for(int i=1;i<=n;i++)if(i!=U&&i!=V&&F(i)!=F(U)){
        E.erase(eg(U,V));
        E.insert(eg(U,i));
        E.insert(eg(i,V));
        V=i,fa[F(i)]=U;
    }
    printf("Yes\n");
    for(set<int>::iterator it=E.begin();it!=E.end();it++){
        int u=(*it)/(n+1),v=(*it)%(n+1);
        printf("%lld %lld\n",u,v);
    }
    return 0;
}


