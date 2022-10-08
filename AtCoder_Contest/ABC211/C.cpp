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

const int N=1e5+7,Mod=1e9+7,INF=1e9+7;
char s[N],t[N];
int n,g[10];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	t[1]='c',t[2]='h',t[3]='o',t[4]='k';
	t[5]='u',t[6]='d',t[7]='a',t[8]='i';
	
	g[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=8;j++){
			if(s[i]==t[j])g[j]=(g[j]+g[j-1])%Mod;
		}
	}
	printf("%d",g[8]);
	return 0;
}

