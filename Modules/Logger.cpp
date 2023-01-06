/// @brief 日志管理
/// @brief 只完成了 Console

module Logger;

import <chrono>;
import <format>;
import <string>;
import <iostream>;
using namespace std;

import Global;

namespace XrayN::Tool {
	int8_t XrayN::Tool::ConsoleLogger::GetMaxLogLevel()
	{
		return static_cast<int8_t>(XrayN::Global::MaxConsoleLogLevel);
	}

	void ConsoleLogger::_Log(const string& msg, const Severity& severity) {
		int8_t Tseverity{ static_cast<int8_t>(severity) };

		if (Tseverity <= GetMaxLogLevel()) {
			cout << format("{} [{}]\t{}\n", chrono::system_clock::now(), SeverityStr[Tseverity], msg);
		}
	}

	void ConsoleLogger::LogLine() {
		LogN("---------Line---------\n");
	}

	void ConsoleLogger::LogN(const string& msg) {
		_Log(msg, Severity::none);
	}

	void ConsoleLogger::LogF(const string& msg) {
		_Log(msg, Severity::fatal);
	}

	void ConsoleLogger::LogE(const string& msg) {
		_Log(msg, Severity::error);
	}

	void ConsoleLogger::LogW(const string& msg) {
		_Log(msg, Severity::warning);
	}

	void ConsoleLogger::LogI(const string& msg) {
		_Log(msg, Severity::info);
	}

	void ConsoleLogger::LogD(const string& msg) {
		_Log(msg, Severity::debug);
	}

	void ConsoleLogger::LogV(const string& msg) {
		_Log(msg, Severity::verbose);
	}
}