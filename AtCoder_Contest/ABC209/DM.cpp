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

const int N=10,Mod=998244353,INF=1e9+7;

int T,n,a[N];

int main(){
	srand(time(0));
	freopen("d.in","w",stdout);
	printf("%d\n",N);
	for(int i=1;i<=N;i++){
		int len=3+rand()%4;
		for(int j=1;j<=len;j++)printf("%c",'a'+rand()%2);
		printf("\n");
	}
	return 0;
}

