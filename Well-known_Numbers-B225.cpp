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
 
 
struct box{
int c;
int p;
int ind;
};
bool operator<(const box& a,const box& b )
{
    return a.p > b.p;
 
}
 
void pri(pair<int,int> x)
{        cout<<x.first<<" "<<x.second<<"\n";
 
}
 
int main()
{
    ll s,k,i;
    cin>>s>>k;
    int BIG = 75;
    vector <ll> fib(BIG);
    fib[0]=1;
    fib[1]=1;
    For(i,2,BIG){
        fib[i]=2*fib[i-1];
        if((i-k-1)>=0)
            fib[i]-=fib[(i-k-1)];
    }
    ll lo=0,hi=(BIG-1),mi,ans=0;
    vector <ll> v;
    while(s>0)
    {
        ans=0;
        lo=0;hi=(fib.size()-1);
        while(lo<=hi){
            mi=(lo+hi)/2;
            if(fib[mi]==s){
                ans=mi;
                break;
            }
            else if(fib[mi]<s){
                ans=mi;
                lo=mi+1;
            }
            else{
                hi=mi-1;
            }
        }
 
        v.pb(fib[ans]);
        s-=fib[ans];
        fib.erase(fib.begin()+ans);
    }
    if(v.size()==1){
        cout<<2<<"\n"<<0<<" "<<v.at(0)<<"\n";
        return 0;
    }
    cout<<v.size()<<"\n";
    For(i,0,v.size()){
        cout<<v.at(i)<<" ";
    }
    return 0;
 
}
