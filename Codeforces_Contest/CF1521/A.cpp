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

int T,n,a,b; 

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);}

signed main(){
	scanf("%lld",&T);
	while(T--){
		a=read(),b=read();
		if(b==1){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		if(b!=2)printf("%lld %lld %lld\n",a,a*(b-1),a*b);
		else{
			printf("%lld %lld %lld\n",a,3*a,a*b*2);
		} //
	}
	return 0;
}
