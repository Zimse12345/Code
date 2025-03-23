#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,a,b,c,d; 

signed main(){
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        if(a==b&&b==c&&c==d)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


