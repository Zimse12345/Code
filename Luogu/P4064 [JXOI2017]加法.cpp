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
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e16;
int T,n,m,k,v,a[N];
int mn[N*4],tag[N*4];
multiset<int> t[N],S;

void build(int L,int R,int id){
	tag[id]=0;
	if(L==R)mn[id]=a[L];
	else build(L,M,Lid),build(M+1,R,Rid),mn[id]=min(mn[Lid],mn[Rid]);
	return;
}

void pushdown(int id){
	if(tag[id])mn[id]+=tag[id],tag[Lid]+=tag[id],tag[Rid]+=tag[id],tag[id]=0;
	return;
}

void update(int L,int R,int id,int l,int r,int v){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)tag[id]+=v,pushdown(id);
	else update(L,M,Lid,l,r,v),update(M+1,R,Rid,l,r,v),mn[id]=min(mn[Lid],mn[Rid]);
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(r<L||R<l)return INF;
	if(l<=L&&r>=R)return mn[id];
	return min(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

bool check(int x){
	build(1,n,1);
	int K=k;
	S.clear();
	for(int i=1;i<=n;i++){
		int s=query(1,n,1,i,i);
		for(set<int>::iterator it=t[i].begin();it!=t[i].end();it++)S.insert(*it);
		while(S.size()){
			set<int>::iterator it=S.begin();
			int p=(-(*it));
			if(p<i)S.erase(it);
			else if(s<x){
				update(1,n,1,i,p,v),--K;
				S.erase(it),s+=v;
				if(K<0)return false;
			}
			else break;
		}
		if(s<x)return false;
	}
	return K>=0;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),k=read(),v=read();
		for(int i=1;i<=n;i++)a[i]=read(),t[i].clear();
		for(int i=1,x;i<=m;i++)x=read(),t[x].insert(-read());
		int L=0,R=INF,ans=0;
		while(L<=R){
			if(check(M))ans=M,L=M+1;
			else R=M-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

