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
		int x1=read(),x2=read(),x3=read(),x4=read();
		if(x2<x1){
			int t=x1;x1=x2,x2=t;
		} 
		if(x4<x3){
			int t=x3;x3=x4,x4=t;
		}
		if(x2>x3&&x4>x1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

