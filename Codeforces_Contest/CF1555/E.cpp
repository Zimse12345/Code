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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=2e6+7,INF=0x3f3f3f3f;
int n,m,ans=INF;
int ad[N*4],mi[N*4];

struct s{
	int L,R,W;
	s(int L=0,int R=0,int W=0):L(L),R(R),W(W){}
	bool operator <(const s& A)const{return W<A.W;}
}p[N];

void push_down(int o){
	int _l=o<<1,_r=(o<<1)|1;
	mi[o]+=ad[o],ad[_l]+=ad[o],ad[_r]+=ad[o],ad[o]=0;
	return;
}

int add(int L,int R,int l,int r,int k,int o){
	push_down(o);
	if(l<=L&&R<=r){
		ad[o]+=k;
		push_down(o);
//		printf("[%d %d %d]\n",L,R,mi[o]);
		return 0;
	}
	int M=(L+R)>>1;
	if(l<=M)add(L,M,l,r,k,o<<1);
	if(r>M)add(M+1,R,l,r,k,(o<<1)|1);
	push_down(o<<1),push_down((o<<1)|1);;
	mi[o]=min(mi[o<<1],mi[(o<<1)|1]);
	push_down(o);
//	printf("[%d %d %d]\n",L,R,mi[o]);
	return 0;
}

int query(int L,int R,int o){
	push_down(o);
	return mi[o];
}

int main(){
	n=read(),m=read();
//	for(int i=1;i<=n;i++){
//		int ty=read();
//		if(ty==1){
//			int l=read(),r=read(),k=read();add(1,m,l,r,k,1);
//		}else{
//			printf("[%d]\n",query(1,m,1));
//		}
//	}
	
	for(int i=1,L,R,W;i<=n;i++)L=read(),R=read(),W=read(),p[i]=s(L,R,W);
	sort(p+1,p+n+1);
	
	int L=1;--m;
	for(int i=1;i<=n;i++){
		add(1,m,p[i].L,p[i].R-1,1,1);
		while(query(1,m,1)>0){
			ans=min(ans,p[i].W-p[L].W),add(1,m,p[L].L,p[L].R-1,-1,1),++L;
//			printf("%d(%d) %d(%d);\n",L,p[L].W,i,p[i].W);
		}
	}
	printf("%d\n",ans);
	return 0;
}
