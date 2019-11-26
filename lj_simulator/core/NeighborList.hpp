#ifndef NEIGHBOR_LIST_HPP
#define NEIGHBOR_LIST_HPP
#include"../util/AllUtility.hpp"
#include"Particle.hpp"
#include"Box.hpp"
#include<cmath>
#include<vector>
#include<array>
#include<fstream>
#include<string>

namespace lj_simulator {

namespace core {

namespace neighbor_list {

template<typename realT, std::size_t dimension>
class Neighbor_list {

public:
	
//	Neighbor_list(const std::ifstream& parameter_file);
	Neighbor_list(const realT& cutoff_len, const realT& margin_rate);
	~Neighbor_list() = default;

	void make_NeighborPair(const Particles<realT, dimension>& particle_set, const Box<realT, dimension>& box_environments);

	bool check_NeighborList(const Particles<realT, dimension>& particle_set, const realT& delta_t);


private:

	std::array<std::vector<int>, 2> pair_list;
	realT cutoff_length;
	realT margin_ratio;
	realT max_margin_length;
	realT margin_length;

};
}
}
}

#endif /* NEIGHBOR_LIST_HPP */
