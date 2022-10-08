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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e2+7,Mod=998244353,INF=1e9+7;
int n,m,pos[N*N],ccnt,cnt,fa[N],sz[N];
int p,k,a,b,c,q,mst[N*N],tot[N*N],ans;
struct edge{int u,v,w,tag;edge(int u=0,int v=0,int w=0,int tag=0):u(u),v(v),w(w),tag(tag){}
bool operator < (const edge& A)const{return w<A.w;}}e[N],E[N];
inline int F(int x){if(fa[x]!=x)fa[x]=F(fa[x]);return fa[x];}

inline void add(int x){
	int L=1,R=cnt,t=0;
	while(L<=R){
		int M=(L+R)>>1;
		if(pos[M]<=x)t=M,L=M+1;
		else R=M-1;
	}
	ans^=(mst[t]+tot[t]*(x-pos[t]));
	return;
} 

signed main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		e[i]=edge(u,v,w),pos[++ccnt]=e[i].w+1;
	}
	sort(e+1,e+m+1);
	pos[++ccnt]=0,pos[0]=-1;
	for(int i=1;i<m;i++)for(int j=i+1;j<=m;j++)pos[++ccnt]=(e[i].w+e[j].w)/2+1;
	
	sort(pos+1,pos+ccnt+1);
	for(int i=1;i<=ccnt;i++)if(pos[i]!=pos[i-1]){
		pos[++cnt]=pos[i];
		for(int j=1;j<=m;j++){
			E[j]=e[j],E[j].w=abs(E[j].w-pos[cnt]);
			if(e[j].w>=pos[cnt])E[j].tag=-1;
			else E[j].tag=1;
		}
		sort(E+1,E+m+1);
		for(int j=1;j<=n;j++)fa[j]=j,sz[j]=1;
		for(int j=1,u,v,A,B;j<=m;j++){
			u=E[j].u,v=E[j].v;
			A=F(u),B=F(v);
			if(A!=B){
				if(sz[A]<sz[B])swap(A,B);
				fa[B]=A,sz[A]+=sz[B],mst[cnt]+=E[j].w,tot[cnt]+=E[j].tag;
			}
		}
	}
	
	p=read(),k=read(),a=read(),b=read(),c=read();
	for(int i=1;i<=p;i++)q=read(),add(q);
	for(int i=p+1;i<=k;i++)q=(q*a+b)%c,add(q);
	printf("%lld\n",ans);
	return 0;
}

