#ifndef FORCE_CALCULATION_HPP
#define FORCE_CALCULATION_HPP
#include"NonLocalForce/NonLocalForce.hpp"
#include"Particle.hpp"
#include"Box.hpp"
#include<array>
#include<vector>


namespace lj_simulator {

namespace core {

namespace force {

template<typename realT, std::size_t dimension>
class Force_Calculation {

public:
	
	Force_Calculation(const realT);

};
}
}
}

#endif /* FORCE_CALCULATION_HPP */
