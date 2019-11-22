#include"NeighborList.hpp"


lj_simulator::core::neighbor_list::NeighborList::NeighborList(const std::ifstream& parameter_file) {
	be_InitializedBy(parameter_file);
}


void lj_simulator::core::neighbor_list::NeighborList::make_NeighborPair(const Particles& particle_set) {
}




// private

void lj_simulator::core::neighbor_list::NeighborList::be_InitializedBy(const std::ifstream& ifs) {

	std::string buffer;

	while (std::getline(ifs, buffer)) {

		std::vector<std::string> split_line;

		try {
			split_line = read_ParameterLine(buffer, delim);
		}
		catch (Misc_Exception e) {
			std::cerr << e.what() << std::endl;
			std::exit(1);
		}


	}

}
