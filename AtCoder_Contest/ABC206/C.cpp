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
#define int long long

using namespace std;

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,a[N],t,b[N],ans;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	
	int tot=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1])++tot;
		else{
			if(tot)b[++t]=tot;
			tot=1;
		}
	}b[++t]=tot;
	
	ans=n*(n-1);
	for(int i=1;i<=t;i++)ans-=b[i]*(b[i]-1);
	printf("%lld\n",ans/2);
	
	return 0;
}

