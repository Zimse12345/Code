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

const int N=3e6+7,Mod=998244353,INF=1e9+7;
int n;

inline void write(int x)
{
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9) 
		write(x/10);
    putchar(x%10+'0');
}

int main(){
	n=read();
	if(n<=8){
		printf("-1");
		return 0;
	}
	printf("%d\n",n);
//	if(n==6){
//		printf("1 2\n2 3\n3 6\n2 4\n1 5\n");
//		return 0;
//	}
	printf("1 2\n2 3\n3 4\n4 5\n1 6\n6 7\n");
	for(register int i=8;i<=n;i++){
		putchar('1');
		putchar(' ');
		write(i);
		putchar('\n');
	}
	return 0;
}
