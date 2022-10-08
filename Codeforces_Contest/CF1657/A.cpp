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

const int N=1e3+7,M=500,INF=1e9+7;
int T,s[N][N];

signed main(){
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)s[i][j]=INF;
	s[M][M]=0;
	for(int a=0;a<=200;a++){
		for(int b=0;b<=200;b++){
			int sq=sqrt(a*a+b*b);
			if(sq*sq==a*a+b*b){
				for(int i=300;i<N-300;i++){
					for(int j=300;j<N-300;j++){
						s[i][j]=min(s[i][j],1+min(min(s[i+a][j+b],s[i+a][j-b]),min(s[i-a][j+b],s[i-a][j-b])));
					}
				}
			}
		}
	}
	T=read();
	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++)printf("%d ",s[i+M][j+M]);
		printf("\n");
	}
	while(T--){
		int x=read(),y=read();
		printf("%d\n",s[x+M][y+M]);
	}
	return 0;
}

