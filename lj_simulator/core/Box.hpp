#ifndef BOX_HPP
#define BOX_HPP
#include<vector>
#include<array>

namespace lj_simulator {

namespace core {

namespace box {

template<typename realT, std::size_t dimension>
struct Basic_Box {
	std::array<realT, dimension> cell_size_upper_limit;
	std::array<realT, dimension> cell_size_lower_limit;
	bool is_periodic = false;

	void adjust_PeriodicLength(std::array<realT, dimension>& Vec) {
		if (is_periodic) {
			for (std::size_t idx = 0; idx < dimension; ++idx) {
				// check the sign of Vec[idx]
				int Sign = ((Vec[idx] > 0) - (Vec[idx] < 0));
				// get absolute of Vec[idx]
				realT vec_size = Sign * Vec[idx];

				if (vec_size <= 0.5 * (cell_size_upper_limit[idx] - cell_size_lower_limit[idx])) continue;
				Vec[idx] -= Sign * (cell_size_upper_limit[idx] - cell_size_lower_limit[idx]);
			}
		}
	}

};
}

using Box = lj_simulator::core::box::Basic_Box;

}
}

#endif /* BOX_HPP */
