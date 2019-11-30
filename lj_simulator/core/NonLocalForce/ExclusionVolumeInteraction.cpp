#include"ExclusionVolumeInteraction.hpp"


template<typename realT, std::size_t dimension>
lj_simulator::core::force::Exclusion_Volume_Interaction::Exclusion_Volume_Interaction(const realT& cutoff_len) {
	cutoff_length = cutoff_len;
}


template<typename realT, std::size_t dimension>
std::vector<realT> calc_ExclusionVolumeInteraction(const Particles<realT, dimension>& particle_set, const Neighbor_List<realT, dimension>& pair_list, const Box<realT, dimension>& box_environments) {
	
	std::array<std::vector<realT>, dimension> result;

	for (std::size_t idx = 0; idx < pair_list.size(); ++idx) {
		
	}
}
