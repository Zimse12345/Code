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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,len,vis[N],ans[N],k1[N],k2[N];
char s[N];
vector<int> st[N],ed[N];

int sol(int x){
	if(vis[x])return ans[x];
	vis[x]=1;
	int E=k2[x];
	if(st[E].size()==0){
		ans[x]=1;
//		printf("[%d %d]\n",x,ans[x]);
		return 1;
	}
//	printf("*");
	int y0=0,y1=0,y2=0;
	for(int i=0;i<st[E].size();i++){
		int to=st[E][i];
//		printf("(%d -> %d)\n",x,to);
		sol(to);
		if(ans[to]==0)y0=1;
		if(ans[to]==1)y1=1;
		if(ans[to]==2)y2=1;
	}
	
	if(y1)ans[x]=2;
	else if(y0==0)ans[x]=1;
//	printf("[%d %d %d %d %d]\n",x,ans[x],y0,y1,y2);
	return ans[x];
}

int C(int x){
	char v=s[x];
	if('a'<=v&&v<='z')return v-'a'+1;
	else return 26+v-'A'+1;
}

int main(){
	freopen("d.in","r",stdin);
	freopen("d1.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1),len=strlen(s+1);
		
		int A=0,B=0;
		for(int j=1;j<=3;j++)A=A*30+C(j),B=B*30+C(len-3+j);
		k2[i]=B,st[A].push_back(i);
//		printf("[%d %d]\n",A,B);
	}
	for(int i=1;i<=n;i++)sol(i);
	for(int i=1;i<=n;i++){
		if(ans[i]==1)printf("Takahashi\n");
		if(ans[i]==2)printf("Aoki\n");
		if(ans[i]==0)printf("Draw\n");
	}
	return 0;
}

