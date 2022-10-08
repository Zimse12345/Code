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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=1e9+7,INF=1e9+7;

struct matrix{
	int v[3][3];
	void init(){
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)v[i][j]=0;
		return;
	}
	void see(){
		printf("\n");
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)printf("%3lld ",v[i][j]);
			printf("\n");
		}
		printf("\n");
	}
};

matrix mul(matrix A,matrix B){
	matrix res;
	res.init();
	for(int i=0;i<3;i++)for(int j=0;j<3;j++){
		for(int k=0;k<3;k++)(res.v[i][j]+=A.v[i][k]*B.v[k][j])%=Mod;
	}
	return res;
}

matrix qp(matrix A,int k){
	matrix res;
	res.init(),res.v[0][0]=res.v[1][1]=res.v[2][2]=1;
	while(k){
		if(k&1ll)res=mul(res,A);
		A=mul(A,A),k/=2;
	}
	return res;
}

signed main(){
	int T=read();
	while(T--){
		int n=read()-1,k=read();
		matrix I;
		I.init(),I.v[0][0]=I.v[0][1]=I.v[1][0]=I.v[2][0]=I.v[2][2]=1;
		matrix B;
		B.init();
		if(n==0){
			B.v[0][0]=1;
		}
		else{
			matrix A=qp(I,n-1);
			B.v[1][1]=A.v[2][0];
			A=mul(A,I);
			B.v[0][1]=B.v[1][0]=A.v[2][0];
			A=mul(A,I);
			B.v[0][0]=A.v[2][0];
		}
		B.v[1][1]++;
		B=qp(B,k);
		printf("%lld\n",B.v[0][0]);
	}
	
	return 0;
}

