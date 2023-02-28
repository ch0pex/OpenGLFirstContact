#include "LightRenderer.h"

LightRenderer::LightRenderer(MeshType meshType, Camera* camera) {
	this->camera = camera;
	switch (meshType)
	{
	case kTriangle:
		Mesh::setTriData(vertices, indexes); 
		break;
	case kQuad:
		Mesh::setQuadData(vertices, indexes); 
		break;
	case kCube:
		Mesh::setCubeData(vertices, indexes); 
		break;
	default:
		Mesh::setSphereData(vertices, indexes);
		break;
	}

	// VAO (helper storing) 
	glGenVertexArrays(1, &vao); 
	glBindVertexArray(vao); 
	
	//VBO (geometrical information) 
	glGenBuffers(1, &vbo); // GEN BUFFER 
	glBindBuffer(GL_ARRAY_BUFFER, vbo); // BIND BUFFER 
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW); // Add data to GPU BUFFER

	//Enable vertex attribute for position 
	glEnableVertexAttribArray(0);  
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) 0);
	//Enable vertex attribute for vertex color 
	glEnableVertexAttribArray(1); 
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, Vertex::normal)));

	// EBO (index of each vertex) 
	glGenBuffers(1, &ebo);  // GEN BUFFER (ebo will have the id)  
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo); // BIND BUFFER (attach de
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indexes.size(), &indexes[0], GL_STATIC_DRAW); // Add data to GPU BUFFER 

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind de array buffer 
	glBindVertexArray(0); // Unbind de vertex array 
}

LightRenderer::~LightRenderer()
{
}

void LightRenderer::draw() {
	// 2dPoint = projectionMatrix * viewMatrix * modelMatrix * point
	
	glUseProgram(this->program); //Indicate shader program compiled in the gpu to use 

	glm::mat4 model = glm::mat4(1.0f); 
	model = glm::translate(glm::mat4(1.0), position);
	GLint modelLoc = glGetUniformLocation(program, "model"); // Get Model Location in program
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); // Passing the value of model in the program

	glm::mat4 view = camera->getViewMatrix();
	GLint viewLoc = glGetUniformLocation(program, "view"); // Get View Location in program 
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));  // Passing the value of view in the program 
	
	glm::mat4 projection = camera->getProjectionMatrix();
	GLint projectionLoc = glGetUniformLocation(program, "projection"); // Get Projection location in program
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection)); // Passing the value of projection in the program

	//Draw the object
	glBindVertexArray(vao); 
	glDrawElements(GL_TRIANGLES, indexes.size(), GL_UNSIGNED_INT, 0); 
	glBindVertexArray(0);
	glUseProgram(0);
}

void LightRenderer::setPosition(glm::vec3 _position) {
	position = _position; 
}

void LightRenderer::setColor(glm::vec3 _color) {
	color = _color;
}

void LightRenderer::setProgram(GLuint _program) {
	program = _program;
}

glm::vec3 LightRenderer::getPosition()
{
	return glm::vec3();
}

glm::vec3 LightRenderer::getColor()
{
	return glm::vec3();
}

