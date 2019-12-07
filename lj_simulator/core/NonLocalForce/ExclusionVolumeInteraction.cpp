#include"ExclusionVolumeInteraction.hpp"


template<typename realT, std::size_t dimension>
lj_simulator::core::force::Exclusion_Volume_Interaction::Exclusion_Volume_Interaction(const realT& cutoff_len, const realT& force_epsilon, const realT& force_sigma) {
	cutoff_length = cutoff_len;
	exv_epsilon = force_epsilon;
	exv_sigma = force_sigma;
}


template<typename realT, std::size_t dimension>
std::array<std::vector<realT>, dimension> calc_ExclusionVolumeInteraction(const Particles<realT, dimension>& particle_set, const Neighbor_List<realT, dimension>& pair_list, const Box<realT, dimension>& box_environments) {
	
	// resize the force vector
	std::array<std::vector<realT>, dimension> result;
	for (std::size_t idim = 0; idim < dimension; ++idim) {
		result[idim].resize(particle_set.size(), 0.0);
	}

	// calculate exv force from the pair list
	for (std::size_t idx = 0; idx < pair_list.size(); ++idx) {
		const std::array<int, 2>& ipair = pair_list[idx];
		std::array<realT, dimension>& diff_vector = particle_set.get_RelativeVectorInCoordinateSpace(ipair[0], ipair[1]);
		box_environments.adjust_PeriodicLength(diff_vector);
		realT dist2 = lj_simulator::utility::functions::calc_Vec2ScholarSqr(diff_vector);
		
		if (dist2 > cutoff_length * cutoff_length) continue;

		// force calculation
		realT dist6 = dist2 * dist2 * dist2;
		realT sigma2 = exv_sigma * exv_sigma;
		realT sigma6 = sigma2 * sigma2 * sigma2;
		realT sigma12 = sigma6 * sigma6;

		realT force_scholar_part = exv_epsilon * sigma12 * (24.0 * dist6 / sigma6 - 48.0) / (dist6 * dist6 * dist2);
		for (std::size_t idim = 0; idim < dimension; ++idim) {
			result[idim][ipair[0]] += force_scholar_part * diff_vector[idim];
			result[idim][ipair[1]] -= force_scholar_part * diff_vector[idim];
		}
	}
	return result;
}
