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

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],b[N],ans,c;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;}};
priority_queue<int> Q;
priority_queue<node> P;

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read();
		if(i==1)continue;
		if(a[i]>a[1])Q.push(-(b[i]-a[i]+1));
		else P.push(node(a[i],b[i])),++c;
	}
	ans=c;
	while(!Q.empty()){
		a[1]+=Q.top(),Q.pop(),++c;
		if(a[1]<0)break;
		while(!P.empty()&&P.top().x>a[1]){
			Q.push(-(P.top().y-P.top().x+1)),P.pop(),--c;
		}
		ans=max(ans,c);
	}
	ans=n-ans;
	printf("%lld\n",ans);
	return 0;
}

