export module Base64;

import <algorithm>;
import <string>;

using namespace std;

namespace XrayN::Tool {
	export class Base64 {
		const static inline string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	public:
		static bool is_base64(const unsigned char& c);

		static string base64_decode(const string& data);

		static string base64_encode(const string& data);
	};
}