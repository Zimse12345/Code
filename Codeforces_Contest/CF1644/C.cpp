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

const int N=5e3+7,Mod=998244353,INF=1e9;
int T,n,x,a[N],sum[N],mx[N];

signed main(){
	T=read();
	while(T--){
		n=read(),x=read(),mx[0]=0;
		for(int i=1;i<=n;i++)a[i]=read(),sum[i]=sum[i-1]+a[i],mx[i]=-INF;
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)mx[j-i+1]=max(mx[j-i+1],sum[j]-sum[i-1]);
		for(int i=n-1;i>=0;i--)mx[i]=max(mx[i],mx[i+1]);
		for(int i=1;i<=n;i++)mx[i]+=i*x,mx[i]=max(mx[i-1],mx[i]);
		for(int i=0;i<=n;i++)printf("%d ",mx[i]);
		printf("\n");
	}
	return 0;
}

