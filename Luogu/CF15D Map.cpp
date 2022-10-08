/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-26
*Description:
*Other:
********************************/

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
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define ll long long
#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1024;

int n,m,a,b,val[N][N],presum[N][N],sum[N][N],lmin[N][N],mn[N][N];
int que[N],L,R,cost[N][N],vis[N][N];

struct node{
    int v,x,y;
    node(int v=0,int x=0,int y=0):v(v),x(x),y(y){}
    bool operator < (const node& _)const{
        if(v==_.v){
            if(x==_.x){
                return y>_.y;
            }
            return x>_.x;
        }
        return v>_.v;
    }
    bool operator == (const node& _)const{
        return v==_.v&&x==_.x&&y==_.y;
    }
};

priority_queue<node> q;
vector<node> ans;

signed main(){
    n=read(),m=read(),a=read(),b=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            val[i][j]=read();
            presum[i][j]=val[i][j]+presum[i][j-1]+presum[i-1][j]-presum[i-1][j-1];
        }
    }
    for(int i=1;i+a-1<=n;i++){
        for(int j=1;j+b-1<=m;j++){
            sum[i][j]=presum[i+a-1][j+b-1]-presum[i+a-1][j-1]-presum[i-1][j+b-1]+presum[i-1][j-1];
            // printf("sum[%d][%d]=%d\n",i,j,sum[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        L=1,R=0;
        for(int j=1;j<=m;j++){
            while(L<=R&&que[L]<=j-b)++L;
            while(L<=R&&val[i][j]<val[i][que[R]])--R;
            que[++R]=j;
            if(j-b+1>0)lmin[i][j-b+1]=val[i][que[L]];
            // printf("lmin[%d][%d]=%d j=%d\n",i,j-b+1,lmin[i][j-b+1],j);
        }
    }
    for(int j=1;j+b-1<=m;j++){
        L=1,R=0;
        for(int i=1;i<=n;i++){
            while(L<=R&&que[L]<=i-a)++L;
            while(L<=R&&lmin[i][j]<lmin[que[R]][j])--R;
            que[++R]=i;
            if(i-a+1>0)mn[i-a+1][j]=lmin[que[L]][j];
            // printf("min[%d][%d] = %d\n",i-a+1,j,mn[i-a+1][j]);
        }
    }
    for(int i=1;i+a-1<=n;i++){
        for(int j=1;j+b-1<=m;j++){
            cost[i][j]=sum[i][j]-mn[i][j]*a*b;
            q.emplace(cost[i][j],i,j);
            // printf("cost(%d,%d)=%d\n",i,j,cost[i][j]);
        }
    }
    while(!q.empty()){
        ans.push_back(q.top());
        // printf("[%lld]\n",q.top().v);
        int x=q.top().x,y=q.top().y;
        vis[x][y]=1;
        q.pop();
        for(int i=max(x-a+1,1ll);i<=min(x+a-1,n-a+1);i++){
            for(int j=max(y-b+1,1ll);j<=min(y+b-1,m-b+1);j++){
                vis[i][j]=1;
            }
        }
        while(!q.empty()&&vis[q.top().x][q.top().y])q.pop();
    }
    printf("%u\n",ans.size());
    for(unsigned i=0;i<ans.size();i++)printf("%lld %lld %lld\n",ans[i].x,ans[i].y,ans[i].v);
    return 0;
}
