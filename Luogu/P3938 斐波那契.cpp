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
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=70,Mod=998244353,INF=1e9+7;
int T,a,b,fib[100];

int F(int x){
	if(x==1)return 1;
	int L=1,R=N,H=0;
	while(L<=R){
		int M=(L+R)>>1;
		if(fib[M]<x)H=M,L=M+1;
		else R=M-1;
	}
	return x-fib[H];
}

signed main(){
	fib[0]=fib[1]=1;
	for(int i=2;i<=70;i++)fib[i]=fib[i-2]+fib[i-1];
	
	T=read();
	while(T--){
		a=read(),b=read();
		while(a!=b){
			if(a>b)a=F(a);
			else b=F(b);
		}
		printf("%lld\n",a);
	}
	return 0;
}

