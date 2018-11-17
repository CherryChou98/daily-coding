
#include"sha256.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>

//#define DEBUG

using namespace std;

int main()
{
	string fileName("");

	cout << "�������ļ�����" << endl;
#ifndef DEBUG
	cin >> fileName;
#else
	fileName = "10.txt";
#endif // DEBUG

	ifstream getContentFromFile(fileName,   std::ifstream::binary);
	if (!getContentFromFile.is_open()) {
		cout << "�ļ�������" << endl;
		return -1;
	}
	std::stringstream buffer;
	buffer << getContentFromFile.rdbuf();
	std::string contents(buffer.str());
	auto shaBytesList=sha256(contents);
	for (auto val : shaBytesList)
		cout << hex << val;
	return 0;
}
