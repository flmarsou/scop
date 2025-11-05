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
		void	Load(const std::string &filePath);

	private:
		void	parseO(std::istringstream &iss, Object *&currentObject);
		void	parseV(std::istringstream &iss, Object *&currentObject);
		void	parseF(std::istringstream &iss, Object *&currentObject);

		void	printObject(const Object &object);

		std::vector<Object>	_objects;

		static u32	_objectIndex;
};
