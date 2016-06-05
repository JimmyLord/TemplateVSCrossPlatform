#ifndef __GameCore_H__
#define __GameCore_H__

class ShaderProgram;

class GameCore
{
public:
    unsigned int m_WindowWidth;
    unsigned int m_WindowHeight;

    ShaderProgram* m_pShader;
    GLuint m_VBO;

public:
    GameCore();
    virtual ~GameCore();

    void OnSurfaceChanged(int width, int height);
    void LoadContent();

    void Update(float deltatime);
    void Draw();

    void GenerateTriangle();
    void DrawTriangle();
};

#endif //__GameCore_H__