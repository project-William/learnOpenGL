#pragma once
#include <glad/glad.h>
#include <string>
#include <iostream>

namespace flappy {
	namespace graphics {
		class Texture {
		private:
			unsigned int m_Texture;
			std::string m_Filepath;
			int m_Index;
		public:
			Texture():m_Texture(0),m_Index(0){}
			Texture(const std::string& filepath, int index);
			void bind()const;
			void unbind()const;
			inline unsigned int getTexture()const { return m_Texture; }
		private:
			void load();
		};
	}
}


