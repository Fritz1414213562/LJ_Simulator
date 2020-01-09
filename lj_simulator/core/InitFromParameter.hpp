#ifndef INIT_FROM_PARAMETER_HPP
#define INIT_FROM_PARAMETER_HPP
#include"./NonLocalForce/NonLocalForce.hpp"
#include<fstream>
#include<string>

namespace lj_simulator {

namespace core {

namespace force {

template<realT, std::size_t dimension>
class ParameterInitializer {

public:
	
	ParameterInitializer() = default;
	~ParameterInitializer() = default;

private:
	
	template<typename... Arg_type>
	void initialize_From(const std::string& filename, Arg_type& arguments) {
	}


};
}
}
}
#endif /* INIT_FROM_PARAMETER_HPP */
