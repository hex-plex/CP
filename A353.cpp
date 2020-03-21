#include<iostream>
#include<set>
//#include<vector>
//#include<algorithm>

#include<string>

//#include<stdio.h>
//#define a.pb(c) push_back(c)
//#define pri(n) cout<<n<<"\n"
#define all(c) c.begin(),c.end()
#define allarr(c) c,c+sizeof(c)
#define revall(c) c.rbegin(),c.rend()
#define pb push_back
typedef long long ll;
#define inf 1000000000
//typedef vector <int> vi;
//typedef pair<int,int> pii;

using namespace std;

void pri(int x)
{
    cout<<x<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;

    int i;
    int oddc=0,oddc1=0,oddc2=0;
    int t1,t2;
    for(i=0;i<n;i++)
    {
        cin>>t1>>t2;
        oddc1+=t1%2;
        oddc2+=t2%2;
        oddc+= t1%2 ^ t2%2 ? 1:0;

    }
    if(oddc%2)
        cout<<-1;
    else {
        if(oddc1!=oddc2)
        {
            cout<<(oddc1%2);
        }
        else
        {
            if(oddc1%2&&oddc==0)cout<<-1;
            else cout<<oddc1%2;
        }
    }

    return 0;
}
