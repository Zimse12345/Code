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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int m,n,add[N],del[N],f[N][N],vis[N][N];
char s[N];

int dp(int l,int r){
	if(vis[l][r])return f[l][r];
	if(l>=r)return 0;
	if(s[l]==s[r])f[l][r]=dp(l+1,r-1);
	else f[l][r]=min(dp(l,r-1)+min(add[s[r]-'a'],del[s[r]-'a']),dp(l+1,r)+min(add[s[l]-'a'],del[s[l]-'a']));
	vis[l][r]=1;
	return f[l][r];
}

int main(){
	m=read(),n=read();
	scanf("%s",s+1);
	for(int i=1;i<=m;i++){
		char c=getchar();
		while(c<'a'||c>'z')c=getchar();
		add[c-'a']=read(),del[c-'a']=read();
	}
	printf("%d\n",dp(1,n));
	return 0;
}
