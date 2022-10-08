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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],dp[N],c[N];
struct node{int x,y,id;node(int x=0,int y=0,int id=0):x(x),y(y),id(id){}};
vector<node> v[N];
vector<int> ans,p[N];

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1,e,t,p;i<=m;i++)e=read(),t=read(),p=read(),v[e].push_back(node(t,p,i)),c[i]=p;
		int t=0;
		ans.clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=100;j++)dp[j]=INF,p[j].clear();
			for(int j=0;j<signed(v[i].size());j++){
				for(int k=100;k>=v[i][j].y;k--){
					int w=dp[k-v[i][j].y]+v[i][j].x;
					if(w<dp[k])dp[k]=w,p[k]=p[k-v[i][j].y],p[k].push_back(v[i][j].id);
				}
				for(int k=99;k>=1;k--)if(dp[k]>dp[k+1])dp[k]=dp[k+1],p[k]=p[k+1];
			}
			int Min=dp[100],pos=100;
			t+=Min;
			if(t>a[i]){t=-1;break;}
			for(int j=0;j<signed(p[pos].size());j++)ans.push_back(p[pos][j]);
		}
		for(int i=1;i<=n;i++)v[i].clear();
		if(t==-1)printf("-1\n");
		else{
			printf("%d\n",signed(ans.size()));
			for(int i=0;i<signed(ans.size());i++)printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}

