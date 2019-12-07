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
	std::size_t system_size;

	std::array<realT, dimension> get_RelativeVectorInCoordinateSpace(const std::size_t& idx_i, const std::size_t& idx_j) {
		std::array<realT, dimension> result;
		result = {coordinate_space[0][idx_j] - coordinate_space[0][idx_i],
				  coordinate_space[1][idx_j] - coordinate_space[1][idx_i],
				  coordinate_space[2][idx_j] - coordinate_space[2][idx_i]};
		return result;
	}

	realT get_VelocitySqr(const std::size_t& idx) {
		realT result = 0.0;
		for (std::size_t idim = 0; idim < dimension; ++idim) {
			result += (velocity_space[idim][idx] * velocity_space[idim][idx]);
		}
		return result;
	}

	std::size_t size() {
		return system_size;
	}

};

}

using Particles = particle::Basic_Particles;

}
}

#endif /* ATOM_HPP */
