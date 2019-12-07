#ifndef NEIGHBOR_LIST_HPP
#define NEIGHBOR_LIST_HPP
#include"../../util/AllUtility.hpp"
#include"../Particle.hpp"
#include"../Box.hpp"
#include<cmath>
#include<vector>
#include<array>
#include<fstream>
#include<string>

namespace lj_simulator {

namespace core {

namespace neighbor_list {

template<typename realT, std::size_t dimension>
class Neighbor_Pair_List {

public:
	
//	Neighbor_list(const std::ifstream& parameter_file);
	Neighbor_list(const realT& cutoff_len, const realT& margin_rate);
	~Neighbor_list() = default;

	void make_NeighborPair(const Particles<realT, dimension>& particle_set, const Box<realT, dimension>& box_environments);

	bool check_NeighborList(const Particles<realT, dimension>& particle_set, const realT& delta_t);

	const std::array<int, 2>& operator()(const std::size_t& idx) {
		return {pair_list[0][idx], pair_list[1][idx]};
	}

	const std::array<int, 2>& operator[](const std::size_t& idx) {
		return {pair_list[0][idx], pair_list[1][idx]};
	}

	std::size_t size() {
		return (pair_list[0].size() == pair_list[1].size()) * pair_list[0].size();
	}

private:

	std::array<std::vector<int>, 2> pair_list;
	realT cutoff_length;
	realT margin_ratio;
	realT max_margin_length;
	realT margin_length;

};
}

using Neighbor_List = lj_simulator::core::neighbor_list::Neighbor_Pair_List;

}
}

#endif /* NEIGHBOR_LIST_HPP */
