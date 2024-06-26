#pragma once
#include <glm.hpp>
#include <string>
#include "glad.h"

class Shader
{
public:
	enum class ShaderType{VERTEX_SHADER, FRAGMENT_SHADER};
	enum class IDType {PROGRAM_ID, SHADER_ID};

public:
	static Shader* Instance();

public:

	GLuint GetShaderProgramID();


	bool CreateProgram();
	bool CreateShaders();

	bool CompileShaders(const std::string& filename, ShaderType shaderType);
	void AttachShaders();
	bool LinkProgram();

	void DetachShaders();
	void DestroyShaders();
	void DestroyProgram();

	bool ErrorManagement(IDType id);


	// Send Uniforms overloads (we also could use templates)
	// Scalar
	bool SendUniformData(const std::string& uniformName, bool data);
	bool SendUniformData(const std::string& uniformName, GLint data);
	bool SendUniformData(const std::string& uniformName, GLuint data);
	bool SendUniformData(const std::string& uniformName, GLfloat data);

	// Vectors
	bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y);
	bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z);
	bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z, GLfloat w);

	// Matrices
	bool SendUniformData(const std::string& uniformName, const glm::mat4& data);
	

private:
	Shader();
	Shader(const Shader&);
	Shader& operator=(Shader&);

private:
	GLuint m_shaderProgramID;
	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
	GLuint m_shaderID;
};

