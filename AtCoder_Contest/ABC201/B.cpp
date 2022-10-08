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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n;

struct mt{
	char name[20];
	int h;
	bool operator < (const mt& A)const{return h<A.h;}
}a[N];

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		cin>>a[i].name;
		a[i].h=read();
	}
	sort(a+1,a+n+1);
	printf("%s\n",a[n-1].name);
	return 0;
}

