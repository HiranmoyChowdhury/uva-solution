#include<bits/stdc++.h>
#define bst           ios_base::sync_with_stdio(0);
#define bug(x)        cerr<<#x<<'='<<x<<endl;
#define lp(i,a,b)     for(int i=a; i<=b; i++)
#define ll            long long int
#define eb            emplace_back
#define pb            push_back
#define mp            make_pair
using namespace std;
int main(){
    ll n, i, j, k;
    bool check[1000000]={};
    vector<ll> primes;
    primes.eb(2);
    for(i=4; i<=1000000; i+=2) check[i]=true;
    for( i=3; i<1999; i+=2){
        if(check[i]==false){
            primes.eb(i);
            for(j=i*i; j<=1000000; j+=(i+i)) check[j]=true;
        }
    }
    while(1){
        cin>>n;
        if(n==0) break;
        ll x, y;
        ll limit=sqrt(n)+1;
        for(i=0; primes[i]<=1000; i++){
            if(check[n-primes[i]]==false){
                x=primes[i], y=n-primes[i];
                break;
            }
        }
        
        printf("%lld = %lld + %lld\n", n, x, y);
    }
    return 0;
}
