#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int a[8]; 

signed main(){
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    sort(a+1,a+5);
    if(a[1]==a[2]&&a[3]==a[4])printf("2\n");
    else if(a[1]==a[2]||a[2]==a[3]||a[3]==a[4])printf("1\n");
    else printf("0\n");
    return 0;
}


