#pragma once
#include "VAOVBO/VertexArray.h"
#include "VAOVBO/VertexBuffer.h"


class Shader;
class Board
{
public:
	Board();
	~Board();
	void Draw(const Shader& shader);

private:
	VertexArray m_VAO;
	std::shared_ptr<VertexBuffer> m_VertexBuffer;
	std::vector<float> vertices = {
		// positions            // normals         // texcoords
		 5.0f, -0.5f,  5.0f,  0.0f, 1.0f, 0.0f,  5.0f,  0.0f,
		-5.0f, -0.5f,  5.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
		-5.0f, -0.5f, -5.0f,  0.0f, 1.0f, 0.0f,   0.0f, 5.0f,
						
		 5.0f, -0.5f,  5.0f,  0.0f, 1.0f, 0.0f,  5.0f,  0.0f,
		-5.0f, -0.5f, -5.0f,  0.0f, 1.0f, 0.0f,   0.0f, 5.0f,
		 5.0f, -0.5f, -5.0f,  0.0f, 1.0f, 0.0f,  5.0f, 5.0f
	};
};