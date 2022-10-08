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
struct cow{
	int l,r,w;
	cow(int l=0,int r=0,int w=0):l(l),r(r),w(w){}
	bool operator < (cow& A)const{return r<A.r;}
}c[N];
int n,m,R,f[N],ans;

int main(){
	n=read(),m=read(),R=read();
	for(int i=1,l,r,w;i<=m;i++)l=read(),r=read(),w=read(),c[i]=cow(l,r,w);
	sort(c+1,c+m+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<i;j++)if(c[j].r+R<=c[i].l)f[i]=max(f[i],f[j]);
		f[i]+=c[i].w,ans=max(ans,f[i]);
	}
	printf("%d\n",ans); 
	return 0;
}
