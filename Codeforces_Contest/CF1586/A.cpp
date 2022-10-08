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

const int N=1e2+7,M=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],p[M];

int main(){
	T=read();
	for(int i=2;i<M;i++)if(!p[i]){
		for(int j=i*2;j<M;j+=i)p[j]=1;
	}
	while(T--){
		n=read();
		int sum=0;
		for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
		if(p[sum]){
			printf("%d\n",n);
			for(int i=1;i<=n;i++)printf("%d ",i);
			printf("\n");
			continue;
		}
		for(int i=1;i<=n;i++)if(p[sum-a[i]]){
			printf("%d\n",n-1);
			for(int j=1;j<=n;j++)if(i!=j)printf("%d ",j);
			printf("\n");
			break;
		}
	}
	return 0;
}
