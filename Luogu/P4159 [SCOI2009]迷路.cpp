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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1000+7,Mod=2009,INF=1e9+7;
int n,m,tag[N];
char s[N][N]; 
vector<int> g[N];

struct mix{
	int m[N][N];
}G;

mix mul(mix A,mix B){
	mix res;
	int s=n;
	for(int i=1;i<=s;i++)for(int j=1;j<=s;j++)res.m[i][j]=0;
	for(int i=1;i<=s;i++){
		for(int j=1;j<=s;j++){
			for(int k=1;k<=s;k++){
				res.m[i][j]=(res.m[i][j]+A.m[i][k]*B.m[k][j])%Mod;
			}
		}
	}
	return res;
}

signed main(){
	n=read();
	int k=read(),p=n;
	for(int i=1;i<=p;i++){
		scanf("%s",s[i]+1);
		tag[0]=i;
		for(int i=1;i<=9;i++)g[tag[i-1]].push_back(++n),tag[i]=n;
		for(int j=1,w;j<=p;j++)if(s[i][j]!='0'){
			w=s[i][j]-'0';
			g[tag[w-1]].push_back(j);
		}
	}
	
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)G.m[i][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<signed(g[i].size());j++){
			int to=g[i][j];
			++G.m[to][i];
		}
	}
	
	mix res,x=G;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)res.m[i][j]=0;
	res.m[1][1]=1;
	while(k){
		if(k&1ll)res=mul(x,res);
		x=mul(x,x),k/=2;
	}
	int ans=res.m[p][1];
	printf("%lld\n",ans);
	return 0;
}
