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

const int N=5e3+7,Mod=998244353,INF=1e12+7;
int n,k,m,a[N],f[N][N],ans=-INF;
deque<int> q[N];

signed main(){
	n=read(),k=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<=m;i++)f[0][i]=-INF;
	f[0][0]=0,q[0].push_back(0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++)f[i][j]=-INF;
		for(int j=m-1;j>=0;j--){
			while(!q[j].empty()&&i-q[j].back()>k)q[j].pop_back();
			if(!q[j].empty())f[i][j+1]=f[q[j].back()][j]+a[i];
			else continue;
			while(!q[j+1].empty()&&f[q[j+1].front()][j+1]<f[i][j+1])q[j+1].pop_front();
			q[j+1].push_front(i);
		}
	}
	for(int i=n-k+1;i<=n;i++)ans=max(ans,f[i][m]);
	if(ans<0)ans=-1;
	printf("%lld\n",ans);
	return 0;
}
