#include "pch.h"

#include "GameCore.h"
#include "SimpleRenderer.h"

GameCore::GameCore()
{
    m_pSimpleRenderer = 0;
}

GameCore::~GameCore()
{
}

void GameCore::Init()
{
    m_pSimpleRenderer = new SimpleRenderer();
}

void GameCore::OnSurfaceChanged(int w, int h)
{
    m_pSimpleRenderer->UpdateWindowSize( w, h );
}

void GameCore::Update(float deltatime)
{
}

void GameCore::Draw()
{
    m_pSimpleRenderer->Draw();
}
