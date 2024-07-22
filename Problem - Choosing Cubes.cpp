//Problem - Choosing Cubes
// https://codeforces.com/contest/1980/problem/B

//tc -> O( 2n + nlogn )
#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);

void solve(){
    int n , f , k; 
    cin>>n>>f>>k ; 
    
    vector<int>arr(n) ; 

    for(int i = 0 ; i<n ; i++)
        cin>>arr[i];
    
    int fval = arr[f-1] ; 

    sort(arr.begin() , arr.end() , greater<int>());
    int lb = 0 ; 
    int ub = 0 ; 
    for(int i = 0 ; i<n ; i++)
    {
        if(arr[i] == fval)
        {
            lb = i ; 
            break ; 
        }
    }
    for(int i = 0 ; i<n ; i++)
    {
        if(arr[i] == fval)
        {
            ub = i ; 
        }
    }

    if(lb == ub){
        //only one occurence of fval
        if((lb == k-1 && ub == k-1) || (k-1 > lb))
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
    }
    else
    {
        if(k-1 < lb)
            cout<<"NO"<<endl;
        else if(lb <= k-1 && k-1 < ub)
            cout<<"MAYBE"<<endl ; 
        else
            cout<<"YES"<<endl;
    }

    
}
int main(){
    fastIO ; 

    int t ; 
    cin>>t ; 

    while(t--){
        solve();
    }
}