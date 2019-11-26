#ifndef UTIL_FUNCTION_HPP
#define UTIL_FUNCTION_HPP
#include"MiscException.hpp"
#include<string>
#include<vector>
#include<array>
#include<fstream>

namespace lj_simulator {

namespace utility {

namespace functions {

std::vector<std::string> split_String(const std::string& input_string, const char& delimiter) {

	std::vector<std::string> result;
	std::string buffer;
	
	for (const char& input_char : input_string) {
		if ((input_char == delimiter) && (buffer.empty())) continue;
		else if ((input_char == delimiter) && (!buffer.empty())) {
			result.push_back(buffer);
			buffer.clear();
			continue;
		}
		buffer.push_back(input_char);
	}
	if (!buffer.empty()) result.push_back(buffer);

	return result;
}


std::vecotr<std::string> read_ParameterLine(const std::string& input_string, const std::string& parameter_kind) {

	std::vector<std::string> result = split_String(input_string, delimiter);

	if (input_string.empty()) {}
	else if ((input_string[0] == '#') || result.size() == 2) {}
	else throw Misc_Exception("invalid format in parameter file.");

	return result;
}


template<typename realT, std::size_t dimension>
realT calc_Vec2ScholarSqr(const std::array<realT, dimension>& Vec) {
	realT result = 0;

	for (std::size_t idx = 0; idx < dimension; ++idx) {
		result += (Vec[idx] * Vec[idx]);
	}
	return result;
}

}
}
}

#endif /* UTIL_FUNCTION_HPP */
