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

int n,k,a[N],b[N],c[N];

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=a[i],c[i]=k/n;
	sort(b+1,b+n+1);
	int s=k%n;
	if(s!=0)for(int i=1;i<=n;i++)if(a[i]<=b[s])++c[i];
	for(int i=1;i<=n;i++)printf("%lld\n",c[i]);
	return 0;
}

