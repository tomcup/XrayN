export module Config;

import <string>;
using namespace std;

import ESysProxyType;

namespace XrayN::Mode {
	/// <summary>
	/// �����ļ�ʵ����
	/// </summary>
	export class Config {
	public:
#pragma region property
		/// <summary>
		/// ������־
		/// </summary>
		bool logEnabled;

		/// <summary>
		/// ��־�ȼ�
		/// </summary>
		string loglevel;

		string indexId;

		/// <summary>
		/// ����Mux��·����
		/// </summary>
		bool muxEnabled;

		XrayN::Mode::ESysProxyType sysProxyType;

		bool autoRun;

		/// <summary>
		/// ����ʵʱ���ٺ�����ͳ��
		/// </summary>
		bool enableStatistics;

		/// <summary>
		/// ȥ��ʱ���ȱ����Ͼɣ��������ڵ�
		/// </summary>
		bool keepOlderDedupl;

		/// <summary>
		/// ��ͼˢ����
		/// </summary>
		unsigned short statisticsFreshRate;

		/// <summary>
		/// �Զ���Զ��DNS
		/// </summary>
		string remoteDNS;

		/// <summary>
		/// Outbound Freedom domainStrategy
		/// </summary>
		string domainStrategy4Freedom;

		/// <summary>
		/// �Ƿ�������ȫ����
		/// </summary>
		bool defAllowInsecure;

		/// <summary>
		/// ������������
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