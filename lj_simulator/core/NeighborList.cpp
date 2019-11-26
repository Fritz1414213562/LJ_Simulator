#include"NeighborList.hpp"


template<typename realT, std::size_t dimension>
lj_simulator::core::neighbor_list::NeighborList::NeighborList(const realT& cutoff_len, const realT& margin_rate) {
	cutoff_length = cutoff_len;
	margin_ratio = margin_rate;
	max_margin_length = (margin_ratio - 1.0) * cutoff_length;
	margin_length = (margin_ratio - 1.0) * cutoff_length;
}


template<typename realT, std::size_t dimension>
void lj_simulator::core::neighbor_list::NeighborList::make_NeighborPair(const Particles<realT, dimension>& particle_set, const Box<realT, dimension>& box_environments) {
	if (!pair_list.empty()) pair_list.clear();
	const std::size_t particle_num = particle_set.coordinate_space[0].size();

	for (std::size_t idx_i = 0; idx_i < particle_num - 1; ++idx_i) {
		for (std::size_t idx_j = idx_i + 1; idx_j < particle_num; ++idx_j) {
			std::array<realT, dimension> relative_vector = particle_set.get_RelativeVectorInCoordinateSpace(idx_i, idx_j);

			box_environments.adjust_PeriodicLength(relative_vector);

			realT sqr_scholar_of_rel_vec = lj_simulator::utility::functions::calc_Vec2ScholarSqr(relative_vector);
			if (sqr_scholar_of_rel_vec > cutoff_length) continue;

			pair_list[0].push_back(idx_i);
			pair_list[1].push_back(idx_j);
		}

	}
}


template<typename realT, std::size_t dimension>
bool lj_simulator::core::neighbor_list::NeighborList::check_NeighborList(const Particles<realT, dimension>& particle_set, const realT& delta_t) {

	bool result = false;

	realT max_velocity_sqr = 0.0;

	for (std::size_t idx = 0; idx < particle_set.velocity_space.size(); ++idx) {
		realT velocity_sqr = particle_set.get_VelocitySqr(idx);
		if (max_velocity_sqr < velocity_sqr) max_velocity_sqr = velocity_sqr;
	}
	realT max_velocity = std::sqrt(max_velocity_sqr);
	margin_length -= 2.0 * max_velocity * delta_t;
	if (margin_length < 0.0) {
		margin_length = max_margin_length;
		result = true;
	}
	return result;
}
