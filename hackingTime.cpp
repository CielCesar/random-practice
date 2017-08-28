#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	string encrpyed = "Atvt hrqgse, Cnikg";
	string decryped = "Your friend, Alice";

	string fullEncrypted = "Otjfvknou kskgnl, K mbxg iurtsvcnb ksgq hoz atv. Vje xcxtyqrl vt ujg smewfv vrmcxvtg rwqr ju vhm ytsf elwepuqyez.-Atvt hrqgse, Cnikg";
	vector<int> key;

	for(int i = 0; i < encrpyed.size(); i++) {
		if (encrpyed.at(i)< 65 || (encrpyed.at(i) > 90 && encrpyed.at(i) < 97) || encrpyed.at(i) > 122) {
			continue;
		}

		if (encrpyed.at(i) - decryped.at(i) > 9 || encrpyed.at(i) - decryped.at(i) < 0) {
			key.push_back(encrpyed.at(i) + 26 - decryped.at(i));
		}
		else {
			key.push_back(encrpyed.at(i) - decryped.at(i));
		}
	}

	for(int i = 0; i < key.size(); i++) {
		cout << key[i] << endl;
	}

	int module = fullEncrypted.size() - encrpyed.size();

	key.clear();
	key.push_back(8);
	key.push_back(2);
	key.push_back(5);
	key.push_back(1);
	key.push_back(2);
	key.push_back(2);
	key.push_back(0);

	int count = 0;

	vector<char> msg;

	for (int i = 0; i < fullEncrypted.size(); i++) {
		if (fullEncrypted.at(i)< 65 || (fullEncrypted.at(i) > 90 && fullEncrypted.at(i) < 97) || fullEncrypted.at(i) > 122) {
			msg.push_back(fullEncrypted.at(i));
			continue;
		}

		if (fullEncrypted.at(i) - key[count] < 65 && fullEncrypted.at(i) < 90) {
			msg.push_back(fullEncrypted.at(i) - key[count] + 26);
		}
		else if (fullEncrypted.at(i) < 90) {
			msg.push_back(fullEncrypted.at(i) - key[count]);
		}
		else if (fullEncrypted.at(i) - key[count] < 97 && fullEncrypted.at(i) < 122) {
			msg.push_back(fullEncrypted.at(i) - key[count] + 26);
		}
		else if (fullEncrypted.at(i) < 122) {
			msg.push_back(fullEncrypted.at(i) - key[count]);
		}
		count++;
		if (count > 6) {
			count = 0;
		}
	}

	for (int i = 0; i < msg.size(); i++) {
		cout << msg[i];
	}
	cout << endl;

	return 0;

}