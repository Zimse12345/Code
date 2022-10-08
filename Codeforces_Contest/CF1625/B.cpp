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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=1e9+7,INF=1e9+7;
inline void yes(){printf("YES\n");return;}
inline void no(){printf("NO\n");return;}
int T,n,a[N];
vector<int> v[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int ans=-1;
		for(int i=1;i<=n;i++)a[i]=read(),v[a[i]].push_back(i);
		for(int i=1;i<=n;i++)if(v[a[i]].size()>0){
			int x=a[i];
			for(unsigned j=1;j<v[x].size();j++){
				ans=max(ans,n-v[x][j]+v[x][j-1]);
			}
			v[a[i]].resize(0);
		}
		printf("%d\n",ans);
	}
	return 0;
}

