#pragma once
#include <GL/glew.h>
#include <memory>
#include <string>

namespace eng
{
    class ShaderProgram;

    class GraphicsAPI
    {
    public:
        std::shared_ptr<ShaderProgram> CreateShaderProgram(const std::string& vertext,
            const std::string& fragmentSource);
        void BindShaderProgram(ShaderProgram* shaderProgram);
    };
}