#include "Shader.h"
#include "..\Renderer\Shaders\Shader.h"

ShaderScript::ShaderScript()
{
}

ShaderScript::ShaderScript(const char* vertexShader_, const char* fragmentShader_)
{
    readCompileAttach(vertexShader_, fragmentShader_);
    link();
}

ShaderScript::~ShaderScript()
{
    glDetachShader(shaderID, fragShaderID);
    glDetachShader(shaderID, vertShaderID);
    glDeleteShader(fragShaderID);
    glDeleteShader(vertShaderID);
    glDeleteProgram(shaderID);  
        
}

char* ShaderScript::readTextFile(const char* filename_)
{
    char* buffer = nullptr;
    std::ifstream file(filename_, std::ios::binary);
    if (file.is_open())
    {
        file.seekg(0, std::ios::end);
        int bufferSize = (int)file.tellg(); // get length 
        if (bufferSize == 0)
        {
            std::cout << "Cant readshader file: " << fileName << std::endl;
        }
        buffer = new char[(int)(bufferSize + 1)];
        file.seekg(0, std::ios::beg);
        file.read(buffer, bufferSize);
        buffer[bufferSize] = NULL;
        file.close();
    }
    else
    {
        std::cout << "Can't open shader file:" << std::endl;
    }
    return buffer;
}

void ShaderScript::readCompileAttach(const char* vertexShader_, const char* fragmentShader_)
{
	GLint status;
	shaderID = 0;
	fragShaderID = 0;

	try
	{
		const char* vertFile = readTextFile(vertexShader_);
		const char* fragFile = readTextFile(fragmentShader_);
		if (vertFile == nullptr || fragFile == nullptr) return;

		/// GL_VERTEX SHADER and GL_FRAGMENT_SHADER ARE DEFINE IN GLEW.H
		vertShaderID = glCreateShader(GL_VERTEX_SHADER); // Just assigns a special pointer to vertShaderID as well fragment Shader
		fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		if (vertShaderID == 0 || fragShaderID == 0)
		{
			std::cout << "Can't create a new shader " << std::endl;
		}
		glShaderSource(vertShaderID, 1, &vertFile, 0);
		glShaderSource(fragShaderID, 1, &fragFile, 0);

		glCompileShader(vertShaderID); // start with the vert shader
		//check for errors 
		glGetShaderiv(vertShaderID, GL_COMPILE_STATUS, &status);
		if (status == 0)
		{
			GLsizei errorLogSize = 0;
			GLsizei titleLength;
			std::string errorLog = "VERT:\n";
			titleLength = errorLog.length();
			glGetShaderiv(vertShaderID, GL_INFO_LOG_LENGTH, &errorLogSize);
			errorLog.resize(titleLength + errorLogSize); // resize does what? 
			glGetShaderInfoLog(vertShaderID, errorLogSize, &errorLogSize, &errorLog[titleLength]);
			std::cout << errorLog << std::endl;
		}

		glCompileShader(fragShaderID);

		glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &status);
		if (status == 0)
		{
			GLsizei errorLogSize = 0;
			GLsizei titleLength;
			std::string errorLog = "FRAG:\n";
			titleLength = errorLog.length();
			glGetShaderiv(fragShaderID, GL_INFO_LOG_LENGTH, &errorLogSize);
			errorLog.resize(titleLength + errorLogSize); // resize does what? 
			glGetShaderInfoLog(fragShaderID, errorLogSize, &errorLogSize, &errorLog[titleLength]);
			std::cout << errorLog << std::endl;
		}

		shaderID = glCreateProgram();
		glAttachShader(shaderID, fragShaderID);
		glAttachShader(shaderID, vertShaderID);
		if (vertFile)delete[] vertFile;
		if (fragFile)delete[] fragFile;


	}
	catch (const std::string error)
	{
		std::cout << error << std::endl;
	}
}

void ShaderScript::link()
{
	///Shader Program checking
	GLint status;
	try
	{
		glLinkProgram(shaderID);
		//check for errors
		glGetProgramiv(shaderID, GL_LINK_STATUS, &status);
		if (status == 0)
		{
			GLsizei errorLogSize = 0;
			std::string errorLog;
			glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &errorLogSize);
			errorLog.resize(errorLogSize);
			glGetProgramInfoLog(shaderID, errorLogSize, &errorLogSize, &errorLog[0]);
		}

	}
	catch (const std::exception&)
	{
		std::cout << "ERROR: " << std::endl;
	}
}

void ShaderScript::setUniformLocations()
{
}
