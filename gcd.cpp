#include <iostream>
using namespace std;

ll gcd(ll a,ll b){
    if(a<b) gcd(b,a);
    ll r=1;
    while(r!=0){
    r=a%b;
    a=b;
    b=r;
    }
    return a;
}