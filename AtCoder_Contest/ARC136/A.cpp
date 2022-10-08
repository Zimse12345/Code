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

const int N=3e5+7,Mod=998244353,INF=1e9+7;
char s[N];
int n;

signed main(){
	n=read();
	scanf("%s",s+1);
	int p=1;
	while(1){
		if(s[p]=='B'&&s[p+1]=='B')printf("A"),p+=2;
		else if(s[p]=='B'&&s[p+1]=='A')swap(s[p],s[p+1]);
		else printf("%c",s[p]),++p;
		if(p>n)break;
	}
	printf("\n");
	return 0;
}

