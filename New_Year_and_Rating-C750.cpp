#include<iostream>
//#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
//#include<cmath>
//#include<string.h>
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
    ll n,i,s=0;
    cin>>n;
    int c[n], d[n];
    For(i,0,n){
        cin>>c[i]>>d[i];
        s+=c[i];
    }
    ll hi=inf,lo=-inf,mi=0,a=-inf,dx=0;
    while(lo<=hi){
        mi = (lo+hi)/2;
        dx=0;
        For(i,0,n){
 
            if(((mi+dx)<1900) && (d[i]==1))
            {
                lo = mi+1;
                break;
            }
            if(((mi+dx)>=1900) && (d[i]==2)){
                hi = mi-1;
                break;
            }
            dx+=c[i];
        }
        //pri(i);
        if(i==(n)){
            a=mi;
            lo = mi+1;
        }
    }
    //cout<<a<<"\n";
    if(a==(inf)){
        cout<<"Infinity"<<"\n";
    }
    else if(a==-inf){
        cout<<"Impossible"<<"\n";
    }
    else{
        cout<<(a+s)<<"\n";
    }
 
    return 0;
 
}
