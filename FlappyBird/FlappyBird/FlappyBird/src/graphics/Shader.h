#pragma once
#include <glad/glad.h>
#include "utils/FileUtils.h"
#include "math/Vec2.h"
#include "math/Matrix4f.h"

namespace flappy {
	namespace graphics {
		struct ParseShader {
			std::string vertexShader;
			std::string fragmentShader;
		};

		class Shader {
		private:
			ParseShader m_ShaderSource;
			unsigned int m_Program;
			std::string m_v_Filepath;
			std::string m_f_Filepath;
		public:
			Shader():m_Program(0) {}
			~Shader() {}
			Shader(const std::string& v_filepath, const std::string& f_filepath);
			void enableProgram()const;
			void disableProgram()const;

			void setInt(const std::string& name, int value)const;
			void setFloat(const std::string& name, float value)const;
			void setVec2(const std::string& name, math::Vec2 vec2)const;
			void setVec3(const std::string& name, math::Vec3 vec3)const;
			void setMat4(const std::string& name, math::Matrix4f mat4)const;

		private:
			ParseShader getShaderSource();
			unsigned int compileShader(unsigned int shaderType, const std::string& shadersource);
			unsigned int createProgram();
			int getLocation(const std::string& name) const;
		};
	}
}


