#pragma once
#include<GL/glew.h>
#include<iostream>

#ifdef REL
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
                  x;
#else
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
                  x;\
                  ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#endif

inline void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

inline bool GLLogCall(const char* function, const char* file, const int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "gl error: " << error << ": " << function << " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}

using uint = unsigned int;
using uchar = unsigned char;