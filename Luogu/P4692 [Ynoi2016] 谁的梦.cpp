/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-14
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

const int Mod=19260817;//1000000007;
namespace Zimse{
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
}using namespace Zimse;

const int N=2e5+7;
const int INF=1000114514;

int S=1,n,m,Val[N],vt,Vt,qx[N],qy[N],qval[N],ans,Len[N];
vector<int> a[N];
map<int,int> mp;
map<int,int> v[N];
set<int> pos[N];
int P[N],c0[N];
map<int,int> p[N];
int cnt;

inline int calc(int L,int R){
	if(R<L)return 0;
	int len=R-L+1;
	return len*(len+1)/2%Mod;
}

void Ins(int I,int val,int id,int x){
	set<int>::iterator it=pos[id].upper_bound(x);
	int R=*it;
	--it;
	int L=*it;
	int t=calc(L+1,R-1)-calc(L+1,x-1)-calc(x+1,R-1);
	if(c0[val]>0)addmod(ans,-(S-0));
	else addmod(ans,-(S-P[val]));
	if(!p[I][val])--c0[val];
	else P[val]=P[val]*inv(p[I][val])%Mod;
	p[I][val]-=t; 
	if(!p[I][val])++c0[val];
	else P[val]=P[val]*p[I][val]%Mod;
	if(c0[val]>0)addmod(ans,S-0);
	else addmod(ans,S-P[val]);
	pos[id].insert(x);
	return;
}

void Era(int I,int val,int id,int x){
	pos[id].erase(x);
	set<int>::iterator it=pos[id].upper_bound(x);
	int R=*it;
	--it;
	int L=*it;
	int t=calc(L+1,R-1)-calc(L+1,x-1)-calc(x+1,R-1);
	if(c0[val]>0)addmod(ans,-(S-0));
	else addmod(ans,-(S-P[val]));
	if(!p[I][val])--c0[val];
	else P[val]=P[val]*inv(p[I][val])%Mod;
	p[I][val]+=t; 
	if(!p[I][val])++c0[val];
	else P[val]=P[val]*p[I][val]%Mod;
	if(c0[val]>0)addmod(ans,S-0);
	else addmod(ans,S-P[val]);
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)Len[i]=read(),S=S*calc(1,Len[i])%Mod;
	for(int i=1,len;i<=n;i++){
		len=Len[i];
		for(int j=1,x;j<=len;j++){
			x=read();
			Val[++vt]=x;
			a[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		qx[i]=read(),qy[i]=read(),qval[i]=read();
		Val[++vt]=qval[i];
	}
	sort(Val+1,Val+vt+1);
	for(int i=1;i<=vt;i++)if(Val[i]!=Val[i-1]){
		Val[++Vt]=Val[i],mp[Val[i]]=Vt;
		P[Vt]=S;
	}
	for(int i=1;i<=n;i++){
		for(unsigned j=0;j<a[i].size();j++){
			a[i][j]=mp[a[i][j]];
			if(!v[i].count(a[i][j])){
				p[i][a[i][j]]=calc(1,Len[i]);
				v[i][a[i][j]]=++cnt;
				pos[cnt].insert(-1),pos[cnt].insert(Len[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(unsigned j=0;j<a[i].size();j++){
			Ins(i,a[i][j],v[i][a[i][j]],j);
		}
	}
	addmod(ans,Mod);
	_write(ans);
	for(int i=1,x,y,val;i<=m;i++){
		x=qx[i],y=qy[i]-1,val=mp[qval[i]];
		Era(x,a[x][y],v[x][a[x][y]],y);
		if(!v[x].count(val)){
			v[x][val]=++cnt;
			p[x][val]=calc(1,Len[x]);
			pos[cnt].insert(-1),pos[cnt].insert(Len[x]);
		}
		a[x][y]=val;
		Ins(x,val,v[x][val],y);
		addmod(ans,Mod);
		_write(ans);
	}
	return 0;
}

