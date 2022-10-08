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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,color[N],f[N],ccnt[N],sum[N];
vector<int> s[N];
deque<int> Q[N];

int calc(int x,int y){
	int t=sum[x]-sum[y];
	if(t<0)t=-t;++t;
	return t*t*color[x]+f[x-1];
}

int md(int x,int y){//R_max x(R)>=y(R)
	int c=color[x];
	int L=0,R=s[c].size()-1,res=-1;
	while(L<=R){
		int M=(L+R)>>1;
		if(calc(x,s[c][M])>=calc(y,s[c][M]))res=M,L=M+1;
		else R=M-1;
	}
	if(res!=-1)return s[c][res];
	return 0;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)color[i]=read(),s[color[i]].push_back(i),sum[i]=++ccnt[color[i]];
	for(int i=1,c;i<=n;i++){
		c=color[i];
		while(Q[c].size()>1){
			int x=Q[c].front();
			Q[c].pop_front();
			int y=Q[c].front();
			if(md(x,y)>md(i,x)){
				Q[c].push_front(x);
				break;
			} 
		}
		Q[c].push_front(i);
		while(Q[c].size()>1){
			int x=Q[c].front();
			Q[c].pop_front();
			int y=Q[c].front();
			if(md(x,y)>=i){
				Q[c].push_front(x);
				break;
			}
		}
		f[i]=calc(Q[c].front(),i);
	}
	printf("%lld\n",f[n]);
	return 0;
}

