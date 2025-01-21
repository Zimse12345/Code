#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int read(){int x=0,y=1;char c=getchar();
while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

int T,n,q,a[N],b[N],sum;

struct node{
    int v,id;
    node(int v=0,int id=0):v(v),id(id){}
    bool operator < (const node& _)const{return v<_.v;}
}p[2][N];
int rk[2][N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>a[i],p[0][i]=node(a[i],i);
        for(int i=1;i<=n;i++)cin>>b[i],p[1][i]=node(b[i],i);
        sort(p[0]+1,p[0]+n+1);
        sort(p[1]+1,p[1]+n+1);
        sum=1;
        for(int i=1;i<=n;i++){
            (sum*=min(p[0][i].v,p[1][i].v))%=Mod;
            rk[0][p[0][i].id]=i;
            rk[1][p[1][i].id]=i;
        }
        printf("%lld ",sum);
        while(q--){
            int o,x;
            cin>>o>>x;
            --o,x=rk[o][x];
            int L=1,R=n,y=n;
            while(L<=R){
                int M=(L+R)/2;
                if(p[o][M].v<=p[o][x].v)y=M,L=M+1;
                else R=M-1;
            }
            swap(p[o][x].id,p[o][y].id);
            swap(rk[o][p[o][x].id],rk[o][p[o][y].id]);
            (sum*=fpow(min(p[0][y].v,p[1][y].v)))%=Mod;
            ++p[o][y].v;
            (sum*=min(p[0][y].v,p[1][y].v))%=Mod;
            printf("%lld ",sum);
        }
        printf("\n");
    }
    return 0;
}


