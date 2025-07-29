#include "DxLib.h"
#include "Object/Player.h"
#include "Utility/InputControl.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
    if (DxLib_Init() == -1) return -1;
    SetDrawScreen(DX_SCREEN_BACK);

    Player player;

    while (ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        InputControl::GetInstance()->Update();

        player.Update();
        player.Draw();

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}
