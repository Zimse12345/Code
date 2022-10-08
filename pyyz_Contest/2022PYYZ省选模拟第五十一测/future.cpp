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

const int N=1e6+7,H=41,Mod=998244353,INF=1e9+7;
int n,m,h[N];
char s[N],ss[N];
map<int,int> pre;

int calc(){
	int res=0;
	for(int i=1;i<=n;i++)res=(res*H+s[i]-'0')%Mod;
	return res;
}

void nxt(){
	s[n+1]=s[1];
	for(int i=1;i<=n;i++){
		if(s[i]==s[i+1])continue;
		else{
			if(s[i]!='r'&&s[i+1]!='r')s[i]='r';
			else if(s[i]!='b'&&s[i+1]!='b')s[i]='b';
			else if(s[i]!='g'&&s[i+1]!='g')s[i]='g';
		}
	}
	return;
}

signed main(){
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)ss[i]=s[i];
	h[0]=calc();
	pre[h[0]]=0;
	for(int i=1;i<=m;i++){
		nxt();
		if(i==m){
			for(int i=1;i<=n;i++)printf("%c",s[i]);
			printf("\n");
			return 0;
		}
		h[i]=calc();
		if(pre[h[i]]){
			int len=i-pre[h[i]];
			int rm=(m-i+1)%len;
			m=pre[h[i]]+rm-1;
			break;
		}
		else pre[h[i]]=i;
	}
	for(int i=1;i<=n;i++)s[i]=ss[i];
	for(int i=1;i<=m;i++){
		nxt();
		if(i==m){
			for(int i=1;i<=n;i++)printf("%c",s[i]);
			printf("\n");
			return 0;
		}
	}
	return 0;
}

