#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<string.h>
#include<deque>
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
 
 
struct box{
int b;
int a;
 
};
bool operator<(const box& a,const box& b )
{
    if(a.b!=b.b){
    return a.b<b.b;}
    else
        return a.a<b.a;
 
}
 
void pri(int x)
{        cout<<x<<" ";
 
}
 
int main()
{
    ll n,i,m,k,j;
    cin>>n>>m>>k;
    if(n==1){
        cout<<m<<"\n";
        return 0;
    }
    ll de = k-1;
    ll delo =n-k;
    ll lo=1,hi=m;
    ll mi=(lo+hi)/2;
    ll ans=0;
    ll cnt= 0;
    while(lo<=hi){
        mi=(lo+hi)/2;
        cnt=(mi*(mi-1));
        cnt+=mi;
        if((mi-1)>delo){
            cnt-=((mi-delo)*(mi-delo-1)/2);
        }else if(delo > (mi-1)) {
            cnt +=delo-(mi-1);
        }
        if((mi-1)>de){
            cnt-=((mi-de)*(mi-de-1)/2);
        }else if(de > (mi-1)) {
            cnt+=de-(mi-1);
        }
 
        if(cnt>m){
            hi=mi-1;
        }
        else if(cnt<=m){
            lo=mi+1;
            ans=mi;
        }
    }
 
    cout<<ans<<"\n";
    return 0;
 
}
