#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,Mod=998244353;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int x=1,y=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            int _x=0,_y=0;
            if(a[i]==a[i-1])_x=x;
            _y=x;
            if(y&&a[i-2]+1==a[i])(_x+=y)%=Mod;
            x=_x,y=_y;
        }
        printf("%d\n",(x+y)%Mod);
    }
    return 0;
}


