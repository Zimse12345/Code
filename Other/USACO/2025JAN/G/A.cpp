#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
const long long inf=1e18;
int n,a[N],c[N],q,m[N],v[N],C[3][3][3];
long long ans[N],f[N][3];

int read(){
    int x=0,y=1;
    char c=getchar();
    while(c<48||57<c){
        if(c==45)y=-1;
        c=getchar();
    }
    while(47<c&&c<58)x=x*10+c-48,c=getchar();
    return x*y;
}

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
}p[N],qr[N];

inline int Mid(int x,int y,int z){
    if(y<x)swap(x,y);
    if(z<y)swap(y,z);
    if(y<x)swap(x,y);
    return y;
}

inline void calc(int u){
    if(u*2>n){
        f[u][0]=f[u][1]=f[u][2]=c[u];
        f[u][v[u]+1]=0;
        return;
    }
    f[u][0]=f[u][1]=f[u][2]=inf;
    int l=u*2,r=u*2+1,mid=0;
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            for(int z=0;z<3;z++){
                mid=C[x][y][z];
                f[u][mid]=min(f[u][mid],f[l][y]+f[r][z]+(v[u]+1==x?0:c[u]));
            }
        }
    }
    return;
}

void upt(int u,int val){
    v[u]=val;
    while(u){
        calc(u);
        u/=2;
    }
    return;
}

signed main(){
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            for(int z=0;z<3;z++){
                C[x][y][z]=Mid(x,y,z);
            }
        }
    }
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read(),c[i]=read();
        p[i]=node(a[i],i);
        v[i]=1;
    }
    sort(p+1,p+n+1);
    for(int i=n;i>=1;i--)calc(i);
    q=read();
    for(int i=1;i<=q;i++){
        m[i]=read();
        qr[i]=node(m[i],i);
    }
    sort(qr+1,qr+q+1);
    for(int i=1,l=0,r=0;i<=q;i++){
        while(l<n&&p[l+1].x<qr[i].x){
            ++l,upt(p[l].y,-1);
        }
        r=max(r,l);
        while(r<n&&p[r+1].x==qr[i].x){
            ++r,upt(p[r].y,0);
        }
        ans[qr[i].y]=f[1][1];
    }
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return 0;
}


