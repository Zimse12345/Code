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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e15+7;
int n,sum[N];
int prime[N],tot,pr[N],d[N],sigma[N];

signed main(){
	n=read();
	sigma[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])prime[++tot]=i,pr[i]=i,sigma[i]=2,d[i]=1;
		for(int j=1;j<=tot&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j],sigma[prime[j]*i]=2*sigma[i],d[prime[j]*i]=1;
			if(pr[i]==prime[j])d[prime[j]*i]=d[i]+1,sigma[prime[j]*i]=sigma[i]/(d[i]+1)*(d[i]+2);
		}
	}
	for(int i=1;i*i<=n;i++)sum[i*i]=1;
	for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=1,v=i;
		while(v>1){
			int p=pr[v],c=0;
			while(pr[v]==p)v/=p,++c;
			if(c&1)x*=p; 
		}
		ans+=sum[n/x];
	}
	printf("%lld\n",ans);
	return 0;
}


