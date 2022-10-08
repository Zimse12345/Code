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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,q,k[N],p[N];
string s[N];

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int j=0;j<m-1;j++){
		for(int i=2;i<=n;i++)if(s[i][j]=='X'&&s[i-1][j+1]=='X')k[j+1]=1;
		p[j+1]=p[j]+k[j+1];
	}
	q=read();
	for(int i=1,l,r;i<=q;i++){
		l=read()-1,r=read()-1;
		if(p[r]-p[l]>0)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
