/// @brief Base64 检查，编码，解码
/// @brief 基本完成

module Base64;

import <string>;

using namespace std;

namespace XrayN::Tool {
	bool is_base64(const unsigned char& c) {
		return isalnum(c) || (c == '+') || (c == '/');
	}

	string Base64::base64_decode(const string& data) {
		int counter{};
		size_t bit_stream{};
		string decoded;
		int offset{};
		for (unsigned char c : data) {
			size_t num_val = Base64::BASE64_CHARS.find(c);
			if (num_val != string::npos) {
				offset = 18 - counter % 4 * 6;
				bit_stream += num_val << offset;
				if (offset == 12) {
					decoded += static_cast<char>(bit_stream >> 16 & 0xff);
				}
				if (offset == 6) {
					decoded += static_cast<char>(bit_stream >> 8 & 0xff);
				}
				if (offset == 0 && counter != 4) {
					decoded += static_cast<char>(bit_stream & 0xff);
					bit_stream = 0;
				}
			}
			else if (c != '=') {
				return std::string();
			}
			counter++;
		}
		return decoded;
	}

	string Base64::base64_encode(const string& data) {
		int counter = 0;
		uint32_t bit_stream = 0;
		std::string encoded;
		int offset = 0;
		for (unsigned char c : data) {
			auto num_val = static_cast<unsigned int>(c);
			offset = 16 - counter % 3 * 8;
			bit_stream += num_val << offset;
			if (offset == 16) {
				encoded += Base64::BASE64_CHARS.at(bit_stream >> 18 & 0x3f);
			}
			if (offset == 8) {
				encoded += Base64::BASE64_CHARS.at(bit_stream >> 12 & 0x3f);
			}
			if (offset == 0 && counter != 3) {
				encoded += Base64::BASE64_CHARS.at(bit_stream >> 6 & 0x3f);
				encoded += Base64::BASE64_CHARS.at(bit_stream & 0x3f);
				bit_stream = 0;
			}
			counter++;
		}
		if (offset == 16) {
			encoded += Base64::BASE64_CHARS.at(bit_stream >> 12 & 0x3f);
			encoded += "==";
		}
		if (offset == 8) {
			encoded += Base64::BASE64_CHARS.at(bit_stream >> 6 & 0x3f);
			encoded += '=';
		}
		return encoded;
	}
}