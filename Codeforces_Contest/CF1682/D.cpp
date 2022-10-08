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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,pos[N];
char s[N];
vector<int> p;

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		int t=0;
		for(int i=1;i<=n;i++)if(s[i]=='1')pos[++t]=i;
		if(t==0||(t&1)){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i+1<t;i+=2){
			for(int j=pos[i];j<pos[i+1];j++)printf("%d %d\n",j,j+1);
		}
		p.clear();
		for(int i=pos[t];i<=n;i++)p.push_back(i);
		for(int i=1;i<pos[1];i++)p.push_back(i);
		for(int i=2;i<t;i+=2){
			for(int j=pos[i];j<pos[i+1];j++)p.push_back(j);
		}
		for(int j=pos[t]-1;j>=pos[t-1];j--)p.push_back(j);
		for(unsigned i=0;i+1<p.size();i++)printf("%d %d\n",p[i],p[i+1]);
	}
	return 0;
}

