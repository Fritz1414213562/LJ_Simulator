#ifndef MISC_EXCEPTION_HPP
#define MISC_EXCEPTION_HPP
#include<string>

namespace lj_simulator {

namespace utility {

namespace exception_process {

class Miscellaneous_Exception {

public:
	Miscellaneous_Exception(const std::string& error_message) : what_exception(error_message) {}
	const std::string& what() {return what_exception;}

private:
	const std::string what_exception;

};
}
}

using Misc_Exception = utility::exception_process::Miscellaneous_Exception;

}

#endif /* MISC_EXCEPTION_HPP */
