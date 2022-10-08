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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int L,R,f[N][N][N][2][2][2][2],s[N];

int sol(int x){
	int res=0;
	for(int i=11;i>=1;i--)s[i]=x%10,x/=10;
	for(int i=0;i<10;i++){
		for(int t1=0;t1<2;t1++)for(int t2=0;t2<2;t2++)for(int t3=0;t3<2;t3++)for(int t4=0;t4<2;t4++){
			f[1][0][i][t1][t2][t3][t4]=0;
		}
		if(i<=s[1])f[1][0][i][i==s[1]?1:0][0][i==4?1:0][i==8?1:0]=1;
	}
	for(int i=2;i<=11;i++){
		for(int _2=0;_2<10;_2++){
			for(int _1=0;_1<10;_1++){
				for(int t1=0;t1<2;t1++)for(int t2=0;t2<2;t2++)for(int t3=0;t3<2;t3++)for(int t4=0;t4<2;t4++){
					f[i][_2][_1][t1][t2][t3][t4]=0;
				}
			}
		}
		for(int _2=0;_2<10;_2++){
			for(int _1=0;_1<10;_1++){
				for(int t1=0;t1<2;t1++)for(int t2=0;t2<2;t2++)for(int t3=0;t3<2;t3++)for(int t4=0;t4<2;t4++){
					if(!f[i-1][_2][_1][t1][t2][t3][t4])continue;
					for(int j=0;j<10;j++){
						if(j>s[i]&&t1)break;
						int T1=t1,T2=t2,T3=t3,T4=t4;
						if(j!=s[i])T1=0;
						if(_2==_1&&_1==j)T2=1;
						if(j==4)T3=1;
						if(j==8)T4=1;
						f[i][_1][j][T1][T2][T3][T4]+=f[i-1][_2][_1][t1][t2][t3][t4];
					}
				}
			}
		}
	}
	for(int _2=0;_2<10;_2++){
		for(int _1=0;_1<10;_1++){
			for(int t1=0;t1<2;t1++)for(int t2=0;t2<2;t2++)for(int t3=0;t3<2;t3++)for(int t4=0;t4<2;t4++){
				if(t3&&t4)continue;
				if(!t2)continue;
				res+=f[11][_2][_1][t1][t2][t3][t4];
			}
		}
	}
	return res;
}

signed main(){
	L=read(),R=read();
	printf("%lld\n",sol(R)-sol(L-1));
	return 0;
}
