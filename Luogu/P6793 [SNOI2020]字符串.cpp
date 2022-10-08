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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,p,ty[N],fa[N],c1[N],c2[N],ans;
int F(int x){if(fa[x]^x)fa[x]=F(fa[x]);return fa[x];}
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return y>A.y;}}v[N];
char A[N],B[N];
struct SA{
int m,h[N],x[N],y[N],c[N],sa[N],rk[N];
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
	for(int i=1;i<=n;i++)rk[sa[i]]=i;
	for(int i=1,j,k=0;i<=n;i++){
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
	n=read(),p=read();
	scanf("%s",A+1),scanf("%s",B+1);
	for(int i=1;i<=n;i++)a.s[i]=A[i],a.s[i+n]=B[i];
	n*=2;
	a.Get_SA();
	a.Get_Height();
	n/=2;
	for(int i=1;i<=n-p+1;i++)ty[a.rk[i]]=1,ty[a.rk[i+n]]=2;
	for(int i=2;i<=n*2;i++)v[i-1]=node(i,a.h[i]);
	sort(v+1,v+n*2);
	for(int i=1;i<=n*2;i++){
		fa[i]=i;
		if(ty[i]==1)++c1[i];
		if(ty[i]==2)++c2[i];
	}
	for(int i=1;i<n*2;i++){
		int x=F(v[i].x),y=F(v[i].x-1);
		while(c1[x]&&c2[y])--c1[x],--c2[y],ans+=max(0ll,p-v[i].y);
		while(c2[x]&&c1[y])--c2[x],--c1[y],ans+=max(0ll,p-v[i].y);
		fa[y]=x,c1[x]+=c1[y],c2[x]+=c2[y];
	}
	printf("%lld\n",ans);
	return 0;
}

