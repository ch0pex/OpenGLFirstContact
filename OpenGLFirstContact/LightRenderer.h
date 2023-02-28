#pragma once
#include <GL/glew.h>
#include "Dependencies/glm/glm/glm.hpp"
#include "Dependencies/glm/glm/gtc/type_ptr.hpp"

#include "Mesh.h"
#include "Camera.h"


class LightRenderer
{
public: 
	LightRenderer(MeshType meshType, Camera* camera); 
	~LightRenderer();

	void draw(); 

	void setPosition(glm::vec3 position);
	void setColor(glm::vec3 color);
	void setProgram(GLuint Program); 

	glm::vec3 getPosition(); 
	glm::vec3 getColor(); 

private: 
	Camera* camera;
	std::vector<Vertex> vertices; 
	std::vector<GLuint> indexes; 
	
	glm::vec3 position, color; 
	GLuint vao, vbo, ebo, program; 
};


