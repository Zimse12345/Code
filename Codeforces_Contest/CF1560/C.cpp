#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

int T,n,k;

int main(){
	T=read();
	while(T--){
		k=read();
		int t=sqrt(k);
		if(k==t*t)printf("%d %d\n",t,1);
		
		else{
			k-=t*t;
			if(k<=t+1)printf("%d %d\n",k,t+1);
			else printf("%d %d\n",t+1,t-(k-t-1)+1);
		}
	}
	return 0;
}
