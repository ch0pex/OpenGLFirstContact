#pragma once
#include <string>
#include <GL/glew.h>	
class TextureLoader
{
public: 
	static GLuint getTextureID(std::string texFileName); 
};

