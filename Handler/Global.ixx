export module Global;

import <string>;
using namespace std;

import Logger;

namespace XrayN {
	export class Global {
	public:
#pragma region const
		const static inline string ConfigFileName = "XrayNConfig.json";
		const static inline string CoreConfigFileName = "config.json";
		const static inline XrayN::Tool::Logger::Severity MaxConsoleLogLevel = XrayN::Tool::Logger::Severity::warning;
#pragma endregion 全局参数
	};
}