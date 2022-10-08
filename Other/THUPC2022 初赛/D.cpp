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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}}ans[N];
int n,a[N],tot,vis[N],m;
vector<int> r[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)if(a[i]!=i&&!vis[i]){
		++tot;
		int p=i;
		r[tot].push_back(p);
		while(a[p]!=i){
			p=a[p],vis[p]=1;
			r[tot].push_back(p);
		}
	}
	if(!tot){
		printf("0 0\n");
		return 0;
	}
	for(int i=1;i<=tot;i++){
		for(unsigned j=0;j+1<r[i].size();j++)ans[++m]=node(n+1,r[i][j]);
	}
	for(int i=tot;i>=1;i--){
		ans[++m]=node(n+2,r[i][r[i].size()-1]);
		ans[++m]=node(n+2,r[i][0]);
	}
	ans[++m]=node(n+1,r[tot][r[tot].size()-1]);
	ans[++m]=node(n+1,n+2);
	printf("%d %d\n",2,m);
	for(int i=1;i<=m;i++)printf("%d %d\n",ans[i].x,ans[i].y);
//	int k=0,m=0;
//	for(int i=1;i<=tot;i++){
//		k+=r[i].size();
//		printf("(%d %d) ",i,r[i].size());
//		for(int j=0;j<r[i].size();j++)printf("r[%d][%d] = %d ",i,j,r[i][j]);
//		printf("\n");
//	}
//	k+=(tot+1)/2;
//	while(m*(m-1)<tot)++m;
//	printf("%d %d\n",m,k);
//	int a=1,b=2;
//	for(int i=1;i*2-1<=tot;i++){
//		for(unsigned j=0;j<r[i*2-1].size();j++)printf("%d %d\n",r[i*2-1][j],a+n),printf("r[%d][%d] = %d\n",i*2-1,j,r[i*2-1][j]);
//		for(unsigned j=0;j<r[i*2].size();j++)printf("%d %d\n",r[i*2][j],b+n);
//		printf("%d %d\n",a+n,b+n);
//		printf("%d %d\n",r[i*2-1][0],b+n);
//		if(i*2<=tot)printf("%d %d\n",r[i*2][0],a+n);
//		++b;
//		if(b==m)++a,b=a+1;
//	}
	return 0;
}

