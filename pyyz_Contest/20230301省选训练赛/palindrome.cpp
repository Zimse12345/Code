/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
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
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
// #define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int n,cnt,p[N];
int q,ql[N],qr[N],ans[N];
char str[N],s[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<node> qryR[N],qryL[N];
vector<int> line[N];
vector<int> midp[N],midq[N];
set<int> pos;

int mx[N*4];
void update(int id,int L,int R,int x,int y){
    _max(mx[id],y);
    if(L!=R){
        if(x<=M)update(Lid,L,M,x,y);
        else update(Rid,M+1,R,x,y);
    }
    return;
}

int query(int id,int L,int R,int l,int r){
    if(l<=L&&r>=R)return mx[id];
    if(r<L||R<l)return 0;
    return max(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
	// ifile("palindrome.in");
	// ofile("palindrome.out");
	
    scanf("%s",str+1);
    n=strlen(str+1);
    s[0]='~',s[++cnt]='|';
    for(int i=1;i<=n;i++)s[++cnt]=str[i],s[++cnt]='|';
    for(int t=1,r=0,mid=0;t<=cnt;t++){
        if(t<=r)p[t]=min(p[mid*2-t],r-t+1);
        while(s[t-p[t]]==s[t+p[t]])++p[t];
        if(p[t]+t>r)r=p[t]+t-1,mid=t;
    }
    for(int i=1;i<=cnt;i++){
        if(p[i]<=2)continue;
        line[i+p[i]-1].pb(i-p[i]+1);
        midp[i].pb(i),midp[i+p[i]].pb(-i);
        midq[i].pb(i),midq[i-p[i]].pb(-i);
    }
    q=read();
    for(int i=1;i<=q;i++){
        int l=read()+1,r=read()+1;
        ql[i]=l*2-1,qr[i]=r*2+1;
        qryR[qr[i]].pb(node(i,ql[i]));
        qryL[ql[i]].pb(node(i,qr[i]));
    }
    pos.insert(-INF),pos.insert(INF);
    for(int i=1;i<=cnt;i++){
        for(unsigned j=0;j<line[i].size();j++)update(1,1,cnt,line[i][j],i-line[i][j]+1);
        for(unsigned j=0;j<qryR[i].size();j++)_max(ans[qryR[i][j].x],query(1,1,cnt,qryR[i][j].y,i));
        for(unsigned j=0;j<midp[i].size();j++){
            int x=midp[i][j];
            if(x>0)pos.insert(x);
            else pos.erase(-x);
        }
        for(unsigned j=0;j<qryR[i].size();j++){
            int l=qryR[i][j].y,r=i,res=0;
            set<int>::iterator it=pos.lower_bound((l+r+1)/2);
            if(l<=*it&&*it<=r)_max(res,min(r-*it,*it-l)*2+1);
            --it;
            if(l<=*it&&*it<=r)_max(res,min(r-*it,*it-l)*2+1);
            _max(ans[qryR[i][j].x],res);
        }
    }
    pos.clear(),pos.insert(-INF),pos.insert(INF);
    for(int i=cnt;i>=1;i--){
        for(unsigned j=0;j<midq[i].size();j++){
            int x=midq[i][j];
            if(x>0)pos.insert(x);
            else pos.erase(-x);
        }
        for(unsigned j=0;j<qryL[i].size();j++){
            int l=i,r=qryL[i][j].y,res=0;
            set<int>::iterator it=pos.lower_bound((l+r+1)/2);
            if(l<=*it&&*it<=r)_max(res,min(r-*it,*it-l)*2+1);
            --it;
            if(l<=*it&&*it<=r)_max(res,min(r-*it,*it-l)*2+1);
            _max(ans[qryL[i][j].x],res);
        }
    }
    for(int i=1;i<=q;i++)_write(max(1,ans[i]/2));
    return 0;
}
