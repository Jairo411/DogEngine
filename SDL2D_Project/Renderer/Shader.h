#ifndef SHADER_HEADER
#define SHADER_HEADER
#include <string>
#include <unordered_map>
#include <glew.h>
#include <fstream>
#include <iostream>
class ShaderScript
{
public:
	ShaderScript();
	ShaderScript(const char* vertexShader_, const char* fragmentShader_);
	~ShaderScript();
	inline GLuint getProgram() const { return shaderID; }


private:
	std::string fileName, filePath;
	unsigned int shaderID;
	unsigned int vertShaderID;
	unsigned int fragShaderID;
	std::unordered_map<std::string, unsigned int> uniformMap;

	char* readTextFile(const char* filename_);
	void readCompileAttach(const char* vertexShader_, const char* fragmentShader_);
	void link();
	void setUniformLocations();
};
#endif
