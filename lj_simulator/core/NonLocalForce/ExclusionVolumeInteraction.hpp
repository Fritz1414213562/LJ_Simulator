#ifndef EXCLUSION_VOLUME_INTERACTION_HPP
#define EXCLUSION_VOLUME_INTERACTION_HPP
#include"NeighborList.hpp"
#include"../Particle.hpp"
#include"../Box.hpp"
#include<array>
#include<vector>

namespace lj_simulator {

namespace core {

namespace force {

template<typename realT, std::size_t dimension>
class Exclusion_Volume_Interaction {

public:

	Exclusion_Volume_Interaction(const realT& cutoff_len, const realT& force_epsilon, const realT& force_sigma);
	~Exclusion_Volume_Interaction() = default;

	std::array<std::vector<realT>, dimension> operator()(const Particles<realT, dimension>& particle_set, const Neighbor_List<realT, dimension>& pair_list, const Box<realT, dimension>& box_environments) {
		return calc_ExclusionVolumeInteraction(particle_set, pair_list, box_environments);
	}


private:

	realT cutoff_length;
	realT exv_epsilon;
	realT exv_sigma;

	std::array<std::vector<realT>, dimension> calc_ExclusionVolumeInteraction(const Particles<realT, dimension>& particle_set, const Neighbor_List<realT, dimension>& pair_list, const Box<realT, dimension>& box_environments);	

};
}
}
}

#endif /* EXCLUSION_VOLUME_INTERACTION_HPP */
