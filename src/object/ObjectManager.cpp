#include "ObjectManager.hpp"

#include <fstream>

void	ObjectManager::loadObj(const std::string &filePath)
{
	std::ifstream	file(filePath);
	if (!file.is_open())
		throw std::runtime_error("Failed to open OBJ file: " + filePath);

	Object	*currentObject = nullptr;

	std::string	line;
	while (std::getline(file, line))
	{
		std::istringstream	iss(line);
		std::string			prefix;
		iss >> prefix;

		if (prefix == "#")
			continue ;
		else if (prefix == "o")
			parseO(iss, currentObject);
		else if (prefix == "v")
			parseV(iss, currentObject);
	}
}

void	ObjectManager::parseO(std::istringstream &iss, Object *&currentObject)
{
	std::string	name;
	iss >> name;

	_objects.emplace_back();
	currentObject = &_objects.back();

	currentObject->name = name;
}

void	ObjectManager::parseV(std::istringstream &iss, Object *&currentObject)
{
	if (!currentObject)
	{
		_objects.emplace_back();
		currentObject = &_objects.back();
	}

	Vect3	vertices;
	iss >> vertices.x >> vertices.y >> vertices.z;

	currentObject->vertices.push_back(vertices);
}
