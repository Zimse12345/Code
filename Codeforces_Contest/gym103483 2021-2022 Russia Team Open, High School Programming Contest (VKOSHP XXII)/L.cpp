#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define int long long
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid (Lid|1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=1e9+7,INF=1e12;
int n,m,k,a[N],b[N],sum[N],ss[N],v[N],s[N*4],c[N],cc[N],t,ans;
int stk[N],top,LL[N],RR[N];
struct node{
    int pos,val;
    node(int pos=0,int val=0):pos(pos),val(val){}
    bool operator < (const node& A)const{return val<A.val;}
}p[N];
vector<int> pos[N];

void build(int id,int L,int R){
    if(L==R)s[id]=v[L];
    else build(Lid,L,M),build(Rid,M+1,R),s[id]=min(s[Lid],s[Rid]);
    return;
}

int query(int id,int L,int R,int l,int r){
    if(R<l||r<L)return INF;
    if(l<=L&&r>=R)return s[id];
    return min(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    n=read(),k=read();
    for(int i=1;i<=n;i++){
        a[i]=read(),b[i]=read();
        if(a[i]<b[i])swap(a[i],b[i]);
        ans=(ans+a[i]*i%Mod*(n-i+1))%Mod;
        if(a[i]%k==b[i]%k)v[i]=INF;
        else v[i]=a[i]-b[i];
    }
    build(1,1,n);
    for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+a[i])%k,ss[i]=ss[i-1]+a[i];
    for(int i=0;i<=n;i++)p[i]=node(i,sum[i]);
    sort(p,p+n+1);
    for(int i=0;i<=n;i++){
        if(i==0||p[i].val!=p[i-1].val)++m;
        sum[p[i].pos]=m;
    }
    for(int i=0;i<=n;i++)pos[sum[i]].push_back(i);
    for(int i=1;i<=m;i++){
        t=0;
        for(int j=1;j<signed(pos[i].size());j++){
            c[++t]=query(1,1,n,pos[i][j-1]+1,pos[i][j]);
            cc[t]=ss[pos[i][j]]-ss[pos[i][j-1]];
        }
        top=0;
        stk[++top]=0,c[0]=-INF;
        for(int j=1;j<=t;j++){
            while(top&&c[j]<c[stk[top]])--top;
            LL[j]=stk[top],stk[++top]=j;
        }
        top=0;
        stk[++top]=t+1,c[t+1]=-INF;
        for(int j=t;j>=1;j--){
            while(top&&c[j]<=c[stk[top]])--top;
            RR[j]=stk[top],stk[++top]=j;
            if(c[j]!=INF)ans=(ans-c[j]*(j-LL[j])%Mod*(RR[j]-j))%Mod;
        }
        for(int j=1;j<=t;){
            if(c[j]==INF){
                int k=j;
                while(k<t&&c[k+1]==INF)++k;
                for(int w=j;w<=k;w++)ans=(ans-cc[w]*(w-j+1)%Mod*(k-w+1)%Mod)%Mod;
                j=k+1;
            }
            else ++j;
        }
    }
    ans=(ans+Mod)%Mod;
    printf("%lld\n",ans);
    return 0;
}
