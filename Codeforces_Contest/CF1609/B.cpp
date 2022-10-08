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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m; 
char s[N];

bool ck(int x){
	if(s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c')return 1;
	return 0;
}

int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	char c;
	int ans=0;
	for(int i=1;i+2<=n;i++)if(ck(i))++ans;
	for(int i=1,p;i<=m;i++){
		p=read();cin>>c;
		if(p-2>=1&&ck(p-2))--ans;
		if(p-1>=1&&p+1<=n&&ck(p-1))--ans;
		if(p+2<=n&&ck(p))--ans;
		s[p]=c;
		if(p-2>=1&&ck(p-2))++ans;
		if(p-1>=1&&p+1<=n&&ck(p-1))++ans;
		if(p+2<=n&&ck(p))++ans;
		printf("%d\n",ans);
	}
	return 0;
}

