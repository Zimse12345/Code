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

const int N=1e2+7,Mod=998244353,INF=1e9+7;

int T,a,b;

signed main(){
	scanf("%lld",&T);
	while(T--){
		a=read(),b=read();
		if(b>a){
			int t=a;a=b,b=t;}
		int c=a-b;
		if(c==0)printf("0 0\n");
		else{
			int ans=min(b%c,c-b%c);
			printf("%lld %lld\n",c,ans);
		}
	}
	return 0;
}

