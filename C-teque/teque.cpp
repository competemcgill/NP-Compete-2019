/*
   This problem requires knowledge of C++ data structures, particularly which ones to use and when.
   In particular, we can implement a Teque using two Deques, representing the left and right halves.
   Our implementation has O(1) insertion and O(1) access, which makes the solution O(N), which is fast enough.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef deque<ll> dq;
//Teque class
class T {
	private:
		//first half & second half deques
		dq f,s;
		//Function to balance the deques:
		//If one is bigger than the other, move elements around to make them equal (or off by 1 in the right direction)
		void balance() {
			int sz = f.size()+s.size();
			int md = (sz+1)/2;
			if(md > f.size()) {
				while(f.size() < md) {
					f.push_back(s.front());
					s.pop_front();
				}
			} else {
				while(f.size() > md) {
					s.push_front(f.back());
					f.pop_back();
				}
			}
		}
	public:
		//Gets the [id]th element in the Teque
		ll get(int id) {
			if(id < f.size()) {
				return f[id];
			}
			id -= f.size();
			return s[id];
		}
		//push_front,push_back, and push_middle all push in the right places and then balance the deques out
		//push_front: front of the front half
		//push_back: back of the back half
		//push_middle: front of the back half
		void push_front(int val) {
			f.push_front(val);
			balance();
		}
		void push_back(int val) {
			s.push_back(val);
			balance();
		}
		void push_middle(int val) {
			s.push_front(val);
			balance();
		}
};
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	T ans;
	while(n--) {
		string t;
		int val;
		cin >> t >> val;
		//Basic string processing:
		//"get" starts with "g",
		//the 5th letter of "push_*" determines which operation is being entered
		if(t[0] == 'g') {
			cout << ans.get(val) << '\n';
		} else if(t[5] == 'b') {
			ans.push_back(val);
		} else if(t[5] == 'f') {
			ans.push_front(val);
		} else {
			ans.push_middle(val);
		}
	}
}
