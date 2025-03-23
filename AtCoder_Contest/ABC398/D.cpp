#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,r,c;
char s[N];

map<int,int> mp;

signed main(){
    cin>>n>>r>>c;
    scanf("%s",s+1);
    mp[0]=1;
    for(int i=1,x=0,y=0;i<=n;i++){
        if(s[i]=='N')--x;
        if(s[i]=='W')--y;
        if(s[i]=='S')++x;
        if(s[i]=='E')++y;
        mp[x*N+y]=1;
        if(mp[(x-r)*N+(y-c)])printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}


