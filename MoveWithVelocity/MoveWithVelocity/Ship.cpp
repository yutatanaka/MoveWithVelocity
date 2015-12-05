#include "Ship.h"

#include <math.h>
#include "DxLib.h"
#include "GameManager.h"

Ship::Ship():
    m_position(vec2f(Window::Width/2,Window::Height/2)),
    m_velocity(),
    m_moveSpeed(3.0f),
    INCREASE_ANGLE_VALUE(0.05f),
    m_nowAngle(0)    
{
}


Ship::~Ship()
{
}

void Ship::Update()
{

    Input();

    Move();

    WarpPosition();

}



void Ship::Render()
{
    const int COLOR = 0xff0000;
    const int HEAD_SIZE = 3;
    const int TALE_SIZE = 6;
    const int NECK_LENGTH = 5;

    //! 先端（頭）の描画
    DrawCircle(m_position.x + (NECK_LENGTH * m_velocity.x),
               m_position.y + (NECK_LENGTH * m_velocity.y),
               HEAD_SIZE, COLOR/2);

    //! 胴体（尾）の描画
    DrawCircle(m_position.x, m_position.y, TALE_SIZE, COLOR);

    PrintLog();
}

void Ship::PrintLog()
{
    const int STRING_DISTANCE = 20;
    const int COLOR = 0xffffff;
    DrawFormatString(0, 0, COLOR, "POSITION:%2f,%2f", m_position.x,m_position.y);
    DrawFormatString(0, STRING_DISTANCE, COLOR, "VELOCITY:%2f,%2f", m_velocity.x, m_velocity.y);
    DrawFormatString(0, STRING_DISTANCE * 2, COLOR, "ANGLE   :%2f", m_nowAngle);
    DrawFormatString(0, STRING_DISTANCE * 3, COLOR, "SPEED   :%2f", m_moveSpeed);

}


void Ship::Move()
{

    CalcVelocity();
    m_position += m_velocity * m_moveSpeed;
}

void Ship::Input()
{
    //! レフトターン
    if (CheckHitKey(KEY_INPUT_D) == TRUE)
    {
        m_nowAngle += INCREASE_ANGLE_VALUE;
    }
    //! ライトターン
    if (CheckHitKey(KEY_INPUT_A) == TRUE)
    {
        m_nowAngle -= INCREASE_ANGLE_VALUE;
    }
}

void Ship::CalcVelocity()
{
    //! ここで角度をx,y方向の要素に分解している。
    m_velocity = vec2f(cos(m_nowAngle), sin(m_nowAngle));
}

void Ship::WarpPosition()
{
    if (m_position.x < 0)
    {
        m_position.x = Window::Width;
    }

    if (m_position.x > Window::Width)
    {
        m_position.x = 0;
    }

    if (m_position.y < 0)
    {
        m_position.y = Window::Height;
    }

    if(m_position.y > Window::Height)
    {
        m_position.y = 0;
    }
}
