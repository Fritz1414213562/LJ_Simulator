#ifndef INITIALIZED_HPP
#define INITIALIZED_HPP
#include<fstream>

namespace lj_simulator {

namespace core {

namespace abstract {

class Objects_Initialized_By_Parameter_File {

protected:
	virtual void be_InitializedBy(const std::ifstream& ifs) = 0;
};

}

using Init_By = abstract::Objects_Initialized_By_Parameter_File;

}
}

#endif /* INITIALIZED_HPP */
