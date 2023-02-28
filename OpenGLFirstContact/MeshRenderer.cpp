#include "MeshRenderer.h"



MeshRenderer::MeshRenderer(MeshType meshType, Camera* _camera)
{
	camera = _camera; 
	setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	//setRotation(glm::vec3(0.0f, 0.0f, 0.0f)); 
	
	
	switch (meshType)
	{
	case kTriangle: Mesh::setTriData(vertices, indices); break; 
	case kCube: Mesh::setCubeData(vertices, indices); break; 
	case kQuad: Mesh::setQuadData(vertices, indices); break; 
	default: Mesh::setSphereData(vertices, indices);  break;
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao); 

	glGenBuffers(1, &vbo); 
	glBindBuffer(GL_ARRAY_BUFFER, vbo); 
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex), &vertices[0], GL_STATIC_DRAW); 

	glEnableVertexAttribArray(0); 
	glVertexAttribPointer(0, sizeof(Vertex::pos), GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0); 

	glEnableVertexAttribArray(1); 
	glVertexAttribPointer(1, sizeof(Vertex::color), GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(offsetof(Vertex, Vertex::texCoords))); 

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo); 
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Vertex), &indices[0], GL_STATIC_DRAW); 

	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glBindVertexArray(0); 


}

MeshRenderer::~MeshRenderer()
{
}

void MeshRenderer::draw()
{
	glUseProgram(program); 

	//glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), rotation);
	glm::mat4 model = glm::mat4(1.0f); 
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position); 
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale); 
	model = translationMatrix * scaleMatrix; 
	GLuint modelLoc = glGetUniformLocation(program, "model"); 
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glm::mat4 vp = camera->getProjectionMatrix() * camera->getViewMatrix(); 
	GLuint vpLoc = glGetUniformLocation(program, "vp"); 
	glUniformMatrix4fv(vpLoc, 1, GL_FALSE, glm::value_ptr(vp)); 

	
	glBindTexture(GL_TEXTURE_2D, texture); 
	glBindVertexArray(vao); 
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0); 
	glUseProgram(0); 
	glBindVertexArray(0);
}

void MeshRenderer::setPosition(glm::vec3 _position)
{
	position = _position; 
}

void MeshRenderer::setScale(glm::vec3 _scale)
{
	scale = _scale; 
}
/*
void MeshRenderer::setRotation(glm::vec3 _rotation)
{
	rotation = _rotation; 
}
*/
void MeshRenderer::setProgram(GLuint _program)
{
	program = _program; 
}

void MeshRenderer::setTexture(GLuint _texture)
{
	texture = _texture; 
}
