#include "ObjectManager.hpp"

#include "debug.hpp"

#include <fstream>
#include <iostream>

u32	ObjectManager::_objectIndex = 0;

void	ObjectManager::Load(const std::string &filePath)
{
	std::ifstream	file(filePath);
	if (!file.is_open())
		throw std::runtime_error("Failed to open OBJ file: " + filePath);

	u32		currentAmount = _objects.size();
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
		else if (prefix == "f")
			parseF(iss, currentObject);
	}

	while (currentAmount < _objects.size())
	{
		printObject(_objects[currentAmount]);
		printLog(LogType::Info, "Object \"" + _objects[currentAmount++].name + "\" created");
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

void	ObjectManager::parseF(std::istringstream &iss, Object *&currentObject)
{
	if (!currentObject)
		return ;

	Face	face;

	std::string	token;
	while (iss >> token)
	{
		i32	index = std::stoi(token);
		face.indices.push_back(index - 1);
	}

	currentObject->faces.push_back(face);
}

void	ObjectManager::printObject(const Object &object)
{
	std::cout << "-> Name: " << object.name << '\n';
	std::cout << "-> Vertices: " << '\n';
	for (Vect3 vertices : object.vertices)
		std::cout << "   " << vertices << '\n';
	for (u32 face = 0; face < object.faces.size(); ++face)
	{
		std::cout << "-> Face[" << face << "]: ";
		for (u32 index : object.faces[face].indices)
			std::cout << index << " ";
		std::cout << '\n';
	}
}
