#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int a[10]; 

signed main(){
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    sort(a+1,a+5);
    if((a[1]==a[3]&&a[3]!=a[4])||(a[2]==a[4]&&a[1]!=a[2])||(a[1]==a[2]&&a[2]!=a[3]&&a[3]==a[4])){
        printf("Yes\n"); 
    }
    else printf("No\n");
    return 0;
}


