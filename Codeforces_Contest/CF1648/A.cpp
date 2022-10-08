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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],ans;
vector<int> r[N],c[N],sr[N],sc[N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1,x;j<=m;j++)x=read(),r[x].push_back(i),c[x].push_back(j);
	}
	for(int i=1;i<N;i++){
		if(r[i].size()){
			sort(r[i].begin(),r[i].end());
			int s=0;
			for(unsigned j=0;j<r[i].size();j++)s+=r[i][j],sr[i].push_back(s);
			for(unsigned j=0;j<r[i].size();j++){
				ans+=r[i][j]*(j+1)-sr[i][j];
			}
		}
		if(c[i].size()){
			sort(c[i].begin(),c[i].end());
			int s=0;
			for(unsigned j=0;j<c[i].size();j++)s+=c[i][j],sc[i].push_back(s);
			for(unsigned j=0;j<c[i].size();j++){
				ans+=c[i][j]*(j+1)-sc[i][j];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

