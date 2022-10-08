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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n;

void link(int u,int v){
    printf("%d %d\n",u,v);
    return;
}

signed main(){
    n=read();
    if(n==(n&(-n))){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    for(int i=2;i<n;i+=2){
        link(1,i),link(i,i+1+n);
        link(1,i+1),link(i+1,i+n);
    }
    link(3+n,1+n);
    if(n%2==0){
        int x=(n&(-n)),y=n^x;
        x^=1;
        link(x,n),link(y,n+n);
    }
	return 0;
}
