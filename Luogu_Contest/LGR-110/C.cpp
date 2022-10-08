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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x>=10)write(x/10);putchar(x%10+'0');return;}

const int N=1e6+7,Mod=1e9+7,INF=1e9+7;
int n,m,k,a[N],b[N],sum,mx[N],s[N];
char opt[N];
int ldl(int x,int k=Mod-2){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{
		return (x-A.x)*n>(y-A.y);
	}
	bool operator == (const node& A)const{
		return (x-A.x)*n==(y-A.y);
	}
};
priority_queue<node> q1,q2;

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read(),sum+=b[i],mx[a[i]]=max(mx[a[i]],b[i]),s[a[i]]+=b[i];
	for(int i=1;i<=k;i++)if(mx[i])q1.push(node(mx[i],s[i]));
	while(m--){
		scanf("%s",opt+1);
		if(opt[1]=='C'){
			int x=read(),y=read();
			if(s[x])q2.push(node(mx[x],s[x]));
			if(s[y])q2.push(node(mx[y],s[y]));
			mx[y]=max(mx[y],mx[x]),mx[x]=0;
			s[y]+=s[x],s[x]=0;
			if(mx[y])q1.push(node(mx[y],s[y]));
		}
		else{
			while(!q2.empty()&&q1.top()==q2.top())q1.pop(),q2.pop();
			node p=q1.top();
			int ans=(p.x+(sum-p.y)*ldl(n))%Mod;
			write(ans),putchar('\n');
		}
	}
	return 0;
}

