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

using namespace std;
#define int long long

const int N=1e6+7;
int n,q,a[N],s,ss,p[N];

bool check(int x){
	int l=1,r=0,c=q;
	s=0,ss=0;
	for(int i=n;i>=1;i--){
		while(l<=r&&x-(i-p[l])*(i-p[l])<=0)s-=p[l],ss-=p[l]*p[l],++l;
		int len=r-l+1,v=x*len-(i*i*len+ss-2*i*s);
		int vv=max(0ll,a[i]-v);
		while(vv>0){
			vv-=x;
			--c,p[++r]=i,ss+=i*i,s+=i;
			if(c<0)return 0;
		}
	}
	return 1;
}

signed main(){
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),++a[i];
	int L=1,R=1e11;
	int ans=0;
	while(L<=R){
		int M=(L+R)/2;
		if(check(M))ans=M,R=M-1;
		else L=M+1;
	}
	printf("%lld\n",ans);
	return 0;
}

