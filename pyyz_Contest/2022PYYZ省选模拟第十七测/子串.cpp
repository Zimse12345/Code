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
#include <unordered_map>

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=20,Mod=1e9+7,hs=10001777,INF=1e9+7;
int T,n,len[N],cnt,d[2560][2560],f[2560][2560],du[2560],fr[N][N];
char s[N][N];
struct node{int p[N];};
unordered_map<int,int> vis;

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

int inv(int x){
	return qp(x,Mod-2);
}

int dfs(node u){
	int h=0,tag=0;
	for(int i=1;i<=n;i++){
		h=h*hs+u.p[i];
		if(u.p[i]==len[i])tag=1;
	}
	if(vis[h])return vis[h];
	vis[h]=++cnt;
	if(tag)++d[1][vis[h]],++du[vis[h]];
	else{
		for(char c='a';c<='z';c++){
			node v=u;
			for(int i=1;i<=n;i++){
				while(v.p[i]&&c!=s[i][v.p[i]+1])v.p[i]=fr[i][v.p[i]];
				if(c==s[i][v.p[i]+1])++v.p[i];
			}
			int vid=dfs(v);
			++d[vid][vis[h]],++du[vis[h]];
		}
	}
	return vis[h];
}

signed main(){
	T=read();
	while(T--){
		for(int i=0;i<=cnt;i++){
			for(int j=0;j<=cnt;j++)d[i][j]=0,f[i][j]=0;
			du[i]=0;
		}
		n=read(),vis.clear(),cnt=1;
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1),len[i]=strlen(s[i]+1);
			for(int j=2,k=0;j<=len[i];j++){
				while(k&&s[i][k+1]!=s[i][j])k=fr[i][k];
				if(s[i][k+1]==s[i][j])fr[i][j]=++k;
				else fr[i][j]=0;
			}
		}
		node u;
		for(int i=1;i<=n;i++)u.p[i]=0;
		dfs(u);
		for(int i=1;i<=cnt;i++){
			for(int j=2;j<=cnt;j++)if(d[i][j])f[i][j]=-(inv(du[j])*d[i][j])%Mod;
			++f[i][i];
			if(i==2)f[i][0]=1;
		}
		for(int i=1;i<=cnt;i++){
			int t=0;
			for(int j=i;j<=cnt;j++)if(f[j][i]!=0){t=j;break;}
			for(int j=0;j<=cnt;j++)swap(f[i][j],f[t][j]);
			for(int j=1;j<=cnt;j++)if(j!=i){
				int x=f[j][i]*inv(f[i][i])%Mod;
				for(int k=0;k<=cnt;k++)f[j][k]=(f[j][k]-f[i][k]*x)%Mod;
			}
			int x=f[i][i];
			for(int j=0;j<=cnt;j++)f[i][j]=(f[i][j]*inv(x))%Mod;
		}
		int ans=0;
		for(int i=1;i<=cnt;i++)if(i!=1)ans=(ans+f[i][0])%Mod;
		printf("%lld\n",(ans+Mod-1)%Mod);
	}
	return 0;
}

