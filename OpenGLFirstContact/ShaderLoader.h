#pragma once
#include <GL/glew.h>
#include <string>

class ShaderLoader
{
private: 
	static std::string readShader(const char* filename); 
	static GLuint createShader(GLenum shaderType, std::string& source, const char* shaderName);

public: 
	static GLuint CreateProgram(const char* vertexShaderFilename, const char* fragmentShaderFilename);
};

