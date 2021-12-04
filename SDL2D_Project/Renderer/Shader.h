#ifndef SHADER_HEADER
#define SHADER_HEADER
#include <string>
#include <unordered_map>
#include <glew.h>
#include <glm/glm.hpp>
#include <fstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
class ShaderScript
{
public:
	ShaderScript();
	ShaderScript(const char* vertexShader_, const char* fragmentShader_);
	~ShaderScript();
	inline GLuint getProgram() const { return this->shaderID; }
	inline void Use() const { glUseProgram(this->shaderID);};

	void SetFloat(const char* name, float value);
	void SetInteger(const char* name, int value);
	void SetVector2f(const char* name, glm::vec2 &value);
	void SetVector3f(const char* name, glm::vec3& value);
	void SetVector4f(const char* name, glm::vec4& value);
	void SetMatrix(const char* name, glm::mat4& matrix);

	

private:
	
	char* readTextFile(const char* filename_);
	void readCompileAttach(const char* vertexShader_, const char* fragmentShader_);
	void link();
	void setUniformLocations();

	std::string fileName, filePath;
	unsigned int shaderID;
	unsigned int vertShaderID;
	unsigned int fragShaderID;
	std::unordered_map<std::string, unsigned int> uniformMap;
};
#endif
