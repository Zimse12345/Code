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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],ans;

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	int s=a[n];
	for(int i=2;i<n;i++){
		int c=min(m,a[n]-a[i]);
		a[i]+=c,m-=c,ans+=a[i];
	}
	ans=ans+m-m/(n-1);
	if(m%(n-1))--ans;
	printf("%lld\n",ans);
	return 0;
}

