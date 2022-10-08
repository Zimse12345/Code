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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int ans=INF,len[10];
char s[10][N];

void sol(int a,int b,int c){
	int res=0;
	int p=0,q=0;
	for(int i=1;i<=min(len[a],min(len[b],len[c]));i++){
		if(s[a][i]==s[b][i]&&s[b][i]==s[c][i])++p;
		else break;
	}
	res+=len[a]-p;
	for(int i=1;i<=min(len[b],len[c]);i++){
		if(s[b][i]==s[c][i])++q;
		else break;
	}
	res+=len[b]+len[c]-q-p;
	ans=min(ans,res);
	return;
}

signed main(){
	for(int i=1;i<=3;i++)len[i]=read(),scanf("%s",s[i]+1);
	sol(1,2,3),sol(1,3,2),sol(2,1,3),sol(2,3,1),sol(3,1,2),sol(3,2,1);
	printf("%d\n",ans);
	return 0;
}

