#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a,b,ans; 

signed main(){
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(b>a)++ans;
    }
    printf("%d\n",ans);
    return 0;
}


