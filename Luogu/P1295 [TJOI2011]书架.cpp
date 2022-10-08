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
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e12+7;
int n,L,H[N],Len[N],sl[N],f[N],val[N],st[N],top;
int len[N*4],mi[N*4],tag[N*4];

void build(int L,int R,int id){
	len[id]=R-L+1;
	if(L!=R){
		int M=(L+R)>>1;
		build(L,M,Lid),build(M+1,R,Rid);
	}
	return;
}

void pushdown(int id){
	if(tag[id])mi[id]+=tag[id],tag[Lid]+=tag[id],tag[Rid]+=tag[id],tag[id]=0;
	return; 
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,Lid,l,r,x);
		else pushdown(Lid);
		if(r>M)update(M+1,R,Rid,l,r,x);
		else pushdown(Rid);
		mi[id]=min(mi[Lid],mi[Rid]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return mi[id];
	int M=(L+R)>>1,res=INF;
	if(l<=M)res=query(L,M,Lid,l,r);
	if(r>M)res=min(res,query(M+1,R,Rid,l,r));
	return res;
}

signed main(){
	n=read(),L=read();
	for(int i=1;i<=n;i++)H[i]=read(),Len[i]=H[i],sl[i]=sl[i-1]+Len[i];
	int p=1;
	build(1,n,1);
	for(int i=1;i<=n;i++){
		while(top>0&&H[st[top]]<H[i]){
			update(1,n,1,st[top-1]+1,st[top],-H[st[top]]);
			--top;
		}
		st[++top]=i,update(1,n,1,st[top-1]+1,i,H[i]);
		while(sl[i]-sl[p-1]>L)++p;
		f[i]=min(H[i]+f[i-1],query(1,n,1,p,i)),update(1,n,1,i+1,i+1,f[i]);
	}
	printf("%lld\n",f[n]);
	return 0;
}
