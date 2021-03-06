/*
	1035 Password （20 分)
	To prepare for PAT, the judge sometimes has to generate random passwords for the users. The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one) from l (L in lowercase), or 0 (zero) from O (o in uppercase). One solution is to replace 1 (one) by @, 0 (zero) by %, l by L, and O by o. Now it is your job to write a program to check the accounts generated by the judge, and to help the juge modify the confusing passwords.

	Input Specification:
	Each input file contains one test case. Each case contains a positive integer N (≤1000), followed by N lines of accounts. Each account consists of a user name and a password, both are strings of no more than 10 characters with no space.

	Output Specification:
	For each test case, first print the number M of accounts that have been modified, then print in the following M lines the modified accounts info, that is, the user names and the corresponding modified passwords. The accounts must be printed in the same order as they are read in. If no account is modified, print in one line  There are N accounts and no account is modified where N is the total number of accounts. However, if N is one, you must print There is 1 account and no account is modified instead.

	Sample Input 1:
	3
	Team000002 Rlsp0dfa
	Team000003 perfectpwd
	Team000001 R1spOdfa
	Sample Output 1:
	2
	Team000002 RLsp%dfa
	Team000001 R@spodfa
	Sample Input 2:
	1
	team110 abcdefg332
	Sample Output 2:
	There is 1 account and no account is modified
	Sample Input 3:
	2
	team110 abcdefg222
	team220 abcdefg333
	Sample Output 3:
	There are 2 accounts and no account is modified
*/

#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<char, char> init_replaces() {
	//获取所有需要替换的字符以及其对应替换后的字符
	map<char, char> result;
	result['1'] = '@';
	result['0'] = '%';
	result['l'] = 'L';
	result['O'] = 'o';
	return result;
}
int main() {
	//输入
	int n;
	scanf("%d", &n);
	//获取替换字典
	map<char, char> replaces = init_replaces();
	//初始化两个数组，用于存储替换后的结果
	vector<string> usernames, passwords;
	int replaced_count = 0;	//用于记录一共有多少个密码被替换过
	for (int i = 0; i < n; ++i) {
		//输入某个用户名和密码
		char username[50], password[50];
		bool replaced = false;	//记录当前密码中有字符被替换过
		scanf("%s%s", username, password);
		//对密码中的每一个字符，检查是否为替换字典中的字符
		for (int i = 0; password[i] != '\0'; ++i) {
			if (replaces.find(password[i]) != replaces.end()) {
				//如果是，则替换字符，并修改标志
				password[i] = replaces[password[i]];
				replaced = true;
			}
		}
		if (replaced) {
			//如果标志被置位，则保存这组用户名和密码
			usernames.push_back(username);
			passwords.push_back(password);
			++replaced_count;
		}
	}
	//输出
	if (replaced_count > 0) {
		//如果有密码被替换过，输出被替换的密码个数和替换后的密码
		printf("%d\n", replaced_count);
		for (int i = 0; i < replaced_count; ++i) {
			printf("%s %s\n", usernames[i].c_str(), passwords[i].c_str());
		}
	}
	else {
		//如果没有密码被替换过
		if (n == 1) {
			printf("There is 1 account and no account is modified\n");
		}
		else {
			printf("There are %d accounts and no account is modified\n", n);
		}
	}
	return 0;
}
