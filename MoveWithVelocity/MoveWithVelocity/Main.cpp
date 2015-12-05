#include "DxLib.h"

#include "GameManager.h"
#include "Ship.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //! �E�B���h�E�ŋN������悤�ɐݒ�
    ChangeWindowMode(TRUE);

    //! �摜�T�C�Y�A�F�͈̔͂��w��
    SetGraphMode(Window::Width, Window::Height, ColorBit);

    //�`���̐ݒ�(�o�b�N�o�b�t�@�Ɉ�x��������)
    SetDrawScreen(DX_SCREEN_BACK);

    if (DxLib_Init() == -1)		// �c�w���C�u��������������
    {
	    return -1;			// �G���[���N�����璼���ɏI��
    }


    Ship myShip;

    //! ���s����OS����̃��b�Z�[�W���󂯎��A�������́AEscape�L�[���������܂Ŏ��s����
    while (ProcessMessage() == false && CheckHitKey(KEY_INPUT_ESCAPE) == FALSE)
    {
        ClearDrawScreen();

        myShip.Update();
        myShip.Render();

        ScreenFlip();
    }


    DxLib_End();				// �c�w���C�u�����g�p�̏I������

    return 0;				// �\�t�g�̏I�� 
}
