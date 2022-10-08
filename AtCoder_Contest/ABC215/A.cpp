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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
char s[N];
string t=" Hello,World!";

int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	if(n!=12)return !printf("WA\n");
	for(int i=1;i<=12;i++)if(s[i]!=t[i])return !printf("WA\n");
	printf("AC\n");
	return 0;
}

