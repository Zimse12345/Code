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
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

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

const int N=5000007,SZ=5;
int n,tot,pre;
char s[N];
struct node{
	int to[SZ],len,link,ed;
}t[N*2];
int que[N],rpos[N],ql,qr,ans[N];
int tl[N],tr[N];
ll Ans;

void ins(int c){
	int id=++tot,p=pre;
	t[id].len=t[p].len+1,t[id].ed=t[p].ed+1;
	while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
	if(p==-1)t[id].link=0;
	else{
		int q=t[p].to[c];
		if(t[q].len==t[p].len+1)t[id].link=q;
		else{
			int cp=++tot;
			t[cp]=t[q],t[cp].len=t[p].len+1;
			while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
			t[q].link=t[id].link=cp;
		}
	}
	pre=id;
	return;
}

signed main(){
	t[0].link=-1,ql=1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)ins(s[i]-'a');
	for(int i=1;i<=tot;i++)t[t[i].link].ed=-1;
    for(int i=1;i<=tot;i++)if(t[i].ed!=-1){
        int l=t[i].ed-t[t[i].link].len,r=t[i].ed;
        _max(tl[r],l);
        if(!tr[l])tr[l]=r;
        else _min(tr[l],r);
    }
    int pl=-INF;
    for(int i=1;i<=n;i++){
        if(tl[i])_max(pl,tl[i]);
        if(tr[i]){
            while(ql<=qr&&tr[i]-i+1<=que[qr])--qr;
            que[++qr]=tr[i]-i+1,rpos[qr]=tr[i];
        }
        while(ql<=qr&&rpos[ql]<i)++ql;
        if(ql<=qr)ans[i]=que[ql];
        else ans[i]=INF;
        _min(ans[i],i-pl+1);
    }
    pl=INF;
    for(int i=n;i>=1;i--){
        if(tr[i])_min(pl,tr[i]);
        _min(ans[i],pl-i+1);
        Ans+=ans[i];
    }
	printf("%lld\n",Ans);
	return 0;
}
