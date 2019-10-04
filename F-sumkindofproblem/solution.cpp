/*
   Sum of the first b numbers: b*(b+1)/2
   Sum of the first b odd numbers: b*b
   Sum of the first b even numbers: b*(b+1)
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int N;
	scanf("%d",&N);
	while(N--) {
		ll a,b;
		scanf("%lld %lld",&a,&b);
		printf("%lld %lld %lld %lld\n",a,b*(b+1)/2,b*b,b*(b+1));
	}
}
