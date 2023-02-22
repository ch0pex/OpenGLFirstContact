#pragma once
#include <GL/glew.h>
#include "Dependencies/glm/glm/glm.hpp"
#include "Dependencies/glm/glm/gtc/type_ptr.hpp"

#include "Mesh.h"
#include "ShaderLoader.h"
#include "Camera.h"


class LightRenderer
{
public: 
	LightRenderer(MeshType meshType, Camera* camera); 
	~LightRenderer();

	void draw(); 

	void setPosition(glm::vec3 position);
	void SetColor(glm::vec3 color);
	void setProgram(GLuint Program); 

	glm::vec3 getPosition(); 
	glm::vec3 getColor(); 

private: 
	Camera* camera;
	std::vector<Vertex> vertexs; 
	std::vector<GLuint> indexes; 
	
	glm::vec3 position, color; 
	GLuint vbo; // Vertex buffer object (geometrical information)  
	GLuint ebo; // Element buffer object (index of each vertex) 
	GLuint vao; // Vertex array object  (helper storing all VBOs) 
	GLuint program; // Programa de shaders 
};

