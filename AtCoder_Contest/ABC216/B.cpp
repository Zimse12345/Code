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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n;
string s[N][2];

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j=1;j<i;j++)if(s[i][0]==s[j][0]&&s[i][1]==s[j][1])return !printf("Yes\n");
	}
	printf("No\n");
	return 0;
}
