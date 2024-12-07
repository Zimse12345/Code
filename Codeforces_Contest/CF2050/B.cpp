#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int x=0,y=0,xc=0,yc=0;
        for(int i=1;i<=n;i++){
            cin>>a;
            if(i&1)x+=a,++xc;
            else y+=a,++yc;
        }
        if(x%xc==0&&y%yc==0&&x/xc==y/yc)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


