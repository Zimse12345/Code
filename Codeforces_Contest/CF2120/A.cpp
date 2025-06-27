#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,l1,l2,l3,b1,b2,b3; 

signed main(){
    cin>>T; 
    while(T--){
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        if(l1>b1)swap(l1,b1),swap(l2,b2),swap(l3,b3);
        if(l1+l2==b1&&b2+b3==b1&&l2==l3)printf("Yes\n");
        else if(l1+l2+l3==b1&&b1==b2&&b2==b3)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


