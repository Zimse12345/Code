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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,e,a[N],pre[N],nxt[N];
int tot,prime[N],pr[N];

signed main(){
	for(int i=2;i<N;i++){
		if(!pr[i])prime[++tot]=i,pr[i]=i;
		for(int j=1;j<=tot&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	T=read();
	while(T--){
		n=read(),e=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				if(i>e)pre[i]=pre[i-e]+1;
				else pre[i]=1;
			}
			else pre[i]=0;
		}
		for(int i=n;i>=1;i--){
			if(a[i]==1){
				if(i+e<=n)nxt[i]=nxt[i+e]+1;
				else nxt[i]=1;
			}
			else nxt[i]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++)if(pr[a[i]]==a[i]){
			int l=0,r=0;
			if(i>e)l=pre[i-e];
			if(i+e<=n)r=nxt[i+e];
			ans+=(l+1)*(r+1)-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

