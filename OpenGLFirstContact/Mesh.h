#pragma once
#include<vector>
#include "Dependencies/glm/glm/glm.hpp"


enum MeshType {
	kTriangle = 0,
	kQuad, 
	kCube,
	kSphere
};

struct Vertex {
	glm::vec3 pos; 
	glm::vec3 normal; 
	glm::vec3 color; 
	glm::vec2 texCords; 
};


class Mesh
{
public: 
	static void setTriData(std::vector<Vertex>& vertexs, std::vector<uint32_t>& indexs); 
	static void setQuadData(std::vector<Vertex>& vertexs, std::vector<uint32_t>& indexs); 
	static void setCubeData(std::vector<Vertex>& vertexs, std::vector<uint32_t>& indexs); 
	static void setSphereData(std::vector<Vertex>& vertexs, std::vector<uint32_t>& indexs); 
};

