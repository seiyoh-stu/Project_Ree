#pragma once
#include "../Utility/Vector2D.h"

// === �}�N����`�i�v���C���[�T�C�Y�E��ʏ��j === //
#define PLAYER_WIDTH         50
#define PLAYER_HEIGHT        50

#define SCREEN_WIDTH         640
#define SCREEN_HEIGHT        480
#define GROUND_Y             400

// === �}�N����`�i�����萔�j === //
#define GRAVITY              0.5f
#define MOVE_ACCEL           0.3f
#define MAX_SPEED            3.5f
#define FRICTION             0.2f
#define AIR_CONTROL          0.1f

#define JUMP_POWER_MIN       5.0f
#define JUMP_POWER_MAX       20.0f
#define CHARGE_SPEED         0.3f

// === �N���X��` === //
class Player
{
public:
    Player();          // �R���X�g���N�^
    ~Player();
    void Update();     // �X�V����
    void Draw() const; // �`�揈��

private:
    Vector2D position;     // �ʒu
    Vector2D velocity;     // ���x
    bool isJumping;        // �W�����v����
    bool isCharging;       // �W�����v���ߒ���
    float chargePower;     // ���݂̃W�����v�p���[
};
