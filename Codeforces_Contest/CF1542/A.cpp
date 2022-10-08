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

int T,n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		n=read();
		int A=0,B=0;
		
		for(int i=1;i<=n*2;i++){
			int v=read();
			if(v%2)++A;
			else ++B;
		}
		
		if(A!=B)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

