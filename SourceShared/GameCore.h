#ifndef __GameCore_H__
#define __GameCore_H__

class SimpleRenderer;

class GameCore
{
public:
    SimpleRenderer* m_pSimpleRenderer;
    
public:
    GameCore();
    virtual ~GameCore();

    void Init();
    void OnSurfaceChanged(int w, int h);
    void Update(float deltatime);
    void Draw();
};

#endif //__GameCore_H__