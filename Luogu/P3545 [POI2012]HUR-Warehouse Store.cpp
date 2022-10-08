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

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],b[N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;} };
priority_queue<node> Q;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,s=0;i<=n;i++){
		b[i]=read(),s+=a[i];
		if(s>=b[i]){s-=b[i],Q.push(node(b[i],i));}
		else if(!Q.empty()&&s+Q.top().x>=b[i]&&b[i]<Q.top().x){
			int x=Q.top().x;Q.pop();
			s+=x-b[i],Q.push(node(b[i],i));
		}
	}
	printf("%d\n",signed(Q.size()));
	while(!Q.empty())printf("%lld ",Q.top().y),Q.pop();
	return 0;
}

