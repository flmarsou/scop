#include "ObjectManager.hpp"

#include <fstream>
#include <iostream>

u32	ObjectManager::_objectIndex = 0;

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
	_objects.emplace_back();
	currentObject = &_objects.back();

	std::string	name;
	iss >> name;

	currentObject->name = name.empty() ? "unnamedObject_" + std::to_string(_objectIndex++) : name;
}

void	ObjectManager::parseV(std::istringstream &iss, Object *&currentObject)
{
	if (!currentObject)
	{
		_objects.emplace_back();
		currentObject = &_objects.back();

		currentObject->name = "unnamedObject_" + std::to_string(_objectIndex++);
	}

	Vect3	vertices;
	iss >> vertices.x >> vertices.y >> vertices.z;

	currentObject->vertices.push_back(vertices);
}
