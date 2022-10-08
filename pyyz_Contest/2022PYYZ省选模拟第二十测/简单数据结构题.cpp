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
#define M ((L+R)>>1)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,ty,a[N],pr[N],Ans[N];
int ch[N*64][2],mx[N*64],tag[N*64],rt[N],tot;

void update(int L,int R,int& id,int _id,int l,int r){
	if(!id)id=++tot;tag[id]=tag[_id];
	if(l<=L&&r>=R)++tag[id],Lid=ch[_id][0],Rid=ch[_id][1];
	else if(r<=M)Rid=ch[_id][1],update(L,M,Lid,ch[_id][0],l,r);
	else if(l>M)Lid=ch[_id][0],update(M+1,R,Rid,ch[_id][1],l,r);
	else update(L,M,Lid,ch[_id][0],l,r),update(M+1,R,Rid,ch[_id][1],l,r);
	mx[id]=max(mx[Lid],mx[Rid])+tag[id];
	return;
}

int query(int L,int R,int id,int l,int r){
	if(!id||r<L||R<l)return 0;
	if(l<=L&&r>=R)return mx[id];
	return max(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r))+tag[id];
}

signed main(){
	n=read(),q=read(),ty=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		int t=i;
		while(t>1&&a[i]>a[t-1])t=pr[t-1];
		pr[i]=t;
		update(1,n,rt[i],rt[i-1],t,i);
	}
	for(int i=1,l,r,ans=0;i<=q;i++){
		l=(read()+ty*ans+n-1)%n+1,r=(read()+ty*ans+n-1)%n+1;
		if(r<l)swap(l,r);
		ans=query(1,n,rt[r],l,r);
		printf("%d\n",ans);
	}
	return 0;
}

