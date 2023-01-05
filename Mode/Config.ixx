export module Config;

import <string>;
using namespace std;

import ESysProxyType;

namespace XrayN::Mode {
	/// <summary>
	/// 配置文件实体类
	/// </summary>
	export class Config {
	public:
#pragma region property
		/// <summary>
		/// 允许日志
		/// </summary>
		bool logEnabled;

		/// <summary>
		/// 日志等级
		/// </summary>
		string loglevel;

		string indexId;

		/// <summary>
		/// 允许Mux多路复用
		/// </summary>
		bool muxEnabled;

		XrayN::Mode::ESysProxyType sysProxyType;

		bool autoRun;

		/// <summary>
		/// 启用实时网速和流量统计
		/// </summary>
		bool enableStatistics;

		/// <summary>
		/// 去重时优先保留较旧（顶部）节点
		/// </summary>
		bool keepOlderDedupl;

		/// <summary>
		/// 视图刷新率
		/// </summary>
		unsigned short statisticsFreshRate;

		/// <summary>
		/// 自定义远程DNS
		/// </summary>
		string remoteDNS;

		/// <summary>
		/// Outbound Freedom domainStrategy
		/// </summary>
		string domainStrategy4Freedom;

		/// <summary>
		/// 是否允许不安全连接
		/// </summary>
		bool defAllowInsecure;

		/// <summary>
		/// 域名解析策略
		/// </summary>
		string domainStrategy;

		string domainMatcher;
		string routingIndexId;
		bool enableRoutingAdvanced;
		bool ignoreGeoUpdateCore;
		string systemProxyExceptions;
		string systemProxyAdvancedProtocol;
		unsigned short autoUpdateInterval = 10;
		unsigned short autoUpdateSubInterval = 10;
		bool checkPreReleaseUpdate = false;
		bool enableSecurityProtocolTls13;
		unsigned short trayMenuServersLimit = 20;
		bool autoHideStartup;
#pragma endregion

#pragma region other entities

#pragma endregion nothing yet
	};
}