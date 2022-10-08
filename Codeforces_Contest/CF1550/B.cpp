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
int T,n,a,b;
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		n=read(),a=read(),b=read();
		scanf("%s",s+1);
		if(b>=0){
			printf("%d\n",(a+b)*n);
			continue;
		}
		char c='0';
		int k=1;
		if(s[1]=='0'&&s[n]=='0')c='1';
		for(int i=1;i<=n;i++)if(s[i]!=s[i-1]&&s[i]==c)++k;
		printf("%d\n",a*n+b*k);
	}
	return 0;
}

