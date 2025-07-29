#pragma once
#include "../Utility/Vector2D.h"

// === マクロ定義（プレイヤーサイズ・画面情報） === //
#define PLAYER_WIDTH         50
#define PLAYER_HEIGHT        50

#define SCREEN_WIDTH         640
#define SCREEN_HEIGHT        480
#define GROUND_Y             400

// === マクロ定義（物理定数） === //
#define GRAVITY              0.5f
#define MOVE_ACCEL           0.3f
#define MAX_SPEED            3.5f
#define FRICTION             0.2f
#define AIR_CONTROL          0.1f

#define JUMP_POWER_MIN       5.0f
#define JUMP_POWER_MAX       20.0f
#define CHARGE_SPEED         0.3f

// === クラス定義 === //
class Player
{
public:
    Player();          // コンストラクタ
    ~Player();
    void Update();     // 更新処理
    void Draw() const; // 描画処理

private:
    Vector2D position;     // 位置
    Vector2D velocity;     // 速度
    bool isJumping;        // ジャンプ中か
    bool isCharging;       // ジャンプ溜め中か
    float chargePower;     // 現在のジャンプパワー
};
