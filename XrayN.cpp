import <iostream>;
import <string>;

using namespace std;

import Logger;
import Base64;
using namespace XrayN;

int main(const int argc, const string argv[]) {
	Tool::ConsoleLogger CLogger(Tool::ConsoleLogger::Severity::info);
	CLogger.LogI("Welcome to XrayN!");
}