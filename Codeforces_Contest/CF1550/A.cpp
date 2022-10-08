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

int T,s,ans;

int main(){
	scanf("%d",&T);
	while(T--){
		s=read(),ans=0;
		if(s)s-=1,++ans;
		if(s){
			for(int i=3;1;i+=2){
				if(s>=i)s-=i,++ans;
				else break;
			}
			if(s)++ans;
		}
		
		printf("%d\n",ans);
	}
	return 0;
}

