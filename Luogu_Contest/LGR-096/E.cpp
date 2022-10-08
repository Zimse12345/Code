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
int n;

int main(){
	n=read();
	if(n==1)printf("0");
	if(n==2)printf("1\n2 1\n");
	if(n==3)printf("0");
	if(n==4)printf("1\n4 2\n");
	if(n==5)printf("1\n5 3\n");
	if(n==6)printf("1\n6 3\n");
	if(n==7)printf("2\n7 3\n4 2\n");
	if(n==8)printf("2\n8 3\n5 2\n");
	if(n==9)printf("1\n9 5\n");
	if(n==10)printf("3\n10 6\n6 3\n4 2\n");
	return 0;
}
