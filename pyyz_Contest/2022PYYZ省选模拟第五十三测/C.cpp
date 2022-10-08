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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,a[N],vis[N];

struct pe{
	int v[10];
	bool operator < (const pe& A)const{
		for(int i=1;i<=n;i++){
			if(v[i]<A.v[i])return 1;
			if(v[i]>A.v[i])return 0;
		}
		return 0;
	}
}ans,s,k;
int gcd(int x,int y){return y?gcd(y,x%y):x; }
map<pe,bool> S;

void dfs2(pe s){
	if(S[s])return;
	if(k<s)k=s;
	S[s]=true;
	for(int i=1;i<n;i++)if(gcd(s.v[i],s.v[i+1])==1){
		swap(s.v[i],s.v[i+1]);
		dfs2(s);
		swap(s.v[i],s.v[i+1]);
	}
	return;
}

void dfs(int x){
	if(x==n){
		S.clear();
		k=s;
		dfs2(s);
		if(k<ans)ans=k;
	}
	else{
		for(int i=1;i<=n;i++)if(!vis[i]){
			s.v[x+1]=a[i],vis[i]=1;
			dfs(x+1);
		}
	}
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),ans.v[i]=INF;
	dfs(0);
	for(int i=1;i<=n;i++)printf("%d ",ans.v[i]);
	printf("\n");
	return 0;
}

