#include <GL/glew.h>
#include <GLFW/glfw3.h>



void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); 
	glClearColor(1.0, 0.0, 0.0, 1.0); 
	
}



int main(int argc, char** argv)
{
	uint16_t hola; 
	glfwInit(); 
	GLFWwindow* window = glfwCreateWindow(800,600," Hello OpenGL ",NULL,NULL);
	glfwMakeContextCurrent(window); 
	glewInit(); 

	while (!glfwWindowShouldClose(window))
	{
		renderScene(); 

		glfwSwapBuffers(window); 
		glfwPollEvents(); 
	}
	glfwTerminate(); 

	return 0;
} 