/********************************
*FileName:
*Author: Zimse
*Data:
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
#define pb push_back
#define ll long long
//#define int long long
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

const int N=1e6+7;

int n,s[N];
char str[64];
vector<int> a,b,_a,_b;

int query(vector<int> q){
	printf("? %d ",int(q.size()));
	for(unsigned i=0;i<q.size();i++)printf("%d ",q[i]);
	printf("\n");
	fflush(stdout);
	scanf("%s",str);
	return str[0]=='Y'?1:0;
}

int answer(int ans){
	printf("! %d\n",ans);
	fflush(stdout);
	scanf("%s",str);
	return str[1]==')'?1:0;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a.pb(i);
	while(a.size()+b.size()>3){
		vector<int> q;
        int as=a.size(),bs=b.size();
        if(bs==1){
            a.pb(b[0]);
            b.resize(0);
            continue;
        }
        int t=as/2;
        if(bs&1)if(t+1<=as)++t;
        for(int i=0;i<t;i++)q.pb(a[i]);
        for(int i=0;i<bs/2;i++)q.pb(b[i]);
        if(query(q)){
            _a=q;
            for(int i=t;i<as;i++)_b.pb(a[i]);
        }
        else{
            for(int i=t;i<as;i++)_a.pb(a[i]);
            for(int i=bs/2;i<bs;i++)_a.pb(b[i]);
            for(int i=0;i<t;i++)_b.pb(a[i]);
        }
        a=_a,b=_b,_a.resize(0),_b.resize(0);
	}
    for(unsigned i=0;i<b.size();i++)a.pb(b[i]);
    vector<int> q1,q2;
	if(a.size()==1)answer(a[0]);
	else if(a.size()==2){
		if(!answer(a[0]))answer(a[1]);
	}
	else{
		q1.push_back(a[0]),q1.push_back(a[1]);
		if(!query(q1)){
			if(!answer(a[2])){
				q2.push_back(a[0]);
				if(query(q2))answer(a[0]);
				else answer(a[1]);
			}
		}
		else{
			if(!query(q1)){
				if(!answer(a[2])){
					q2.push_back(a[0]);
					if(query(q2))answer(a[0]);
					else answer(a[1]);
				}
			}
			if(!answer(a[0]))answer(a[1]);
		}
	}
	return 0;
}


