#ifndef ATOM_HPP
#define ATOM_HPP
#include<vector>
#include<array>

namespace lj_simulator {

namespace core {

namespace particle {

template<typename realT, std::size_t dimension>
struct Basic_Particles {
	std::array<std::vector<realT>, dimension> coordinate_space;
	std::array<std::vector<realT>, dimension> velocity_space;
	std::vector<realT> mass;
	std::vector<realT> radii;
};

}

using Particles = particle::Basic_Particles;

}
}

#endif /* ATOM_HPP */
