#include <iostream>
using namespace std;

int chk(char& a) {
	switch (a) {
	case 'I': {return 1; break; }
	case 'V': {return 5; break; }
	case 'X': {return 10; break; }
	case 'L': {return 50; break; }
	case 'C': {return 100; break; }
	case 'D': {return 500; break; }
	case 'M': {return 1000; break; }
	default: { return 0; break; }
	}
}

int romToint(string s) {
	int ans = 0;
	if (s.size() > 1) {
		for (int i = 0; i < s.size(); ++i) {
			if (chk(s[i]) < chk(s[i + 1])) {
				ans += chk(s[i + 1]) - chk(s[i]);
				i += 1;
			}
			else {
				ans += chk(s[i]);
			}
		}
		return ans;
	}
	else return chk(s[0]);
}