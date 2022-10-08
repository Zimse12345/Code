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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,k,u[N],a[N],x,ans=1;
char o;

signed main(){
	n=read(),k=read();
	for(int i=1;i<=k;i++){
		o=getchar();
		while((o!='L')&&(o!='R'))o=getchar();
		x=read(),u[x]=1;
		if(o=='L')for(int j=x+1;j<=n;j++)++a[j];
		else for(int j=1;j<x;j++)++a[j];
	}
	for(int i=1;i<=n;i++)if(!u[i])ans=(ans*a[i])%Mod;
	printf("%lld\n",ans);
	return 0;
}

