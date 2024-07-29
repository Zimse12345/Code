#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        n/=2;
        printf("%d\n",n/2+(n&1));
    }
    return 0;
}

