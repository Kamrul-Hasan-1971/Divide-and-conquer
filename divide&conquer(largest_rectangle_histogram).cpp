#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
ll ara[100005];
ll combine( ll l , ll mid , ll r )
{
    ll i = mid , j = mid+1 , mn = INT_MAX,mx=0;
    while(i>=l && j<=r)
    {
        mn = min(mn,min(ara[i],ara[j]));
        mx = max(mx,(j-i+1)*mn);
        if(i==l) j++;
        else if(j==r) i--;
        else {
            if(ara[i-1]>ara[j+1]) i--;
            else j++;
        }
    }
    return mx ;
}
ll fun(ll l,ll r)
{
    if(l==r) return ara[l];
    ll mid = (l+r)/2ll;
    ll ret1 = fun(l,mid);
    ret1 = max(ret1,fun(mid+1,r));
    ret1 = max(ret1,combine(l,mid,r));
    return ret1 ;
}
int main()
{
    CIN;
    ll  a,b,c,d,e,f,i,j,k,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    while(1)
    {
        scanf("%lld",&a);
        if(a==0) break;
        for( i =1 ; i <= a ; i++) scanf("%lld",&ara[i]);
        printf("%lld\n",fun(1,a));
    }
    return 0 ;
}
