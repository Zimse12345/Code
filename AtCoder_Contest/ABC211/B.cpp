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
char s[100],a1,a2,a3,a4;

int main(){
	for(int i=1;i<=4;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		if(len==1&&s[1]=='H')a1=1;
		if(len==2&&s[1]=='2'&&s[2]=='B')a2=1;
		if(len==2&&s[1]=='3'&&s[2]=='B')a3=1;
		if(len==2&&s[1]=='H'&&s[2]=='R')a4=1;
	}
	if(a1&&a2&&a3&&a4)printf("Yes\n");
	else printf("No\n"); 
	return 0;
}

