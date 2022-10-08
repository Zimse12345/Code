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
#define Lid (ch[id][0])
#define Rid (ch[id][1])

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e9+7;
struct node{int sz,s[5];}tr[N];
int n,ch[N][2],tot=1,rt=1;
char op[100];

node merge(node A,node B){
	node res;
	res.sz=A.sz+B.sz;
	for(int i=0;i<5;i++)res.s[i]=A.s[i]+B.s[((i-A.sz)%5+5)%5];
	return res;
}

void update(int L,int R,int& id,int x,int t){
	if(!id)id=++tot;
	if(L==R){
		tr[id].sz+=t;
		if(t==1)tr[id].s[1]=L;
		else tr[id].s[1]=0;
	}
	else{
		int M=(L+R)>>1;
		if(x<=M)update(L,M,Lid,x,t);
		else update(M+1,R,Rid,x,t);
		tr[id]=merge(tr[Lid],tr[Rid]);
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,x;i<=n;i++){
		scanf("%s",op+1);
		if(op[1]=='a'){
			x=read();
			update(1,1e9,rt,x,1);
		}
		else if(op[1]=='d'){
			x=read();
			update(1,1e9,rt,x,-1);
		}
		else printf("%lld\n",tr[1].s[3]);
	}
	return 0;
}

