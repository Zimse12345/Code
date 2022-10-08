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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int n,a[N],q;

struct node{
	int pre,suf,sum,mx;
	node(int pre=0,int suf=0,int sum=0,int mx=0):pre(pre),suf(suf),sum(sum),mx(mx){}
};

vector<node> t[N];

node merge(node a,node b){
	return node(max(a.pre,a.sum+b.pre),max(b.suf,b.sum+a.suf),a.sum+b.sum,max(max(a.mx,b.mx),a.suf+b.pre));
}

void build(int L,int R,int id,int x){
	t[id].resize(1<<x);
	if(L==R)t[id][0]=node(a[L],a[L],a[L],a[L]);
	else{
		build(L,M,Lid,x-1),build(M+1,R,Rid,x-1);
		for(int i=0;i<(1<<(x-1));i++){
			t[id][i]=merge(t[Lid][i],t[Rid][i]);
			t[id][i|(1<<(x-1))]=merge(t[Rid][i],t[Lid][i]);
		}
	}
	return;
}

signed main(){
	n=read();
	for(int i=0;i<(1<<n);i++)a[i]=read();
	build(0,(1<<n)-1,1,n);
	int s=0;
	q=read();
	while(q--){
		s^=(1<<read());
		printf("%lld\n",max(0ll,t[1][s].mx));
	}
	return 0;
}

