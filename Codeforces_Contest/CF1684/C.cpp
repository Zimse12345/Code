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
int T,n,m,a[N];
vector<int> v[N];

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		int I=0,J=0,tag=0;
		for(int i=1;i<=n;i++){
			v[i].push_back(0);
			for(int j=1;j<=m;j++)a[j]=read(),v[i].push_back(a[j]);
			if(I)continue;
			int L=0,R=0;
			for(int j=1;j<=m;j++)if(a[j]<a[j-1]){
				L=j-1;
				while(a[L-1]==a[L])--L;
				break;
			}
			a[m+1]=INF;
			for(int j=m;j>=1;j--)if(a[j]>a[j+1]){
				R=j+1;
				while(a[R+1]==a[R])++R;
				break;
			}
			I=L,J=R;
		}
		if(!I)I=J=1;
		for(int i=1;i<=n;i++){
			swap(v[i][I],v[i][J]);
			for(int j=1;j<=m;j++)if(v[i][j]<v[i][j-1])tag=1;
		}
		if(tag)printf("%d\n",-1);
		else printf("%d %d\n",I,J);
		for(int i=1;i<=n;i++)v[i].resize(0);
	}
	return 0;
}

