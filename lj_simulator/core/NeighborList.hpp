#ifndef NEIGHBOR_LIST_HPP
#define NEIGHBOR_LIST_HPP
#include"abstract/Initialized.hpp"
#include"../util/AllUtility.hpp"
#include"Particle.hpp"
#include<vector>
#include<array>
#include<fstream>
#include<string>

namespace lj_simulator {

namespace core {

namespace neighbor_list : public Init_By {

template<typename realT, std::size_t dimension>
class Neighbor_list {

public:
	
	Neighbor_list(const std::ifstream& parameter_file);
	~Neighbor_list() = default;

	void make_NeighborPair(const Particles& particle_set);


private:

	std::array<std::vector<int>, 2> pair_list;
	realT cutoff_length;
	realT MARGIN_RATIO;
	// for reading paramter file.
	const std::string row_name_cutoff_length = "cutoff_length";
	const std::string row_name_margin_ratio = "margin_ratio";

	void be_InitializedBy(const std::ifstream& ifs);

};
}
}
}

#endif /* NEIGHBOR_LIST_HPP */
