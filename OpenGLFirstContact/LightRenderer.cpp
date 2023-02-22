#include "LightRenderer.h"

LightRenderer::LightRenderer(MeshType meshType, Camera* camera) {
	this->camera = camera;
	switch (meshType)
	{
	case kTriangle:
		Mesh::setTriData(vertexs, indexes); 
		break;
	case kQuad:
		Mesh::setQuadData(vertexs, indexes); 
		break;
	case kCube:
		Mesh::setCubeData(vertexs, indexes); 
		break;
	default:
		Mesh::setSphereData(vertexs, indexes);
		break;
	}
	glGenVertexArrays(1, &vao); 
	glBindVertexArray(vao); 
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo); 
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexs.size(), &vertexs[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0); 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) 0);

}