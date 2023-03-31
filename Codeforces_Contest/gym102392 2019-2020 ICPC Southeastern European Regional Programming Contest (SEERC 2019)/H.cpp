#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

#define int long long

using namespace std;

inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}

const int N=1000007;

int n,a[N],vis[N],ans[N],cnt[N],p[N],len,val[N],tot;
priority_queue<int> Q;

signed main(){
	int mn=1;
	n=read();
	for(int i=1;i<=n*2-2;i++)a[i]=read(),vis[a[i]]=1,++cnt[a[i]];
	int pc=0;
	for(int i=1;i<=n;i++){
		pc+=cnt[i];
		if(pc==i)mn=min(n-1,mn+1);
		if(pc<i)pc=-N;
	}
	if(pc<0){
		for(int i=1;i<n;i++){
			printf("-1");
			if(i<n-1)printf(" ");
		}
		printf("\n");
		return 0;
	}
	sort(a+1,a+(n*2-2)+1);
	int mx=1;
	for(int i=1;i<n;i++)if(vis[i])++mx,--cnt[i],p[++len]=i;
	int rm=n-mx;
	for(int i=1;i<n;i++){
		int t=min(cnt[i],rm);
		rm-=t,cnt[i]-=t;
		if(!rm)break;
	}
	rm=mx-1;
	int sum=0;
	for(int i=n-1;i>=1;i--){
		int t=min(cnt[i],rm);
		rm-=t;
		while(t>0)val[++tot]=i,t--,Q.push(-i),sum+=i;
		if(!rm)break;
	}
	for(int i=mx-1;i>=mn;i--){
		ans[i]=sum;
		Q.push(-p[i]),sum+=p[i];
		sum+=Q.top(),Q.pop();
		sum+=Q.top(),Q.pop();
	}
	for(int i=1;i<n;i++){
		if(!ans[i])ans[i]=-1;
		printf("%lld",ans[i]);
		if(i<n-1)printf(" ");
	}
	printf("\n");
	return 0;
}
