export module Logger;

import <iostream>;
import <string>;
import <array>;

using namespace std;

namespace XrayN::Tool {
	// TODO: 日志文件管理器
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

		void static LogLine();

		void static LogN(const string& msg);

		void static LogF(const string& msg);

		void static LogE(const string& msg);

		void static LogW(const string& msg);

		void static LogI(const string& msg);

		void static LogD(const string& msg);

		void static LogV(const string& msg);

	private:
		const static inline array SeverityStr{ "NONE", "FATAL", "ERROR", "WARNING", "INFO", "DEBUG", "VERBOSE" };

		int8_t static GetMaxLogLevel();

	protected:
		void static  _Log(const string& msg, const Severity& severity = Severity::warning);
	};
}
