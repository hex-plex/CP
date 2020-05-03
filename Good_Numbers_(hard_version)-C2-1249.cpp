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
    ll n,i,bas,p=1;
    int q;
    cin>>q;
    while(q--){
        cin>>n;
        vector<int> base;
        ll poof2=-1;
        while(n>0){
            base.pb(n%3);
            if(n%3==2)
                poof2=(base.size()-1);
            n/=3;
        }
        base.pb(0);
        if(poof2!=-1){
            ll poof0= find(base.begin()+poof2,base.end(),0) - base.begin();
            base[poof0]=1;
            for(i=poof0-1 ;i>=0;i--)
                base[i]=0;
        }
        n=0;
        p=1;
        for(i=0;i<base.size();i++){
            n+=p*base[i];
            p*=3;
        }
        if(base.back()==1)n=p/3;
        cout<<n<<"\n";
 
    }
 
    return 0;
 
}
