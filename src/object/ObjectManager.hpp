#pragma once

# include "types.hpp"
# include "Vect2.hpp"
# include "Vect3.hpp"

# include <string>
# include <vector>
# include <sstream>

struct	Face
{
	std::vector<i32>	indices;
};

struct	Object
{
	std::string			name;
	std::vector<Vect3>	vertices;
	std::vector<Face>	faces;
};

class	ObjectManager
{
	public:
		void	loadObj(const std::string &filePath);

	private:
		void	parseO(std::istringstream &iss, Object *&currentObject);
		void	parseV(std::istringstream &iss, Object *&currentObject);

		std::vector<Object>	_objects;

		static u32	_objectIndex;
};
