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
int T,n,a[N],b[N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return x>A.x;}
};

vector<node> p[N];
priority_queue<node> q;

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)p[i].resize(0);
		for(int i=1;i<=n;i++){
			b[i]=read();
			int id=i,l=i/(b[i]+1)+1,r=(b[i]==0?n:i/b[i]);
			p[l].push_back(node(r,id));
		}
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++){
			for(unsigned j=0;j<p[i].size();j++)q.push(p[i][j]);
			node t=q.top();q.pop();
			a[t.y]=i;
		}
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}

