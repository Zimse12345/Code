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

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,a[N],ans[N],nd[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++){
		int c=a[i+1]-nd[i-1]-1;
		int u=c/a[i];
		nd[i]=nd[i-1]+u*a[i];
		ans[i]=ans[i-1]+u;
	}
//	for(int i=1;i<n;i++)printf("[%lld  %lld]\n",ans[i],nd[i]);
	q=read();
	while(q--){
		int b=read();
		int L=1,R=n-1,K=0;
		while(L<=R){
			int M=(L+R)>>1;
			if(b>=nd[M])K=M,L=M+1;
			else R=M-1;
		}
		int res=ans[K]+(b-nd[K])/a[K+1];
		printf("%lld %lld\n",nd[K]+((b-nd[K])/a[K+1])*a[K+1],res);
	}
	return 0;
}

