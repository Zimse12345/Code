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
char a[N],b[N],c[N];

int main(){
	scanf("%s %s %s",a+1,b+1,c+1);
	if(a[2]!='B'&&b[2]!='B'&&c[2]!='B')printf("ABC\n");
	if(a[2]!='R'&&b[2]!='R'&&c[2]!='R')printf("ARC\n");
	if(a[2]!='G'&&b[2]!='G'&&c[2]!='G')printf("AGC\n");
	if(a[2]!='H'&&b[2]!='H'&&c[2]!='H')printf("AHC\n");
	return 0;
}

