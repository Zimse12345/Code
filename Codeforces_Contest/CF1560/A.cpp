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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],k;

int main(){
	T=read();
	while(T--){
		n=read(),k=n;
		for(int i=1;i<=k*10;i++){
			if((i%10!=3)&&(i%3!=0))n--;
			if(n==0){
				printf("%d\n",i);
				break;
			}
		} 
	}
	return 0;
}
