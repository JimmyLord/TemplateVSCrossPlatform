#include "pch.h"
#include "../Core/CoreHeaders.h"

#include "GameCore.h"

GameCore::GameCore()
{
    m_WindowWidth = -1;
    m_WindowHeight = -1;

    m_pShader = 0;
    m_VBO = 0;
}

GameCore::~GameCore()
{
    glDeleteBuffers( 1, &m_VBO );
}

void GameCore::OnSurfaceChanged(int width, int height)
{
    glViewport( 0, 0, width, height );

    m_WindowWidth = width;
    m_WindowHeight = height;
}

void GameCore::LoadContent()
{
    // turn on depth buffer testing.
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LESS );

    // turn on alpha blending.
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // create our shaders.
    m_pShader = new ShaderProgram( "Data/Shaders/white.vert", "Data/Shaders/white.frag" );

    GenerateTriangle();

    CheckForGLErrors();
}

void GameCore::Update(float deltatime)
{
}

void GameCore::Draw()
{
    // clear the screen to dark blue.
    glClearColor( 0.0f, 0.0f, 0.4f, 0.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // use our shader.
    glUseProgram( m_pShader->GetProgram() );

    // draw the triangle
    DrawTriangle();

    CheckForGLErrors();
}

void GameCore::GenerateTriangle()
{
    // ATM this can only be called once, so we assert if it's called again with a VBO already allocated
    assert( m_VBO == 0 );

    // vertex position info for a triangle
    float vertexattributes[] = { 0.0f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f };

    // gen and fill buffer with our attributes
    glGenBuffers( 1, &m_VBO );
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof(float)*6, vertexattributes, GL_STATIC_DRAW );

    // check for errors
    CheckForGLErrors();
}

void GameCore::DrawTriangle()
{
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

    GLint loc = glGetAttribLocation( m_pShader->GetProgram(), "a_Position" );
    if( loc != -1 )
    {
        glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0 );
        glEnableVertexAttribArray( loc );
    }

    // check for errors
    CheckForGLErrors();

    glDrawArrays( GL_TRIANGLES, 0, 3 );
}
