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
#define ull unsigned long long

using namespace std;

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;

int T,n,a[N],b[N];

int main(){
	scanf("%d",&T);
	while(T--){
		n=read();
		n*=2;
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		int t=0;
		for(int i=1;i<=n;i+=2)b[i]=a[++t];
		for(int i=2;i<=n;i+=2)b[i]=a[++t];
		for(int i=1;i<=n;i++)printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}

