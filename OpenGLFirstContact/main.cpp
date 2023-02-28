#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"
#include "Camera.h"
#include "ShaderLoader.h"
#include "MeshRenderer.h"
#include "LightRenderer.h"
#include "TextureLoader.h"

Camera* camera; 
LightRenderer* light;
MeshRenderer* sphere; 



void initGame() {
	glEnable(GL_DEPTH_TEST); 

	GLuint flatShader = ShaderLoader::CreateProgram("Assets/Shaders/FlatModel.vs", "Assets/Shaders/FlatModel.fs"); 
	GLuint textureShader = ShaderLoader::CreateProgram("Assets/Shaders/TextureModel.vs", "Assets/Shaders/TextureModel.fs");
	GLuint texture = TextureLoader::getTextureID("Assets/Textures/Concrete.jpg"); 

	camera = new Camera(45.0f, 800, 600, 0.1f, 100.0f, glm::vec3(0.0f, 5.0f, 6.0f));

	
	light = new LightRenderer(kCube, camera); 
	light->setProgram(flatShader);
	light->setPosition(glm::vec3(0.0f, 0.0f, 0.0f)); 
	
	
	sphere = new MeshRenderer(kCube, camera); 
	sphere->setProgram(textureShader); 
	sphere->setTexture(texture);
	sphere->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	sphere->setScale(glm::vec3(1.0f)); 
}

void inputEvents() {
	
	


}


void renderScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0f, 0.0, 1.0);
	sphere->draw();
}

int main(int argc, char** argv)
{
	if (!glfwInit()) return (-1); 
	GLFWwindow* window = glfwCreateWindow(800,600," Hello OpenGL ",NULL,NULL);
	if (!window) {
		glfwTerminate(); 
		return(-1); 
	}

	glfwMakeContextCurrent(window);

	glewInit(); 
	
	initGame(); 
	
	while (!glfwWindowShouldClose(window))
	{ 
		renderScene(); 
		glfwSwapBuffers(window); 
		glfwPollEvents(); 
	}
	glfwTerminate(); 
	delete(camera); 
	delete(light); 
	delete(sphere); 

	return 0;
} 