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
int k,n,t=1;
char s[N];

int w(int x){
	if(x<10)return 10;
	if(x<100)return 100;
	else return 1000;
}

int main(){
	k=read(),n=read(),s[t]='1';//ABAB AB CCCC
	if(k==0){
		for(int i=1;i<=n;i++)printf("%d\n",i);
	}
	if(k==1){
		for(int i=1;i<=n;i++)printf("%d%d%d\n",i,i,i+i);
	}
	if(k==2){
		for(int i=1;i<=n;i++)printf("%d%d%d%d\n",i,i,i,i*w(i)+i+i);
	}
	return 0;
}

