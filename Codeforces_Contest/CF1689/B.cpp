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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],p[N],t[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		if(n==1){
			read(); 
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=n;j++)if(!t[j]&&j!=a[i]){
				p[i]=j;
				t[j]=1;
				break;
			}
		}
		int x=0,y=0;
		for(int i=1;i<=n;i++)if(!t[i]){
			if(!x)x=i;
			else y=i;
		}
		if(x!=a[n-1]&&y!=a[n]){
			p[n-1]=x,p[n]=y;
		}
		else{
			p[n-1]=y,p[n]=x;
		}
		for(int i=1;i<=n;i++)printf("%d ",p[i]),t[i]=0;
		printf("\n");
	}
	return 0;
}

