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
int n,a[N],to[N],ans;

int f(int x){
	if(to[x]!=x)to[x]=f(to[x]);
	return to[x];}

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),to[a[i]]=a[i];
	for(int i=1;i*2<=n;i++){
		int j=n-i+1;
		int A=f(a[i]),B=f(a[j]);
		if(A!=B)++ans,to[A]=B;
	}
	printf("%d\n",ans);
	
	return 0;
}

