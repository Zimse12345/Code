#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define int long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while('0'<=qrc&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e6+7,INF=1e9+7;
int T,p,d,rt,ans[N],cnt,hr[N];
int prime[N],tot,pr[N],phi[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lindongli2004(int x,int k=p-2){int res=1;while(k){if(k&1ll)res=(res*x)%p;x=(x*x)%p,k/=2;}return res;}

signed main(){
	phi[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])prime[++tot]=i,pr[i]=i,phi[i]=i-1;
		for(int j=1,x;j<=tot&&prime[j]*i<N;j++){
			x=prime[j]*i,pr[x]=prime[j],phi[x]=phi[i]*(prime[j]-1);
			if(pr[i]==prime[j]){phi[x]+=phi[i];break;}
		}
	}
	hr[2]=hr[4]=1;
	for(int i=2,x;i<=tot;i++){
		x=prime[i];
		while(x<N){
			hr[x]=1;if(2*x<N)hr[x*2]=1;
			x*=prime[i];
		}
	}
	T=read();
	while(T--){
		p=read(),d=read(),cnt=0;
		if(!hr[p]){printf("0\n\n");continue;}
		for(int i=1,tag=1;i<p;i++,tag=1)if(gcd(i,p)==1){
			for(int j=1,x=i;j<phi[p];j++,x=(x*i)%p)if(x==1){tag=0;break;}
			if(tag){rt=i;break;}
		}
		printf("%lld\n",phi[phi[p]]);
		for(int i=1,x=rt;i<=phi[p];i++,x=(x*rt)%p)if(gcd(i,phi[p])==1)ans[++cnt]=x;
		sort(ans+1,ans+cnt+1);
		for(int i=d;i<=cnt;i+=d)printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}

