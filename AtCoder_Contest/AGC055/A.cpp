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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,v[N],ans[N],sum[N][5];
char s[N];

void iNit(){
	for(int i=1;i<=n;i++){
		sum[i][1]=sum[i-1][1],sum[i][2]=sum[i-1][2],sum[i][3]=sum[i-1][3];
		++sum[i][v[i]];
	}
	return;
}

inline int f(int x,int l,int r){return sum[r][x]-sum[l-1][x];}

void sol(int x){
	iNit();
	int p1=x*2-1,p2=x*2;
	int y=x+1,z=x+2;
	if(y>3)y-=3;
	if(z>3)z-=3;
	int k=0,m=0;
	for(int i=1;i<=n;i++){
		if(f(x,1,i)<=f(y,i+1,n)&&f(x,1,i)<=f(z,i+1,n))k=i;
		else break;
	}
//	printf("(%d %d %d %d %d %d %d %d)\n",x,p1,p2,x,y,z,k,m);
	for(int i=k+1;i<=n;i++){
		if(f(y,k+1,i)<=f(z,i+1,n))m=i;
		else break;
	}
	int k1=f(y,k+1,m),r=k1,sx=0;
	for(int i=1;i<=k;i++)if(v[i]==x){
		++sx;
		if(r<=0)ans[i]=p2;
		else ans[i]=p1,--r;
		v[i]=4;
	}
	for(int i=k+1;i<=m;i++)if(v[i]==y)ans[i]=p1,v[i]=4;
	r=k1;
	for(int i=m+1;i<=n;i++)if(v[i]==z){
		if(r<=0)break;
		ans[i]=p1,v[i]=4;
		--r;
	}
	sx-=k1,r=sx;
	for(int i=k+1;i<=n;i++)if(v[i]==z){
		if(r<=0)break;
		ans[i]=p2,v[i]=4;
		--r;
	}
	r=sx;
	for(int i=n;i>=k+1;i--)if(v[i]==y){
		if(r<=0)break;
		ans[i]=p2,v[i]=4;
		--r;
	}
	return;
}

int main(){
	n=read()*3;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='A')v[i]=1;
		if(s[i]=='B')v[i]=2;
		if(s[i]=='C')v[i]=3;
	}
	sol(1),sol(2),sol(3);
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}
