export module Logger;

import <iostream>;
import <string>;
import <array>;

using namespace std;

namespace XrayN::Tool {
	// Todo
	export class Logger {
		const static inline array SeverityStr{ "NONE", "FATAL", "ERROR", "WARNING", "INFO", "DEBUG", "VERBOSE" };

		const enum class LogMode : char {
			Console,
			File
		};

		LogMode _logMode;

		bool CheckError();

	public:
		enum class Severity : char {
			none,
			fatal,
			error,
			warning,
			info,
			debug,
			verbose
		};

		Logger(const LogMode& logMode = LogMode::Console, const char* LogFile = "log.log");

		~Logger();

		bool Log(const char* msg, const Severity& severity, const char* func = nullptr);
	};

	export class ConsoleLogger {
	public:
		enum class Severity : char {
			none,
			fatal,
			error,
			warning,
			info,
			debug,
			verbose
		};

		ConsoleLogger(const Severity& maxSeverity = Severity::warning);

		void LogLine();

		void LogN(const string& msg);

		void LogF(const string& msg);

		void LogE(const string& msg);

		void LogW(const string& msg);

		void LogI(const string& msg);

		void LogD(const string& msg);

		void LogV(const string& msg);

	private:
		const static inline array SeverityStr{ "NONE", "FATAL", "ERROR", "WARNING", "INFO", "DEBUG", "VERBOSE" };

		size_t _maxSeverity;

	protected:
		void _Log(const string& msg, const Severity& severity= Severity::warning);
	};
}
