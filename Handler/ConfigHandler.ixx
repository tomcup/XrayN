module;
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
export module ConfigHandler;

import <string>;
import <fstream>;
import <iostream>;
using namespace std;

import Global;
import Config;
import Utils;

namespace XrayN::Handler {
	/// <summary>
	/// 配置文件处理类
	/// </summary>
	export class ConfigHandler {
	public:
		static bool LoadConfig(XrayN::Mode::Config& FileName) {
			ifstream input(XrayN::Tool::Utils::GetConfigPath());
			nlohmann::json config;
			try {
				input >> config;
			}
			catch (const exception& e) {
				cerr << e.what() << endl;
			}
			input.close();
			return true;
		}
	};
}