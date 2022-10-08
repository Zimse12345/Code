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

const int N=8e5+7,Mod=998244353,INF=1e9+7;
char s[N],v[N];
int k,n,cnt,vis[N];

struct p{
	char S[10];
	bool operator < (const p& A)const{
		for(int i=1;i<=n;i++){
			if(S[i]<A.S[i])return 1;
			if(S[i]>A.S[i])return 0;
		}
		return 0;
	}
	bool operator == (const p& A)const{
		for(int i=1;i<=n;i++)if(S[i]!=A.S[i])return 0;
		return 1;
	}
}t[N];

void f(int m){
	if(m==n){
		++cnt;
		for(int i=1;i<=n;i++)t[cnt].S[i]=v[i];
		return;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]=1,v[i]=s[m+1];
		f(m+1);
		vis[i]=0;
	}
	return;
}

int main(){
	char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while(c<='z'&&c>='a')s[++n]=c,c=getchar();
	scanf("%d",&k);
	f(0);
	sort(t+1,t+cnt+1);
	for(int i=1;i<=cnt;i++){
		if(t[i]==t[i-1])continue;
		--k;
		if(k==0){
			for(int j=1;j<=n;j++)printf("%c",t[i].S[j]);
			printf("\n");
			return 0;
		}
	}
	return 0;
}
