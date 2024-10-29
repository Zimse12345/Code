#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n; 

signed main(){
    cin>>T;
    while(T--){
        int mx=0,my=0;
        cin>>n;
        while(n--){
            int x,y;
            cin>>x>>y;
            mx=max(mx,x);
            my=max(my,y);
        }
        printf("%d\n",(mx+my)*2);
    }
    return 0;
}


