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
while(qrc>='0'&&qrc<='9')qrx=qrx*10ll+qrc-48ll,qrc=getchar();return qrx*qry;}

const int N=1e2+7,INF=1e9+7;
int Mod;
struct mx{int s[15][15];};

int qm(int a,int b){
	a%=Mod,b%=Mod;
	int res=0;
	while(b){
		if(b&1ll)res=(res+a)%Mod;
		a=(a*2ll)%Mod,b/=2ll;
	}
	return res;
}

mx mul(mx A,mx B){
	mx res;
	for(int i=0;i<=14;i++)for(int j=0;j<=14;j++)res.s[i][j]=0;
	for(int i=0;i<=14;i++)for(int j=0;j<=14;j++){
		for(int k=0;k<=14;k++)res.s[i][j]=(res.s[i][j]+qm(A.s[i][k],B.s[k][j]))%Mod;
	}
	return res;
}

void print(mx jz){
	printf("\n------------------------------\n");
	for(int i=0;i<=14;i++){
		for(int j=0;j<=14;j++)printf("%lld ",jz.s[i][j]);
		printf("\n");
	}
	printf("\n------------------------------\n");
	return;
}

signed main(){
	int n,p,q,r,t,u,v,w,x,y,z;
	n=read(),Mod=read(),p=read(),q=read(),r=read(),t=read(),u=read(),v=read(),w=read(),x=read(),y=read(),z=read();
	int s[15][15]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,q,p,0,0,1,0,0,1,1,t,r,0,0},
	{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,v,u,0,0,1,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
	{0,0,0,1,0,0,1,0,y,x,2,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,2,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,z,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,w}};
	mx ans,X;
	for(int i=0;i<=14;i++)for(int j=0;j<=14;j++)X.s[i][j]=s[i][j],ans.s[i][j]=0;
	int st[15]={0,0,1,3,0,1,3,0,1,3,1,1,1,z,w};
	for(int i=0;i<=14;i++)ans.s[i][1]=st[i];
	while(n){
		if(n&1ll)ans=mul(X,ans);
		X=mul(X,X),n/=2;
	}
	//print(ans);
	printf("nodgd %lld\nCiocio %lld\nNicole %lld\n",ans.s[1][1],ans.s[4][1],ans.s[7][1]);
	return 0;
}
