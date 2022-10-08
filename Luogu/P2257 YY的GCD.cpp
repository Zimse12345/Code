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

const int N=1e7+7,Mod=998244353,INF=1e9+7;
int T,n,m,ans,pr[N],prime[N],tot,mu[N],f[N];

signed main(){
	mu[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,mu[i]=-1,prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<N;j++){
			pr[i*prime[j]]=prime[j],mu[i*prime[j]]=-mu[i];
			if(pr[i]==prime[j]){mu[i*prime[j]]=0;break;}
		}
	}
	for(int i=1;i<=tot;i++){
		for(int j=1;j*prime[i]<N;j++)f[j*prime[i]]+=mu[j];
	}
	for(int i=1;i<N;i++)f[i]+=f[i-1];
	T=read();
	while(T--){
		n=read(),m=read(),ans=0;
		if(n<m)swap(n,m);
		for(int l=1,r;l<=m;){
			r=min(n/(n/l),m/(m/l));
			ans+=(n/l)*(m/l)*(f[r]-f[l-1]);
			l=r+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
