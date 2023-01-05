module Logger;

import <chrono>;
import <format>;
import <string>;
import <iostream>;

using namespace std;

namespace XrayN::Tool {
	ConsoleLogger::ConsoleLogger(const Severity& maxSeverity) {
		_maxSeverity = static_cast<size_t>(maxSeverity);
	}

	void ConsoleLogger::_Log(const string& msg, const Severity& severity) {
		size_t Tseverity{ static_cast<size_t>(severity) };

		if (Tseverity <= _maxSeverity) {
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