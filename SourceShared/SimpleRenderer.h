#pragma once

class ShaderProgram;

class SimpleRenderer
{
public:
    SimpleRenderer();
    ~SimpleRenderer();
    void Draw();
    void UpdateWindowSize(GLsizei width, GLsizei height);

private:
    ShaderProgram* m_pShaderProgram;
    GLuint mProgram;
    GLsizei mWindowWidth;
    GLsizei mWindowHeight;

    GLint mPositionAttribLocation;
    GLint mColorAttribLocation;

    GLint mModelUniformLocation;
    GLint mViewUniformLocation;
    GLint mProjUniformLocation;

    GLuint mVertexPositionBuffer;
    GLuint mVertexColorBuffer;
    GLuint mIndexBuffer;

    int mDrawCount;
};
