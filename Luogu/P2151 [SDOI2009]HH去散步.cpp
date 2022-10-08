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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e2+7,Mod=45989,INF=1e9+7;
int n,m,t,S,T,U[N],V[N],lk[N][N];
struct mx{
	int m[N][N];
}s,c;
vector<int> g1[N],g2[N]; 
int o(int x){
	return (x%2==0)?x+1:x-1;
}

mx mul(mx A,mx B){
	int sz=m*2;
	mx res;
	for(int i=1;i<=sz;i++)for(int j=1;j<=sz;j++)res.m[i][j]=0;
	for(int i=1;i<=sz;i++)res.m[i][i]=1;
	for(int i=1;i<=sz;i++)for(int j=1;j<=sz;j++){
		res.m[i][j]=0;
		for(int k=1;k<=sz;k++){
			res.m[i][j]=(res.m[i][j]+A.m[i][k]*B.m[k][j])%Mod;
		}
	}
	return res;
}

mx qp(mx x,int k){
	int sz=m*2;
	mx res;
	for(int i=1;i<=sz;i++)for(int j=1;j<=sz;j++)res.m[i][j]=0;
	for(int i=1;i<=sz;i++)res.m[i][i]=1;
	while(k){
		if(k&1)res=mul(res,x);
		x=mul(x,x),k/=2;
	}
	return res;
}

int inv(int x){
	int k=Mod-2,res=1;
	while(k){
		if(k&1)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

signed main(){
	n=read(),m=read(),t=read(),S=read()+1,T=read()+1;
	for(int i=1;i<=m;i++){
		U[i]=read()+1,V[i]=read()+1;
		//if(lk[U[i]][V[i]]==1)continue;
		lk[U[i]][V[i]]=lk[V[i]][U[i]]=1;
		g1[U[i]].push_back(i*2),g1[V[i]].push_back(i*2-1); //Èë±ß
		g2[U[i]].push_back(i*2-1),g2[V[i]].push_back(i*2); //³ö±ß
	}
	for(int i=1;i<=n;i++){
		for(int u=0;u<g1[i].size();u++)for(int v=0;v<g2[i].size();v++)if((g1[i][u]+1)/2!=(g2[i][v]+1)/2){
			//printf("(%d %d %d)\n",i,g2[i][u],g1[i][v]);
			++s.m[g2[i][v]][g1[i][u]];
		}
	}
	for(int i=0;i<g2[S].size();i++){
		int u=g2[S][i];
		++c.m[u][1];
	}
	mx res=qp(s,t-1);
	res=mul(res,c);
	
//	for(int i=1;i<=2*m;i++){
//		for(int j=1;j<=2*m;j++)printf("%2d ",res.m[i][j]);
//		printf("\n");
//	}
	int ans=0;
	for(int i=0;i<g1[T].size();i++){
		int u=g1[T][i];
		ans+=res.m[u][1];
	}
	//int ans=res.m[S][T]+res.m[S+n][T]+res.m[S][T+n]+res.m[S+n][T+n];
	
	printf("%lld\n",ans%Mod);
	return 0;
}
