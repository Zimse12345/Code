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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x>9)write(x/10);putchar(x%10+'0');return;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,ch[N][26],cnt,fail[N],dep[N],tag[N],pos[N],len;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x>A.x;}}p[N];
queue<int> q;
char t[N*10],C;

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		len=0;
		do{C=getchar();}while(C<'a'||C>'z');
		while(C>='a'&&C<='z')t[++len]=C,C=getchar();
		int u=0;
		for(int j=1,c;j<=len;j++){
			c=t[j]-'a';
			if(!ch[u][c])ch[u][c]=++cnt,dep[cnt]=dep[u]+1,p[cnt]=node(dep[cnt],cnt);
			u=ch[u][c];
		}
		pos[i]=u;
	}
	q.push(0);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0,v;i<26;i++){
			v=ch[u][i];
			if(v){
				if(u)fail[v]=ch[fail[u]][i];
				q.push(v);
			}
			else ch[u][i]=ch[fail[u]][i];
		}
	}
	len=0;
	do{C=getchar();}while(C<'a'||C>'z');
	while(C>='a'&&C<='z')t[++len]=C,C=getchar();
	for(int i=1,u=0;i<=len;i++)u=ch[u][t[i]-'a'],++tag[u];
	sort(p+1,p+cnt+1);
	for(int i=1;i<=cnt;i++)tag[fail[p[i].y]]+=tag[p[i].y];
	for(int i=1;i<=n;i++)write(tag[pos[i]]),putchar('\n');
	return 0;
}

