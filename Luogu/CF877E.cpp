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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],val[N];
int fa[N],cnt[N],dfn[N],tot;
int sum[N<<2],tag[N<<2],len[N<<2];
vector<int> ch[N];
char op[N];

void dfs1(int u){
	cnt[u]=1,dfn[u]=++tot;
	for(int i=0;i<int(ch[u].size());i++){
		dfs1(ch[u][i]),cnt[u]+=cnt[ch[u][i]];
	}
	return;
}

void pushdown(int id){
	if(tag[id]){
		sum[id]=len[id]-sum[id];
		if(len[id]>1)tag[id<<1]^=1,tag[(id<<1)|1]^=1;
		tag[id]=0;
	}
	return;
}

void build(int L,int R,int id){
	len[id]=R-L+1;
	if(L==R)sum[id]=val[L];
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		sum[id]=sum[id<<1]+sum[(id<<1)|1];
	}
	return;
}

void update(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=1,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r);
		else pushdown(id<<1);
		if(r>M)update(M+1,R,(id<<1)|1,l,r);
		else pushdown((id<<1)|1);
		sum[id]=sum[id<<1]+sum[(id<<1)|1];
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return sum[id];
	int M=(L+R)>>1,res=0;
	if(l<=M)res+=query(L,M,id<<1,l,r);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
	return res;
}

int main(){
	n=read();
	for(int i=2,f;i<=n;i++)f=read(),fa[i]=f,ch[f].push_back(i);
	for(int i=1;i<=n;i++)a[i]=read();
	dfs1(1);
	for(int i=1;i<=n;i++)val[dfn[i]]=a[i];
	build(1,n,1);
	m=read();
	for(int i=1,x;i<=m;i++){
		scanf("%s",op+1);
		x=read();
		if(op[1]=='g')printf("%d\n",query(1,n,1,dfn[x],dfn[x]+cnt[x]-1));
		else update(1,n,1,dfn[x],dfn[x]+cnt[x]-1);
	}
	return 0;
}
