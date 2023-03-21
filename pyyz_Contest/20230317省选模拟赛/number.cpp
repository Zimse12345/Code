/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define ll long long
//#define int long long
// #define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=410000;
int n,r0[N],r9[N],R0[N],R9[N],num[N],mn[N];
int w[N],_num[N],_mn[N];
ll ans;
char str[N];
struct SA{
int m,height[N],x[N],y[N],sa[N],rk[N],c[N];
char s[N];

inline void SA_init(){
    m=128;
    return;
}

inline void Get_SA(){
    for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
    for(int i=2;i<=m;i++)c[i]+=c[i-1];
    for(int i=n;i>0;i--)sa[c[x[i]]--]=i;
    for(int k=1;k<=n;k<<=1){
        int it=0;
        for(int i=n-k+1;i<=n;i++)y[++it]=i; 
        for(int i=1;i<=n;i++)if(sa[i]>k)y[++it]=sa[i]-k;
        for(int i=1;i<=m;i++)c[i]=0;
        for(int i=1;i<=n;i++)c[x[i]]++;
        for(int i=2;i<=m;i++)c[i]+=c[i-1];
        for(int i=n;i>0;i--)sa[c[x[y[i]]]--]=y[i],y[i]=0;
        swap(x,y),it=1,x[sa[1]]=1;
        for(int i=2;i<=n;i++){
            if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])x[sa[i]]=it;
            else x[sa[i]]=++it;
        }
        if(it==n)break;
        m=it;
    }
    return;
}

inline void Get_Height(){
    int k=0;
    for(int i=1;i<=n;i++)rk[sa[i]]=i;
    for(int i=1;i<=n;i++){
        if(rk[i]==1)continue;
        if(k)--k;
        int j=sa[rk[i]-1];
        while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k])k++;
        height[rk[i]]=k;
    }
    return;
}
}sa;

ll tsum[10][N];
int tcnt[10][N],Cnt[10],Lim;
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(const int id,int x,const int y){++Cnt[id];for(;x<Lim;ub(x))tsum[id][x]+=y,tcnt[id][x]++;return;}
inline void del(const int id,int x,const int y){--Cnt[id];for(;x<Lim;ub(x))tsum[id][x]-=y,tcnt[id][x]--;return;}
inline ll qsum(const int id,int x){ll res=0;for(;x;db(x))res+=tsum[id][x];return res;}
inline int qcnt(const int id,int x){int res=0;for(;x;db(x))res+=tcnt[id][x];return res;}

void solve(int L,int R){
    if(R-L+1<=400){
        for(int i=L,Mn=0;i<=R;i++){
            Mn=INF;
            for(int j=i+1;j<=R;j++){
                _min(Mn,sa.height[j]);
                if(num[i]+1==num[j])ans+=1ll*Mn*(min(R9[i],R0[j]));
                if(num[i]-1==num[j])ans+=1ll*Mn*(min(R0[i],R9[j]));
            }
        }
        return;
    }
    int M=(L+R)/2;
    solve(L,M),solve(M+1,R);
    Lim=n-L+1;
    mn[M]=INF;
    for(int i=M-1;i>=L;i--)mn[i]=min(mn[i+1],sa.height[i+1]);
    for(int i=M+1;i<=R;i++)mn[i]=min(mn[i-1],sa.height[i]);
    int p1=L,p2=R,cnt=0;
    while(p1<=M||p2>M){
        if(p1<=M&&(p2<=M||mn[p1]<mn[p2]))w[++cnt]=0,_num[cnt]=num[p1],_mn[cnt]=mn[p1],r0[cnt]=R0[p1],r9[cnt]=R9[p1],++p1;
        else w[++cnt]=1,_num[cnt]=num[p2],_mn[cnt]=mn[p2],r0[cnt]=R0[p2],r9[cnt]=R9[p2],--p2;
    }
    for(int i=1;i<=cnt;i++)if(w[i]==0&&_num[i]>0)add(_num[i],r0[i],r0[i]);
    for(int i=1;i<=cnt;i++)if(_num[i]>=0){
        if(w[i]==0){
        	if(_num[i]>0)del(_num[i],r0[i],r0[i]);
		}
        else if(_num[i]<9)ans+=1ll*_mn[i]*(1ll*r9[i]*(Cnt[_num[i]+1]-qcnt(_num[i]+1,r9[i]))+qsum(_num[i]+1,r9[i]));
    }
    for(int i=1;i<=cnt;i++)if(w[i]==1&&_num[i]>0)add(_num[i],r0[i],r0[i]);
    for(int i=1;i<=cnt;i++)if(_num[i]>=0){
        if(w[i]==1){
        	if(_num[i]>0)del(_num[i],r0[i],r0[i]);
		}
        else if(_num[i]<9)ans+=1ll*_mn[i]*(1ll*r9[i]*(Cnt[_num[i]+1]-qcnt(_num[i]+1,r9[i]))+qsum(_num[i]+1,r9[i]));
    }
    for(int i=1;i<=cnt;i++)if(w[i]==0&&_num[i]>=0&&_num[i]<9)add(_num[i],r9[i],r9[i]);
    for(int i=1;i<=cnt;i++)if(_num[i]>=0){
        if(w[i]==0){
        	if(_num[i]<9)del(_num[i],r9[i],r9[i]);
		}
        else if(_num[i]>0)ans+=1ll*_mn[i]*(1ll*r0[i]*(Cnt[_num[i]-1]-qcnt(_num[i]-1,r0[i]))+qsum(_num[i]-1,r0[i]));
    }
    for(int i=1;i<=cnt;i++)if(w[i]==1&&_num[i]>=0&&_num[i]<9)add(_num[i],r9[i],r9[i]);
    for(int i=1;i<=cnt;i++)if(_num[i]>=0){
        if(w[i]==1){
        	if(_num[i]<9)del(_num[i],r9[i],r9[i]);
		}
        else if(_num[i]>0)ans+=1ll*_mn[i]*(1ll*r0[i]*(Cnt[_num[i]-1]-qcnt(_num[i]-1,r0[i]))+qsum(_num[i]-1,r0[i]));
    }
    return;
}

signed main(){
    // ifile("number.in");
    // ofile("number.out");

    n=read();
    scanf("%s",str+1);
    for(int i=n;i>=1;i--){
        r0[i]=r9[i]=0;
        if(str[i]=='0')r0[i]=r0[i+1]+1;
        if(str[i]=='9')r9[i]=r9[i+1]+1;
    }
    sa.SA_init();
    for(int i=1;i<=n;i++)sa.s[i]=str[n-i+1];
    sa.Get_SA();
    sa.Get_Height();
    for(int i=0;i<=n;i++)num[i]=-2;
    for(int i=1;i<=n;i++){
        int id=sa.rk[n-i+2];
        num[id]=str[i]-'0',R0[id]=r0[i+1],R9[id]=r9[i+1];
    }
    for(int i=0;i<=n;i++)++sa.height[i],++R0[i],++R9[i];
    solve(0,n);
    printf("%lld\n",ans);
    return 0;
}
