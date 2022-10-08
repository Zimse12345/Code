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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,k,P,a[N],c[N],pr[N],prime[N],t,ans=1,aans=1;

int qp(int x,int K){
	int res=1;
	while(K){
		if(K&1ll)res=(res*x)%P;
		x=(x*x)%P,K/=2;
	}
	return res;
}

signed main(){
	pr[1]=1;
	for(int i=2;i<N;i++){
		if(pr[i]==0)pr[i]=i,prime[++t]=i;
		for(int j=1;j<=t&&i*prime[j]<=N;j++){
			pr[i*prime[j]]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	n=read(),m=read(),k=read(),P=read();
	for(int i=0;i<m;i++)a[i+1]=k+i;
	
	for(int i=1,x;i<=m;i++){
		x=i;
		while(x!=1&&pr[x]<1000)--c[pr[x]],x/=pr[x];
		if(x>1){
			int y=(k/x)*x;
			if(y<k)y+=x;
			y-=k-1;
			while(a[y]%x!=0)y+=x;
			a[y]/=x;
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;prime[j]<=min(1000ll,a[i]);j++)while(a[i]%prime[j]==0)++c[prime[j]],a[i]/=prime[j];
		if(a[i]>1)ans=(ans*a[i])%P;
	}
	for(int i=1;i<1000;i++)if(c[i]>0)ans=(ans*qp(i,c[i]))%P;
	for(int i=1;i<=n;i++)aans=(aans*(ans+P))%P,ans--;
	printf("%lld\n",aans);
	return 0;
}

