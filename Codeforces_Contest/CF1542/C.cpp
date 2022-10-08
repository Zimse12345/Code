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

#define int unsigned long long

using namespace std;

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e2+7,P=1e9+7,INF=1e9+7;
int T,n;

int qm(int x,int y,int mod) {
	int ans=0;
	while(y!=0){
		if(y&1==1)ans+=x,ans%=mod;
		x=x+x,x%=mod;
		y>>=1; 
	}
	return ans;
}

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){
	return (a*b)/gcd(a,b);}

signed main(){
	scanf("%lld",&T);
	while(T--){
		n=read();
		int ans=0ll,o=1ll,rm=n;
		for(int i=1;i<=100;i++){
			if(rm==0)break;
			
			int u=rm-rm/(i/gcd(o,i));
			ans=(ans+qm(u,i,P))%P;
			o=lcm(o,i),rm=n/o;
		}
		printf("%llu\n",ans);
	}
	return 0;
}

