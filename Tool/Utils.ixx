export module Utils;

import <string>;
import <fstream>;

using namespace std;

namespace XrayN::Tool {
	export class Utils {
	public:
#pragma region ×ÊÔ´Json²Ù×÷
		static ifstream LoadResource(const string& res);

		static string GetConfigPath();
#pragma endregion

	};
}