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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],p[N],tag;

void c(int l,int r){
	if(r<l)return;
	if(l==r)tag=1;
	else{
		for(int i=l;i<r;i++)p[i]=i+1;
		p[r]=l;
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),tag=0;
		int l=0,r=1;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]!=a[i-1])c(l,r),l=i;
			r=i;
		}
		c(l,r);
		if(tag)printf("-1\n");
		else{
			for(int i=1;i<=n;i++)printf("%d ",p[i]);
			printf("\n");
		}
	}
	return 0;
}

