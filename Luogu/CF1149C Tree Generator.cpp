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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
char s[N];
int n,m,v[N];

struct node{
	int mx,ra,lb,rab,lab,mab,sum;
	node(int mx=0,int ra=0,int lb=0,int rab=0,int lab=0,int mab=0,int sum=0):
	mx(mx),ra(ra),lb(lb),rab(rab),lab(lab),mab(mab),sum(sum){}
}t[N*4];

void pushup(int id){
	t[id].mx=max(max(t[Lid].mx,t[Rid].mx),max(t[Lid].ra+max(t[Rid].lb,t[Rid].lab),t[Lid].rab+t[Rid].lb));
	t[id].ra=max(t[Rid].ra,-t[Rid].sum+t[Lid].ra);
	t[id].lb=max(t[Lid].lb,t[Lid].sum+t[Rid].lb);
	t[id].rab=max(t[Rid].rab,max(t[Rid].mab+t[Lid].ra,t[Rid].sum+t[Lid].rab));
	t[id].lab=max(t[Lid].lab,max(t[Lid].mab+t[Rid].lb,-t[Lid].sum+t[Rid].lab));
	t[id].mab=max(t[Lid].mab+t[Rid].sum,-t[Lid].sum+t[Rid].mab);
	t[id].sum=t[Lid].sum+t[Rid].sum;
	return;
}

void build(int L,int R,int id){
	if(L==R)t[id]=node(max(v[L],0),max(-v[L],0),max(v[L],0),1,1,1,v[L]);
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		pushup(id);
	}
	return;
}

void update(int L,int R,int id,int p){
	if(L==R)t[id]=node(max(v[L],0),max(-v[L],0),max(v[L],0),1,1,1,v[L]);
	else{
		if(p<=M)update(L,M,Lid,p);
		else update(M+1,R,Rid,p);
		pushup(id);
	}
	return;
}

signed main(){
	n=read(),m=read();
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)v[i]=(s[i]=='(')?1:-1;
	build(1,n,1);
	printf("%d\n",t[1].mx);
	while(m--){
		int l=read(),r=read();
		swap(v[l],v[r]);
		update(1,n,1,l);
		update(1,n,1,r);
		printf("%d\n",t[1].mx);
	}
	return 0;
}

