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
int n,k,X,v[N][21],s[N],ans=INF,anss[N];

struct node{
	int x,y,id;
	node(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
	bool operator < (const node& A)const{return x<A.x;}
}p[N];

inline int Abs(int x,int y){
	return x<y?y-x:x-y;
}

void dfs(int x){
	if(x==n){
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)res=max(res,v[i][s[i]]+v[j][s[j]]+X*(Abs(s[i],s[j])));
		}
		if(res<ans){
			ans=res;
			for(int i=1;i<=n;i++)anss[i]=s[i];
		}
	}
	else for(int i=1;i<=k;i++)s[x+1]=i,dfs(x+1);
	return;
}

signed main(){
//	freopen("B.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read(),k=read(),X=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)v[i][j]=read();
	}

	if(k==1){
		int mx=0,se=0;
		for(int i=1;i<=n;i++){
			if(v[i][1]>mx)se=mx,mx=v[i][1];
			else if(v[i][1]>se)se=v[i][1];
		}
		printf("%d\n",mx+se);
		for(int i=1;i<=n;i++)printf("1 ");
		printf("\n");
		return 0;
	}
	
	else if(k==2){
		int ansty=0,ansx=0,ansy=0;
		for(int i=1;i<=n;i++)p[i]=node(v[i][1],v[i][2],i);
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++){
			int mx=0,se=0;
			for(int j=n;j>i;j--){
				if(p[j].y>mx)se=mx,mx=p[j].y;
				else if(p[j].y>se)se=p[j].y;
			}
			for(int j=i-1;j>=1;j--){
				int res=max(max(mx+se,p[i].x+p[j].x),mx+p[i].x+X);
				if(res<ans){
					ans=res;
					ansty=1,ansx=i,ansy=j;
				}
				if(p[j].y>mx)se=mx,mx=p[j].y;
				else if(p[j].y>se)se=p[j].y;
			}
			int res=max(mx+se,mx+p[i].x+X);
			if(res<ans){
				ans=res;
				ansty=1,ansx=i,ansy=0;
			}
		}
		int mx=0,se=0;
		for(int i=1;i<=n;i++){
			if(v[i][1]>mx)se=mx,mx=v[i][1];
			else if(v[i][1]>se)se=v[i][1];
		}
		if(mx+se<ans){
			ans=mx+se;
			ansty=3;
		}
		mx=0,se=0;
		for(int i=1;i<=n;i++){
			if(v[i][2]>mx)se=mx,mx=v[i][2];
			else if(v[i][2]>se)se=v[i][2];
		}
		if(mx+se<ans){
			ans=mx+se;
			ansty=4;
		}
		if(ansty==1){
			for(int i=1;i<=ansy;i++)anss[p[i].id]=1;
			for(int i=ansy+1;i<ansx;i++)anss[p[i].id]=2;
			anss[p[ansx].id]=1;
			for(int i=ansx+1;i<=n;i++)anss[p[i].id]=2;
		}
		if(ansty==3){
			for(int i=1;i<=n;i++)anss[i]=1;
		}
		if(ansty==4){
			for(int i=1;i<=n;i++)anss[i]=2;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)printf("%d ",anss[i]);
		printf("\n");
		return 0;
	}
		dfs(0);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)printf("%d ",anss[i]);
		printf("\n");
		return 0;
	return 0;
}

