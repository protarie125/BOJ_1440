#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int ans;

vii parse(const string& s) {
	const auto s1 = s.substr(0, 2);
	const auto s2 = s.substr(3, 2);
	const auto s3 = s.substr(6, 2);

	auto iss1 = istringstream{ s1 };
	int val1;
	iss1 >> val1;

	auto iss2 = istringstream{ s2 };
	int val2;
	iss2 >> val2;

	auto iss3 = istringstream{ s3 };
	int val3;
	iss3 >> val3;

	return vii{ {1, val1}, {2, val2}, {3, val3} };
}

void check(const vii& vec) {
	const auto hh = vec[0].second;
	const auto mm = vec[1].second;
	const auto ss = vec[2].second;
	if (1 <= hh && hh <= 12) {
		if (0 <= mm && mm <= 59) {
			if (0 <= ss && ss <= 59) {
				++ans;
			}
		}
	}
}

void checkAll(vii& vec) {
	ans = 0;
	do {
		check(vec);
	} while (next_permutation(vec.begin(), vec.end()));
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string s;
	cin >> s;

	auto vec = parse(s);
	checkAll(vec);

	cout << ans;

	return 0;
}