#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, int> dict;	// a dictionary that maps a string to int
	dict["Ching Helen"] = 161;
	dict["Au Cheuk Yi"] = 125;
	dict["Lam Elizabeth"] = 126;
	dict["Ip Wing Chun"] = 112;
	dict["Ho Wai Shum Emma"] = 130;
	dict["Fung Pue Que"] = 131;
	dict["Ng Hey"] = 80;
	dict["Cheng YunYing"] = 195;
	// x.find(ch) returns x.end() if ch is not found in the set

	cout << dict["Ching Helen"] << endl;
	cout << dict["Au Cheuk Yi"] << endl;

	// need to be careful. if the key is not found, map would add an entry, which is probably not what you want most of the time. so it's a good habit to call the find function before the lookup
	if (dict.find("Chow Tsz Yau") != dict.end()) {
		cout << dict["Chow Tsz Yau"] << endl;
	} else {
		cout << "name not found" << endl;
	}
	return 0;
}
