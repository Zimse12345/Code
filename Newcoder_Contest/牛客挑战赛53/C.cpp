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

const int N=1e2+7,Mod=1e9+7,INF=1e9+7;
int n,m,d[N][N];
unsigned A[68000000];
ll ans;
int x[N];
int _2[1200000];

int main(){
	_2[1]=0;
	int m=1;
	for(int i=1;i<=26;i++){
		m*=2;
		if(m<1200000)_2[m]=i;
		//else printf("[%d %d]\n",i,m);
	}
	n=read(),m=read();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)A[(1<<i)|(1<<j)]=1;
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),d[u][v]=d[v][u]=1,A[(1<<u)|(1<<v)]=0;
	for(int i=0;i<n;i++){
		x[i]=(1<<n)-1;
		for(int j=0;j<n;j++)if(i!=j&&d[i][j]==1)x[i]^=(1<<j);
	}
	A[0]=1;
	ll p=1;
	int kk,k,y,z,tag;
	unsigned *w;
	for(int i=0;i<n;i++)A[1<<i]=1;
	for(int j=0;j<(1<<n);j++){//2^26
		w = &A[j];
		z=j,tag=0;
		while(z){
			if(++tag>1)break;
			z^=(z&(-z));
		}
		kk=j&(-j);
		if(kk<1200000)k=_2[j&(-j)];
		else{
			if(kk<8388608){
				if(kk==2097152)k=21;
				else k=22;
			}
			else if(kk==8388608)k=23;
			else{
				if(kk==16777216)k=24;
				else if(kk==33554432)k=25;
				else k=26;
			}
		}
		y=((1<<n)-1)^x[k],*w=1;
		if(A[j^kk]==0||(j&y))*w=0;
		if(tag==1)++(*w);
		else if(tag>1){
			if((j&x[k])==j)*w=A[j^kk]+A[j^kk];
			else *w=A[(j&x[k])^kk]+A[j^kk];
			while(*w>=Mod)*w-=Mod;
		}
		ans=(ans+p*(*w))%Mod;
		p=(p*233ll)%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}
