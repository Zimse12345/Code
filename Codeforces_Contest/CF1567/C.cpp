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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],v,f[N][2][2];

int main(){
	T=read();
	while(T--){
		v=read(),n=0;
		while(v)a[++n]=v%10,v/=10;
		f[0][0][0]=1;
		for(int i=1;i<=n;i++){
			f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=0;
			for(int A=0;A<=9;A++)for(int B=0;B<=9;B++){
				if(A+B==a[i])f[i][0][0]+=f[i-1][0][0],f[i][1][0]+=f[i-1][0][1];
				if(A+B+1==a[i])f[i][0][0]+=f[i-1][1][0],f[i][1][0]+=f[i-1][1][1];
				if(A+B>9&&(A+B)%10==a[i])f[i][0][1]+=f[i-1][0][0],f[i][1][1]+=f[i-1][0][1];
				if(A+B+1>9&&(A+B+1)%10==a[i])f[i][0][1]+=f[i-1][1][0],f[i][1][1]+=f[i-1][1][1];
			}
		}
		printf("%d\n",f[n][0][0]-2);
	}
	return 0;
}

