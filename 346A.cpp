    #include<bits/stdc++.h>
    #define bst           ios_base::sync_with_stdio(0);
    #define bug(x)        cerr<<#x<<'='<<x<<endl;
    #define lp(i,a,b)     for(int i=a; i<=b; i++)
    #define ll            long long int
    using namespace std;
    bool primes[109999];
    int main(){
        bst
        int n, i, j, odd=0, even=0, ans=0;
        cin>>n;
        int a[n];
        for(i=0; i<n; i++){
            cin>>a[i];
            if(a[i]%2==0) even++;
            else odd++;
        }
        sort(a, a+n);
        int diff=a[1]-a[0], k=0;
        for(i=2; i<n; i++){
            if(a[i]-a[i-1]!=diff){
                k=1;
                break;
            }
        }
        if(k==0){
            if(a[0]%diff!=0) k=1;
            if(diff==a[0]){
                cout<<"Bob"<<endl;
                return 0;
            }
        }
        if(k==0){
            ans=a[0]/diff;
            if(ans%2==1) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
            return 0;
        }
        if(even==n){
            if(n==2){
                if(a[n-1]%diff==0){
                    ans=a[n-1]/diff;
                    if(ans%2==1) cout<<"Bob"<<endl;
                    else cout<<"Alice"<<endl;
                    return 0;
                }
            }
            diff=a[0];
            for(i=1; i<n; i++) diff=__gcd(diff,a[i]-a[i-1]);
            int s=0;
            for(i=0; i<n; i++){
                if(a[i]>=diff && a[i]%diff==0) s++;
            }
            if(s==n) s=diff;
            else s=2;
            ans=(a[n-1]/s)-n;
            if(ans%2==0) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
        else{
            ans=a[n-1]-n;
            if(ans%2==0) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
        return 0;
    }
