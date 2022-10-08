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
int T,n,m;
int s[N][30],t[N][30];

int main(){
	scanf("%d",&T);
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=m;i++)for(int j=1;j<=26;j++)s[i][j]=t[i][j]=0;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c=0;
				while(c<'a'||c>'z')c=getchar();
				++s[j][c-'a'+1];
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=m;j++){
				char c=0;
				while(c<'a'||c>'z')c=getchar();
				++t[j][c-'a'+1];
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=26;j++)if(t[i][j]<s[i][j])printf("%c",'a'+j-1);
		}
		printf("\n");
	}
	return 0;
}

