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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,k,tot,ch[N][26],A[N],B[N];
char s[N];

void dfs(int x){
	for(int i=0;i<26;i++)if(ch[x][i]){
		dfs(ch[x][i]);
		if(!A[ch[x][i]])A[x]=1;
		if(!B[ch[x][i]])B[x]=1;
	}
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1,x,len;i<=n;i++){
		scanf("%s",s+1),x=0,len=strlen(s+1);
		for(int j=1;j<=len;j++){
			if(!ch[x][s[j]-'a'])ch[x][s[j]-'a']=++tot;
			x=ch[x][s[j]-'a'];
		}
		B[x]=1;
	}
	dfs(0);
	if(k&1){
		if(A[0])printf("First\n");
		else printf("Second\n");
	}
	else{
		if((A[0]&&B[0]))printf("First\n");
		else printf("Second\n");
	}
	return 0;
}

