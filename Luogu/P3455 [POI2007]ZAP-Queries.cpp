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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,a,b,d,prime[N],pr[N],mu[N],t,pre[N],ans;

signed main(){
	T=read();
	mu[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++t]=i,mu[i]=-1;
		for(int j=1;j<=t&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j],mu[prime[j]*i]=-mu[i];
			if(pr[i]==prime[j]){mu[prime[j]*i]=0;break;}
		}
	}
	for(int i=1;i<N;i++)pre[i]=pre[i-1]+mu[i];
	while(T--){
		a=read(),b=read(),d=read(),ans=0;
		a/=d,b/=d;
		int l=1,r;
		while(1){
			r=min(a/(a/l),b/(b/l));
			ans+=(pre[r]-pre[l-1])*(a/l)*(b/l);
			l=r+1;
			if(a/l==0||b/l==0)break;
		}
		printf("%d\n",ans);
	}	
	return 0;
}

