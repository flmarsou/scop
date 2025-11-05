#pragma once

# include "ObjectManager.hpp"

struct	Mesh
{
	u32	_VAO;
	u32	_VBO;
	u32	_EBO;
};

class	MeshManager
{
	public:
		void	Init(const Object &object);

	private:
		std::vector<Mesh>	_meshes;
};
