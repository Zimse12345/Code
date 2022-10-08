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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
char s[N],t[N];
int a,b;

int main(){
	scanf("%s%s",s+1,t+1);
	a=strlen(s+1),b=strlen(t+1);
	int p=min(a,b);
	int y=0,z=1;
	for(int i=1;i<=p;i++){
		if(s[i]<t[i]){
			y=1;
			break;
		}
		if(s[i]>t[i]){
			z=0;
			break;
		}
	}
	if(z&&b>p)y=1;
	if(y)printf("Yes\n");
	else printf("No\n");
	return 0;
}

