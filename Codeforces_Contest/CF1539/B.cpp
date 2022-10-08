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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,l,r,a[N],sum[N],len;
char s[N];

int main(){
	len=read(),T=read();
	scanf("%s",s+1);
	for(int i=1;i<=len;i++){
		a[i]=s[i]-'a'+1,sum[i]=sum[i-1]+a[i];
	}
	
	while(T--){
		l=read(),r=read();
		printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}

