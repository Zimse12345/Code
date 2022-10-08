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

int T,n;
char s[N];
int t[30][30][30];

int ff(){
	for(int i=1;i<=26;i++)if(t[0][0][i]==0){
			printf("%c\n",'a'+i-1);
			return 1;
		}
		for(int i=1;i<=26;i++)for(int j=1;j<=26;j++)if(t[0][i][j]==0){
			printf("%c%c\n",'a'+i-1,'a'+j-1);
			return 1;
		}
		for(int i=1;i<=26;i++)for(int j=1;j<=26;j++)for(int k=1;k<=26;k++)if(t[i][j][k]==0){
			printf("%c%c%c\n",'a'+i-1,'a'+j-1,'a'+k-1);
			return 1;
		}
	return 0;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++){
			t[0][0][s[i]-'a'+1]=1;
			if(i<n)t[0][s[i]-'a'+1][s[i+1]-'a'+1]=1;
			if(i+1<n)t[s[i]-'a'+1][s[i+1]-'a'+1][s[i+2]-'a'+1]=1;
		}
		ff();
		for(int i=1;i<=n;i++){
			t[0][0][s[i]-'a'+1]=0;
			if(i<n)t[0][s[i]-'a'+1][s[i+1]-'a'+1]=0;
			if(i+1<n)t[s[i]-'a'+1][s[i+1]-'a'+1][s[i+2]-'a'+1]=0;
		}
	}
	return 0;
}

