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
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;

int T,n,a[N]; 

int main(){
	scanf("%d",&T);
	while(T--){
		n=read();
		int Min=INF,w=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]<Min)Min=a[i],w=i;
		}
		printf("%d\n",n-1);
		for(int i=1;i<w;i++){
			int dis=(w-i)%2;
			printf("%d %d %d %d\n",i,w,Min+dis,Min);
		}
		for(int i=w+1;i<=n;i++){
			int dis=(i-w)%2;
			printf("%d %d %d %d\n",i,w,Min+dis,Min);
		}
	}
	return 0;
}
