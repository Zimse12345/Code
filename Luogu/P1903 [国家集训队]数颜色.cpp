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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int B=5000;
struct node{int x,y,z;node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
bool operator < (const node& A)const{
if(x/B!=A.x/B)return x/B<A.x/B;
if(y/B!=A.y/B){if((x/B)&1)return y/B<A.y/B;return y/B>A.y/B;}
if((y/B)&1)return z<A.z;return z>A.z;}};
struct opt{int x,y,pr,z;opt(int x=0,int y=0,int pr=0,int z=0):x(x),y(y),pr(pr),z(z){}
bool operator < (const opt& A)const{return z<A.z;}};
int n,m,a[N],b[N],qt,ct,Ans[N],tot[N],vis[N];
node Q[N];opt C[N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=b[i]=read();
	char op;
	for(int i=1,x,y;i<=m;i++){
		do{op=getchar();}while(op!='Q'&&op!='R');
		x=read(),y=read();
		if(op=='Q')Q[++qt]=node(x,y,i);
		else C[++ct]=opt(x,y,b[x],i),b[x]=y;
	}
	for(int i=1;i<=n;i++)b[i]=a[i];
	
	sort(Q+1,Q+qt+1);
	int L=1,R=0,T=0;
	for(int i=1,x,y,z,ans=0;i<=qt;i++){
		x=Q[i].x,y=Q[i].y,z=Q[i].z;
		while(R<y)ans+=!tot[b[++R]]++;
		while(L>x)ans+=!tot[b[--L]]++;
		while(R>y)ans-=!--tot[b[R--]];
		while(L<x)ans-=!--tot[b[L++]];
		while(T<ct&&z>C[T+1].z){
			++T;
			if(x<=C[T].x&&C[T].x<=y){
				ans-=!--tot[C[T].pr];
				ans+=!tot[C[T].y]++;
			}
			b[C[T].x]=C[T].y;
		}
		while(T>0&&z<C[T].z){
			if(x<=C[T].x&&C[T].x<=y){
				ans-=!--tot[C[T].y];
				ans+=!tot[C[T].pr]++;
			}
			b[C[T].x]=C[T].pr;
			--T;
		}
		Ans[z]=ans,vis[z]=1;
	}
	for(int i=1;i<=m;i++)if(vis[i])printf("%d\n",Ans[i]);
	return 0;
}

