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
    ll n,u,i,j=0,k=0,fi=-1,fj=-1,fk=-1;
    cin>>n>>u;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++){
        if((i>k))
            k=i;
        while((k<(n-1)) && (a[k+1]-a[i])<=u){
            k++;
        }
        if(k>(i+1)){
        j=i+1;
        if(fi==-1 || ((a[k]-a[j])*(a[fk]-a[fi]))>((a[fk]-a[fj])*(a[k]-a[i])) ){
            fi=i;fj=j;fk=k;
        }}
 
    }
    if(fi==-1){
        cout<<-1<<"\n";
 
    }
    else
    {
        cout.precision(15);
        cout<<(double)(a[fk]-a[fj])/(a[fk]-a[fi])<<"\n";
    }
    return 0;
 
}
