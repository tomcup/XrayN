export module Config;

import <string>;
import <vector>;
import <utility>;
using namespace std;

import ESysProxyType;

namespace XrayN::Mode {
	/// <summary>
	/// �����ļ�ʵ����
	/// </summary>
	export class Config {
	public:
		string accessLogPath;
		string errorLogPath;
		string loglevel;
		bool dnsLog{ false };

		bool HandlerService{ false };
		bool LoggerService{ false };
		bool StatsService{ false };

		vector<pair<string, string>> hosts;
		vector<string> serversHosts;
		vector<pair<string, string>> ServerObjects;
		string clientIp;
		string queryStrategy;
		bool disableCache{ false };
		bool disableFallback{ false };
		bool disableFallbackIfMatch{ false };
	};

	export class DefaultConfig {
	};
}