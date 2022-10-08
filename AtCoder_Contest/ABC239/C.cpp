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
int ax_1,ay_1,ax_2,ay_2;

signed main(){
	ax_1=read(),ay_1=read(),ax_2=read(),ay_2=read();
	int d1=abs(ax_1-ax_2),d2=abs(ay_1-ay_2);
	if(d1>10||d2>10){
		printf("No\n");
		return 0;
	}
	else{
		for(int i=ax_1-30;i<=ax_1+30;i++){
			for(int j=ay_1-30;j<=ay_1+30;j++){
				if((abs(i-ax_1)==1&&abs(j-ay_1)==2)||(abs(i-ax_1)==2&&abs(j-ay_1)==1))if((abs(i-ax_2)==1&&abs(j-ay_2)==2)||(abs(i-ax_2)==2&&abs(j-ay_2)==1)){
					printf("Yes\n");
					return 0;
				}
			}
		}
	}
	printf("No\n");
	return 0;
}

