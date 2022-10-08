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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e16;
int n,m,a[N],b[N],c[N],ans=-INF;

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return x<A.x;}
};
priority_queue<int> Q;

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	sort(b+1,b+m+1);
	for(int l=1;l<=n;l++){
		int sum=0;
		while(!Q.empty())Q.pop(); 
		for(int i=1;i<=m;i++)Q.push(b[i]);
		for(int r=l;r<=n;r++){
			sum+=a[r];
			if(Q.size()){
				node p=Q.top();
				if(p.x>a[r]){
					sum+=p.x-a[r];
					Q.pop(),Q.push(a[r]);
				}
			}
			ans=max(ans,sum);
		}
	}
	printf("%lld\n",ans);
	return 0;
}

