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
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int n,d,c[N*2],tot,k,f[N],mx[N*4],tag[N*4];
map<int,int> m;
struct p{
	int a,b;
	p(int a=0,int b=0):a(a),b(b){};
	bool operator < (const p& A)const{return a+b<A.a+A.b;}
}s[N];

void build(int L,int R,int id){
	if(L==R)mx[id]=f[L];
	else{
		int M=(L+R)>>1;
		build(L,M,Lid),build(M+1,R,Rid);
		mx[id]=max(mx[Lid],mx[Rid]);
	}
	return;
}

void pushdown(int id){
	if(tag[id])mx[id]+=tag[id],tag[Lid]+=tag[id],tag[Rid]+=tag[id],tag[id]=0;
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
		mx[id]=max(mx[Lid],mx[Rid]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return mx[id];
	int res=-INF,M=(L+R)>>1;
	if(l<=M)res=query(L,M,Lid,l,r);
	if(r>M)res=max(res,query(M+1,R,Rid,l,r));
	return res;
}

signed main(){
	n=read(),d=read(),c[++tot]=d;
	for(int i=1,a,b;i<=n;i++)a=read(),b=read(),s[i]=p(a,b),c[++tot]=a,c[++tot]=b;
	sort(c+1,c+tot+1);
	c[0]=-1;
	for(int i=1;i<=tot;i++)if(c[i]!=c[i-1])c[++k]=c[i];
	for(int i=1;i<=k;i++)m[c[i]]=i;
	for(int i=1;i<=n;i++)s[i]=p(m[s[i].a],m[s[i].b]);
	sort(s+1,s+n+1);
	for(int i=0;i<=k;i++)f[i]=-INF;
	f[m[d]]=0;
	build(0,k,1);
	for(int i=1;i<=n;i++){
		//printf("A [%d - %d]\n",s[i].b,max(0,query(0,k,1,0,min(s[i].a,s[i].b))+1-query(0,k,1,s[i].b,s[i].b)));
		//printf("B [%d - %d]\n",s[i].b+1,s[i].a);
		update(0,k,1,s[i].b,s[i].b,max(0,query(0,k,1,0,min(s[i].a,s[i].b))+1-query(0,k,1,s[i].b,s[i].b)));
		if(s[i].b<s[i].a)update(0,k,1,s[i].b+1,s[i].a,1);
		//printf("(%d %d)\n",s[i].a,s[i].b);
	}
	pushdown(1);
	printf("%d\n",mx[1]);
	return 0;
}
