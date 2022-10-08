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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,k,f[N];
vector<int> sum[640];

signed main(){
	n=read(),k=read();
	sum[0].resize(1);
	sum[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=639;j;j--){
			if(i%(k+j-1)<signed(sum[j-1].size())){
				f[i]=(f[i]+sum[j-1][i%(k+j-1)])%Mod;
				if(i%(k+j)>n/2+1)continue;
				if(i%(k+j)>=signed(sum[j].size()))sum[j].resize(i%(k+j)+1);
				sum[j][i%(k+j)]=(sum[j][i%(k+j)]+sum[j-1][i%(k+j-1)])%Mod;
			}
		}
		printf("%d ",f[i]);
	}
	printf("\n");
	return 0;
}

