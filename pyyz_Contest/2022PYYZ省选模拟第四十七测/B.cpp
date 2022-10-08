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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,dis[N][N],L;
set<int> S[17000][15];

signed main(){
	n=read(),L=read();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dis[i][j]=read();
		}
	}
	for(int I=0;I<n;I++){
		for(int i=0;i<n;i++)S[1<<i][i].insert(dis[I][i]);
		for(int i=1;i<(1<<n);i++){
			for(int u=0;u<n;u++)if(i&(1<<u)){
				if(S[i][u].count(L-dis[u][I])){
					printf("possible\n");
					return 0;
				}
				for(int v=0;v<n;v++)if(!(i&(1<<v))){
					for(set<int>::iterator it=S[i][u].begin();it!=S[i][u].end();it++){
						if((*it)+dis[u][v]>L)break;
						S[i|(1<<v)][v].insert((*it)+dis[u][v]);
					}
				}
			}
		}
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				S[i][j].clear();
			}
		}
	}
	printf("impossible\n");
	return 0;
}

