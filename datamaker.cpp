#include "bits/stdc++.h"
#include<unistd.h>
#define int long long
using namespace std;

#define maxn 100000
#define maxx 50

mt19937 Rand (getpid());

int arr[maxn + 10];
void solve(){
    int n = Rand() % 20 + 1;
    printf("%d\n",n);
    for(int i = 1; i <= 2; ++i){
        printf("%d ",Rand() % 50 + 1);
    }
    putchar('\n');
    for (int i = 1; i <= 3; ++i) {
        printf("%d ",Rand() % 50 + 1);
    }
}

signed main(){
    freopen("data.txt", "w", stdout);
    //int t = 1;
    //printf("%d\n", t);
    //while(t --){
        solve();
    //}
    return 0;
}
