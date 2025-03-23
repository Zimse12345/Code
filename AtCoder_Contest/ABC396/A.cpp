#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N]; 

signed main(){
    cin>>n;
    int t=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>2&&a[i]==a[i-1]&&a[i]==a[i-2])t=1;
    }
    if(t)printf("Yes\n");
    else printf("No\n");
    return 0;
}


