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

const int N=1e3+7,Mod=998244353,INF=1e9+7;

int T,n,a[N],t[N];

int main(){
	scanf("%d",&T);
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int d=1;t[d]=a[1];
		printf("%d\n",t[d]);
		for(int i=2;i<=n;i++){
			if(a[i]==t[d]+1)++t[d];
			else if(a[i]==1)t[++d]=1;
			else{
				while(a[i]!=t[d]+1&&d>0)--d;
				++t[d];
			}
			for(int i=1;i<=d;i++)printf("%d%c",t[i],i==d?'\n':'.');
		}
	}
	return 0;
}

