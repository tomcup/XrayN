module;
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
module ConfigReaderHandler;

import <fstream>;
import <format>;
import <typeinfo>;
using namespace std;

import Config;
import Logger;
import Utils;

namespace XrayN::Handler { 
	bool ConfigReaderHandler::LoadConfig(XrayN::Mode::Config& FileName) {
		ifstream input;

		input.open(XrayN::Tool::Utils::GetConfigPath());

		if (!input.is_open()) {
			cerr << "Failed to open the config file!" << endl;
			return false;
		}

		nlohmann::json config;
		config.parse(input, nullptr, false);
		input.close();

		if (config.is_discarded()) {
			cerr << "Config Parse Error" << endl;
			return false;
		}

#pragma region Log
		FileName.accessLogPath = to_string(config["log"]["access"]);
		FileName.errorLogPath = to_string(config["log"]["error"]);
		FileName.loglevel = rightful(config["log"]["loglevel"], { "debug", "info", "warning", "error", "none" }) ? config["log"]["loglevel"] : "warning";
		FileName.dnsLog = config["log"]["dnsLog"].is_boolean() ? static_cast<nlohmann::json::boolean_t>(config["log"]["dnsLog"]) : false;
#pragma endregion

#pragma region API
		if (config["api"]["services"].is_array()) {
			for (string var : config["api"]["services"]) {
				if (var == "HandlerService") {
					FileName.HandlerService = true;
					continue;
				}
				if (var == "LoggerService") {
					FileName.LoggerService = true;
					continue;
				}
				if (var == "StatsService") {
					FileName.StatsService = true;
					continue;
				}
				XrayN::Tool::ConsoleLogger::LogW(format("Incorrect value [api -> services] : {}", var));
			}
		}
		else {
			FileName.StatsService = true;
			XrayN::Tool::ConsoleLogger::LogW(format("Incorrect type [api -> services] : {}, expect type : {}", typeid(config["api"]["services"]).name(), typeid(nlohmann::json::array_t).name()));
		}
#pragma endregion


		return true;
	}

	template<typename T>
	bool XrayN::Handler::ConfigReaderHandler::rightful(const T& value, const list<T>& optional)
	{
		return find(optional.begin(), optional.end(), value) != optional.end();
	}
}