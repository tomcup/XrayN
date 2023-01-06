module Utils;

import <string>;
import <fstream>;

using namespace std;

import Global;
import Config;

namespace XrayN::Tool {
	string XrayN::Tool::Utils::GetConfigPath()
	{
		return Global::CoreConfigFileName;
	}
}