export module ConfigReaderHandler;

import <string>;
import <fstream>;
import <iostream>;
import <list>;
using namespace std;

import Global;
import Config;
import Utils;

namespace XrayN::Handler {
	/// @brief parse the config file
	export class ConfigReaderHandler {
	public:
		/// @brief load and parse the config
		/// @param FileName 
		/// @return is succeed
		static bool LoadConfig(XrayN::Mode::Config& FileName);
	private:
		template<typename T>
		static bool rightful(const T& value, const list<T>& optional);
	};
}