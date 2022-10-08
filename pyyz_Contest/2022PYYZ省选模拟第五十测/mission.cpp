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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,k,q,a[N],b[N],c[N],d[N];

void sol(){
	int res=0;
	for(int i=1;i<=k;i++){
		int v=0;
		for(int j=i;j<=n;j+=k){
			if(v^d[j]){
				++res;
				if(j>n-k+1){
					printf("-1\n");
					return;
				}
			}
			v^=d[j];
		}
	}
//	int res=0;
//	for(int i=1;i<=n;i++)d[i]=c[i];
//	for(int i=1;i+k-1<=n;i++)if(d[i]){
//		++res;
//		for(int j=i+1;j<=i+k-1;j++)d[j]^=d[i];
//		d[i]=0;
//	}
//	for(int i=1;i<=n;i++)if(d[i])res=-1;
	printf("%d\n",res);
	return;
}

signed main(){
	n=read(),k=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read(),c[i]=a[i]^b[i],d[i]=c[i]^c[i-1];
	sol();
	while(q--){
		char C=getchar();
		while(C!='a'&&C!='b')C=getchar();
		int x=read(),y=read();
		if(C=='a'){
			c[x]^=a[x]^y;
			d[x]=c[x]^c[x-1];
			d[x+1]=c[x+1]^c[x];
			a[x]=y;
		}
		else{
			c[x]^=b[x]^y;
			d[x]=c[x]^c[x-1];
			d[x+1]=c[x+1]^c[x];
			b[x]=y;
		}
		sol();
	}
	return 0;
}

