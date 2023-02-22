#include "Mesh.h"

void Mesh::setTriData(std::vector<Vertex>& vertexs, std::vector<uint32_t>& indexs)
{
	std::vector<Vertex> _vertexs = {
		{{0.0, -1.0f, 0.0},
		 {0.0, 0.0, 1.0},
		 {1.0f, 0.0f, 0.0f},
		 {0.0, 1.0}},

		{{1.0f, 1.0f, 0.0f},
		 {0.0, 0.0, 1.0},
		 {1.0f, 0.0f, 0.0f},
		 {0.0, 1.0}},

		{{0.0, -1.0f ,0.0},
		 {0.0, 0.0, 1.0},
		 {1.0f, 0.0f, 0.0f},
		 {0.0, 1.0}}

	};
	
	std::vector<uint32_t> _indexs = { 0,1,2 };
	indexs = _indexs; 
	vertexs = _vertexs; 

}

void Mesh::setQuadData(std::vector<Vertex>& vertexs, std::vector<uint32_t>& indexs)
{
}

void Mesh::setCubeData(std::vector<Vertex>& vertexs, std::vector<uint32_t>& indexs)
{
}

void Mesh::setSphereData(std::vector<Vertex>& vertexs, std::vector<uint32_t>& indexs)
{
}
