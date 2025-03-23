#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n;
char s[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        scanf("%s",s+1);
        int x=0,y=0,z=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='_')++y;
            else ++x;
        }
        z=x/2;
        x-=z;
        printf("%lld\n",x*y*z);
    }
    return 0;
}


