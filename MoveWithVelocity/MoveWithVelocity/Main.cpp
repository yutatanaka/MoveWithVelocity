#include "DxLib.h"

#include "GameManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //! ウィンドウで起動するように設定
    ChangeWindowMode(TRUE);

    //! 画像サイズ、色の範囲を指定
    SetGraphMode(Window::Width, Window::Height, ColorBit);

    //描画先の設定(バックバッファに一度書き込む)
    SetDrawScreen(DX_SCREEN_BACK);

    if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
    {
	    return -1;			// エラーが起きたら直ちに終了
    }

    //! 実行時にOSからのメッセージを受け取る、もしくは、Escapeキーが押されるまで実行する
    while (ProcessMessage() == false && CheckHitKey(KEY_INPUT_ESCAPE) == FALSE)
    {

    }


    DxLib_End();				// ＤＸライブラリ使用の終了処理

    return 0;				// ソフトの終了 
}
