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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,n,L[N],R[N];
vector<int> a[N],b[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i].resize(0),b[i].resize(0);
		for(int i=1,l,r;i<=n;i++)l=read(),r=read(),a[l].push_back(r),b[r].push_back(l),L[i]=l,R[i]=r;
		for(int i=1,l,r;i<=n;i++){
			l=L[i],r=R[i];
			if(l==r){
				printf("%d %d %d\n",l,l,l);
				continue;
			}
			int p1=0,p2=n+1;
			for(unsigned j=0;j<a[l].size();j++)if(a[l][j]<r)p1=max(p1,a[l][j]);
			for(unsigned j=0;j<b[r].size();j++)if(b[r][j]>l)p2=min(p2,b[r][j]);
			if(p1!=0)printf("%d %d %d\n",l,r,p1+1);
			else printf("%d %d %d\n",l,r,p2-1);
		}
	}
	return 0;
}

