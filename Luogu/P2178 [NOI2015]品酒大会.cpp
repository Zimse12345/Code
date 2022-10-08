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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e18+7;
int n,val[N],mx[N],ct[N],fa[N],sz[N],Max[N],Min[N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){};
bool operator < (const node& A)const{return y>A.y;}}p[N];
inline int F(int x){if(fa[x]^x)fa[x]=F(fa[x]);return fa[x];}

struct SA{
int m,h[N],x[N],y[N],sa[N],rk[N],c[N];
char s[N];

void Get_SA(){
	m=122;
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

void Get_Height(){
	int k=0;
	for(int i=1;i<=n;i++)rk[sa[i]]=i;
	for(int i=1,j;i<=n;i++){
		if(rk[i]==1)continue;
		if(k)--k;
		j=sa[rk[i]-1];
		while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k])++k;
		h[rk[i]]=k;
	}
	return;
}
}a; 

signed main(){
	n=read();
	scanf("%s",a.s+1);
	a.Get_SA();
	a.Get_Height();
	for(int i=1;i<=n;i++)val[a.rk[i]]=read();
	for(int i=1;i<=n;i++)mx[i-1]=-INF,fa[i]=i,sz[i]=1,Max[i]=Min[i]=val[i];
	for(int i=2;i<=n;i++)p[i-1]=node(i,a.h[i]);
	sort(p+1,p+n);
	for(int i=1;i<n;i++){
		int x=F(p[i].x-1),y=F(p[i].x),h=p[i].y;
		ct[h]+=sz[x]*sz[y];
		mx[h]=max(mx[h],max(Max[x]*Max[y],Min[x]*Min[y]));
		fa[y]=x,sz[x]+=sz[y],Max[x]=max(Max[x],Max[y]),Min[x]=min(Min[x],Min[y]);
	}
	for(int i=n-2;i>=0;i--)mx[i]=max(mx[i+1],mx[i]),ct[i]+=ct[i+1];
	for(int i=0;i<n;i++){
		if(mx[i]==-INF)mx[i]=0;
		printf("%lld %lld\n",ct[i],mx[i]);
	}
	return 0;
}

