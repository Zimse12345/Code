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
#define t tree[id]
#define tl tree[l]
#define tr tree[r]
#define I int

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,cnt,A[N],B[N],C[N],Id[N],ct,del[N];
char s[N];
struct node{int l,r,v,ky,siz;
node(int l=0,int r=0,int v=0,int ky=0,int siz=0):l(l),r(r),v(v),ky(ky),siz(siz){}}tree[N];

struct fhq{
	int rt;
	fhq(int rt=0):rt(rt){}
	void update(int id){t.siz=tree[t.l].siz+tree[t.r].siz+1;return;}
	
	void split1(int id,int x,int& l,int& r){
		if(!id){l=r=0;return;}
		if(t.v<=x)l=id,split1(t.r,x,t.r,r);
		else r=id,split1(t.l,x,l,t.l);
		update(id);return;
	}
	
	void split2(int id,int x,int& l,int& r){
		if(!id){l=r=0;return;}
		if(t.v<x)l=id,split2(t.r,x,t.r,r);
		else r=id,split2(t.l,x,l,t.l);
		update(id);return;
	}
	
	int merge(int l,int r){
		if(!l||!r)return l^r;
		if(tl.ky>=tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
		tr.l=merge(l,tr.l),update(r);return r;
	}
	
	int kth(int id,int k){
		if(k<=tree[t.l].siz)return kth(t.l,k);
		if(k>tree[t.l].siz+1)return kth(t.r,k-tree[t.l].siz-1);
		return id;
	}
	
	void Insert(int x){
		int l,r;
		split1(rt,x,l,r),tree[++cnt]=node(0,0,x,rand(),1),rt=merge(l,merge(cnt,r));
		return;
	}
	
	void Erase(int x){
		int l,r,m;
		split1(rt,x,l,r),split1(l,x-1,l,m),rt=merge(merge(l,tree[m].l),merge(tree[m].r,r));
		return;
	}
	
	int ber(int x){
		int l,r,res;
		split1(rt,x,l,r),res=tl.siz,rt=merge(l,r);
		return res;
	}
	
	int ser(int x){
		int l,r,res;
		split2(rt,x,l,r),res=tr.siz,rt=merge(l,r);
		return res;
	}
}F1,F2;

int main(){
	n=read();
	for(int i=1,a,b,c,x=0,tot=0;i<=n;i++){
		scanf("%s",s+1);
		if(s[1]=='A'){
			a=read(),b=read(),c=read();
			Id[++ct]=i;
			if(a>0){
				x=floor((c*1.0-b)/a)+1;
				F1.Insert(x);
			}
			else if(a==0&&b>c)++tot;
			else{
				x=ceil(1.0*(c-b)/a)-1;
				F2.Insert(x);
			}
			A[i]=a,B[i]=b,C[i]=c;
		}
		if(s[1]=='D'){
			x=Id[read()],a=A[x],b=B[x],c=C[x];
			if(del[x]++)continue;
			if(a>0){
				x=floor((c*1.0-b)/a)+1;
				F1.Erase(x);
			}
			else if(a==0&&b>c)--tot;
			else{
				x=ceil(1.0*(c-b)/a)-1;
				F2.Erase(x);
			}
		}
		if(s[1]=='Q'){
			x=read();
			printf("%d\n",F1.ber(x)+F2.ser(x)+tot);
		}
	}
	return 0;
}
