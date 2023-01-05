export module Global;

import <string>;
using namespace std;

namespace XrayN {
	export class Global {
	public:
#pragma region const
		const static inline string ConfigFileName = "XrayNConfig.json";
		const static inline string CoreConfigFileName = "config.json";
#pragma endregion 全局参数
	};
}