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
int n,k;
char s[N][N];

int dfs(int x){
//	printf(">%d\n",x);
	int res=0;
	if(x==k)return 1;
	if(x==0)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(s[i][j]=='.'){
		s[i][j]='@';
//		printf("(s[%d][%d]=%c)\n",i,j,s[i][j]);
		res+=dfs(x+1);
		s[i][j]='.';
	}
	if(x>0)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(s[i][j]=='.'&&(s[i-1][j]=='@'||s[i+1][j]=='@'||s[i][j-1]=='@'||s[i][j+1]=='@')){
		s[i][j]='@';
//		printf("[%d %d]\n",i,j);
		res+=dfs(x+1);
		s[i][j]='.';
	}
	return res;
}

int main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	int res=dfs(0);
	for(int i=2;i<=k;i++)res/=i;
	printf("%d\n",res);
	return 0;
}

