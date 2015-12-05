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
     * オリジナル定義の += オペレータ（演算子）
     * vec2f += vec2f を実装する
     */
    vec2f operator+=(const vec2f& _other)
    {
        return *this = vec2f(this->x + _other.x, this->y + _other.y);
    }

    /** 
     * オリジナル定義の * オペレータ（演算子）
     * vec2f * float を実装する
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
     * 移動処理
     */
    void Move();

    /**
     * 入力を処理する
     */
    void Input();

    /**
     * もっている角度情報を元に方向(vec2f型)を計算する
     */
    void CalcVelocity();

    /**
     * 画面外に出た時に反対側から出現させる
     */
    void WarpPosition();

    /**
     * 各種情報を表示する
     */
    void PrintLog();

    //! 座標
    vec2f m_position;

    //! 方向(正規化されている)
    vec2f m_velocity;

    //! 移動速度
    float m_moveSpeed;

    //! 方向転換速度
    const float INCREASE_ANGLE_VALUE;

    //! 今向いている方向
    float m_nowAngle;


};

