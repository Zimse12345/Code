#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int m=1,ans=1;
        while(m<n)m=(m+1)*2,++ans;
        printf("%d\n",ans);
    }
    return 0;
}


