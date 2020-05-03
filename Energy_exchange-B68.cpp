#include<iostream>
//#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
//#include<cmath>
#include<string.h>
//#include<deque>
//#include<stdio.h>
//#define a.pb(c) push_back(c)
//#define pri(n) cout<<n<<"\n"
#define all(c) c.begin(),c.end()
#define allarr(c) c,c+sizeof(c)
//#define revall(c) c.rbegin(),c.rend()
#define pb push_back
typedef long long ll;
#define inf 1000000000
//typedef vector <int> vi;
//typedef pair<int,int> pii;
#define For(i,a,b) for(i=a;i<b;i++)
using namespace std;
 
 
void pri(pair<int,int> x)
{        cout<<x.first<<" "<<x.second<<"\n";
 
}
 
int main()
{
    int n ,k,i,j;
    cin>>n>>k;
    int a[n];
    int ma=0;
    For(i,0,n){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
 
    double lo=0,hi=ma,mi;
    double lss=0,gai=0,ans=0;
    while((hi-lo)>=(1e-6))
    {
        lss=0;gai=0;
        mi=(lo+hi)/2;
        For(i,0,n){
            if(a[i]>mi){
                gai+=(a[i]-mi);
            }
            if(a[i]<mi){
                lss+=(mi-a[i]);
            }
        }
        if(lss<=(gai*(1-(k/100.0)))){
            ans=mi;
            lo=mi;
        }
        else{
            hi=mi;
        }
    }
    cout.precision(10);
    cout<<ans<<"\n";
    return 0;
 
}
