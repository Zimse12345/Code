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
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;

int T,n,k,s;

signed main(){
	scanf("%d",&T);
	while(T--){
		n=read(),k=read(),s=read();
		int Lsum=((1+k)*k)/2,Rsum=((n-k+1+n)*k)/2;
		if(Lsum<=s&&Rsum>=s)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

