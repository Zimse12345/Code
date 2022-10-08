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

int T,n,a,b;

signed main(){
	scanf("%lld",&T);
	while(T--){
		n=read(),a=read(),b=read();
		int v=1,y=0;
		if(a!=1)while(v<=n&&!y){
			int k=n-v;
			if(k%b==0)y=1;
			v*=a;
		}if(a==1&&((n-1)%b==0))y=1;
		if(y)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

