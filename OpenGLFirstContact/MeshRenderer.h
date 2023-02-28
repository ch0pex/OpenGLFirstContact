#pragma once
#include <GL/glew.h>
#include "Dependencies/glm/glm/glm.hpp"
#include "Dependencies/glm/glm/gtc/type_ptr.hpp"
#include "Camera.h"
#include "Mesh.h"

class MeshRenderer
{

public: 
	MeshRenderer(MeshType meshType, Camera* _camera);
	~MeshRenderer(); 
	void draw(); 

	void setPosition(glm::vec3 _position); 
	void setScale(glm::vec3 _scale); 
	void setRotation(glm::vec3 _rotation); 
	void setProgram(GLuint _program);
	void setTexture(GLuint _texture); 

private: 
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices; 
	glm::mat4 modelMatrix; 
	Camera* camera; 
	glm::vec3 position, scale;
	GLuint vao, vbo, ebo, texture, program; 

};

