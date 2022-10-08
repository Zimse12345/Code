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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,k,ans;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{
		if(x==A.x)return y<A.y;
		return x<A.x;
	}
}p[N];
map<node,int> v;
map<int,int> s1,s2;

signed main(){
	n=read(),k=read();
	for(int i=1,x,y;i<=n;i++){
		x=read(),y=read();
		p[i]=node(x,y);
		++v[p[i]];
		if(v[p[i]]>=k){
			printf("Infinity\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			vector<int> q;
			q.push_back(i),q.push_back(j);
			for(int k=1;k<=n;k++)if(k!=i&&k!=j){
				if((p[i].y-p[j].y)*(p[i].x-p[k].x)==(p[i].y-p[k].y)*(p[i].x-p[j].x)){
					q.push_back(k);
				}
			}
			if(q.size()<unsigned(k))continue;
			sort(q.begin(),q.end());
			int h1=0,h2=0;
			for(unsigned j=0;j<q.size();j++){
				h1=(h1*301+q[j])%Mod,h2=(h2*303+q[j])%Mod;
			}
			if(!s1[h1]||!s2[h2])++ans;
			s1[h1]=s2[h2]=1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

