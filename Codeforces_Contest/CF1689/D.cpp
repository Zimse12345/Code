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
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,T,t[N],dis[N][N];
char s[N][N];

struct segmenttree{
int mx[N*16];
void build(int L,int R,int id){
	mx[id]=-INF;
	if(L!=R)build(L,M,Lid),build(M+1,R,Rid);
	return;
}

void upt(int L,int R,int id,int x,int y){
	mx[id]=max(mx[id],y);
	if(L!=R){
		if(x<=M)upt(L,M,Lid,x,y);
		else upt(M+1,R,Rid,x,y);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(r<L||R<l)return -INF;
	if(l<=L&&r>=R)return mx[id];
	return max(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}
}A,B;

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)dis[i][j]=0;
		}
		
		A.build(1,m,1),B.build(1,m,1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)if(s[i][j]=='B'){
				if(!t[j]){
					t[j]=1;
					A.upt(1,m,1,j,n-i+1+m-j+1);
					B.upt(1,m,1,j,n-i+1+j);
				}
			}
			for(int j=1,x;j<=m;j++){
				x=A.query(1,m,1,1,j);
				dis[i][j]=max(dis[i][j],x-(n-i+1)-(m-j+1));
				x=B.query(1,m,1,j,m);
				dis[i][j]=max(dis[i][j],x-(n-i+1)-j);
			}
		}
		for(int j=1;j<=m;j++)t[j]=0;
		A.build(1,m,1),B.build(1,m,1);
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++)if(s[i][j]=='B'){
				if(!t[j]){
					t[j]=1;
					A.upt(1,m,1,j,i+m-j+1);
					B.upt(1,m,1,j,i+j);
				}
			}
			for(int j=1,x;j<=m;j++){
				x=A.query(1,m,1,1,j);
				dis[i][j]=max(dis[i][j],x-i-(m-j+1));
				x=B.query(1,m,1,j,m);
				dis[i][j]=max(dis[i][j],x-i-j);
			}
		}
		int ax=1,ay=1,md=dis[1][1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)if(dis[i][j]<md){
				md=dis[i][j],ax=i,ay=j;
			}
		}
		for(int i=1;i<=m;i++)t[i]=0;
		printf("%d %d\n",ax,ay);
	}
	return 0;
}

