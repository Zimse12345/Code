#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>1&&min(a[i-1],a[i])*2>max(a[i-1],a[i]))ans=1; 
        }
        if(ans)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


