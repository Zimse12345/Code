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

const int N=2e5+7,Mod=998244353,INF=1e14;
int n,a[N],b[N],c[N],m,ans,sum[N];

int sol(int x,int R){
	if(x==m)return max(0ll,min(R,b[x]-1)-1)*sum[x];
	int t=R/b[x+1];
	int u=(t-1)*b[x+1],v=u+b[x+1];
	int ans=sol(x+1,b[x+1])+u*sum[x-1]+max(0ll,u-1)*c[x];
	if(v<=R)ans=max(ans,sol(x+1,R-v)+v*sum[x-1]+max(0ll,v-1)*c[x]);
	return ans;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,mi=INF;i<=n;i++){
		if(a[i]<mi)mi=a[i],b[++m]=a[i];
		++c[m];
	}
	for(int i=1;i<=m;i++)sum[i]=sum[i-1]+c[i];
	printf("%lld",sol(1,b[1]));
	return 0;
}

