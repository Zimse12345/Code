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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=1e9+7,INF=1e9+7;
int n,k,a[N],t,ans,vis[N];
char s[N];
map<int,int> s1,s2,t1,t2;
struct node{
	int x,y,w;
	node(int x=0,int y=0,int w=0):x(x),y(y),w(w){}
	bool operator < (const node& A)const{return w<A.w;}
};
priority_queue<node> Q;

signed main(){
	scanf("%s",s+1),n=strlen(s+1),k=read();
	t2[1]=1;
	for(int i=1;i<=n;i++){
		s1=t1,s2=t2;
		t1.clear(),t2.clear();
		for(int j=1;j<10;j++){
			for(map<int,int>::iterator it=s1.begin();it!=s1.end();it++)t1[(it->first)*j]+=(it->second);
			if(j<s[i]-'0')for(map<int,int>::iterator it=s2.begin();it!=s2.end();it++)t1[(it->first)*j]+=(it->second);
			else if(j==s[i]-'0')for(map<int,int>::iterator it=s2.begin();it!=s2.end();it++)t2[(it->first)*j]+=(it->second);
		}
		if(i!=1){
			for(int j=1;j<10;j++)t1[j]++;
		}
	}
	s1=t1,s2=t2;
	for(map<int,int>::iterator it=s2.begin();it!=s2.end();it++)s1[it->first]+=(it->second);
	for(map<int,int>::iterator it=s1.begin();it!=s1.end();it++)a[++t]=(it->second);//printf("(%d %d)\n",it->first,it->second);
	sort(a+1,a+t+1);
	for(int i=1;i<=t;i++)vis[i]=t+1;
	vis[t]=t;
	Q.push(node(t,t,a[t]*a[t]));
	while(k&&!Q.empty()){
		k--;
		node u=Q.top();
		Q.pop();
		ans=(ans+u.w)%Mod;
		if(u.x>1){
			if(u.y+1==vis[u.x-1])Q.push(node(u.x-1,u.y,a[u.x-1]*a[u.y])),--vis[u.x-1];
		}
		if(u.y>1){
			if(u.y==vis[u.x])Q.push(node(u.x,u.y-1,a[u.x]*a[u.y-1])),--vis[u.x];
		}
	}
	printf("%lld\n",ans);
	return 0;
}

