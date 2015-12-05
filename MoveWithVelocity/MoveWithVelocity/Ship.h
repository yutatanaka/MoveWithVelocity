#pragma once

struct vec2f
{
    vec2f()
    {
        x = y = 0;
    }

    vec2f(float _x,float _y)
    {
        x = _x;
        y = _y;
    };

    /**
     * �I���W�i����`�� += �I�y���[�^�i���Z�q�j
     * vec2f += vec2f ����������
     */
    vec2f operator+=(const vec2f& _other)
    {
        return *this = vec2f(this->x + _other.x, this->y + _other.y);
    }

    /** 
     * �I���W�i����`�� * �I�y���[�^�i���Z�q�j
     * vec2f * float ����������
     */ 
    vec2f operator*(const float& _other)
    {
        return vec2f(this->x * _other, this->y * _other);
    }


    float x;
    float y;
};

class Ship
{
public:
    Ship();
    ~Ship();

    void Update();

    void Render();

private:

    /** 
     * �ړ�����
     */
    void Move();

    /**
     * ���͂���������
     */
    void Input();

    /**
     * �����Ă���p�x�������ɕ���(vec2f�^)���v�Z����
     */
    void CalcVelocity();

    /**
     * ��ʊO�ɏo�����ɔ��Α�����o��������
     */
    void WarpPosition();

    /**
     * �e�����\������
     */
    void PrintLog();

    //! ���W
    vec2f m_position;

    //! ����(���K������Ă���)
    vec2f m_velocity;

    //! �ړ����x
    float m_moveSpeed;

    //! �����]�����x
    const float INCREASE_ANGLE_VALUE;

    //! �������Ă������
    float m_nowAngle;


};

