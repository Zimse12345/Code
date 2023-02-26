#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
 #define int long long

inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<48||57<c){
		if(c==45)y=-1;
		c=getchar();
	}
	while(47<c&&c<58)x=x*10+c-48,c=getchar();
	return x*y;
}

const int N=1000007;

int T,n,m,a[N],pre[N],sum[N],ans;

signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),ans=0;
		for(int i=1;i<=n;i++)a[i]=read(),pre[a[i]]=0;
		for(int i=1;i<=m;i++){
			int p=read(),v=read();
			sum[a[p]]+=i-pre[a[p]],a[p]=v,pre[v]=i;
		}
		for(int i=1;i<=n;i++)sum[a[i]]+=m-pre[a[i]]+1;
		for(int i=1;i<=n+m;i++){
			ans+=sum[i]*(sum[i]-1)/2+sum[i]*(m+1-sum[i]);
			pre[i]=sum[i]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}


