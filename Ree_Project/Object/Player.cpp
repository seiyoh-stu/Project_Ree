#include "Player.h"
#include "DxLib.h"
#include "../Utility/InputControl.h"

// === �R���X�g���N�^ === //
Player::Player()
{
    position = Vector2D(300.0f, GROUND_Y - PLAYER_HEIGHT);
    velocity = Vector2D(0.0f, 0.0f);
    isJumping = false;
    isCharging = false;
    chargePower = 0.0f;
}

Player::~Player()
{
}

// === �v���C���[�̍X�V���� === //
void Player::Update()
{
    InputControl* input = InputControl::GetInstance();

    float accel = isJumping ? AIR_CONTROL : MOVE_ACCEL;
    float friction = isJumping ? 0.0f : FRICTION;

    // --- ���E�ړ����� --- //
    if (input->GetKey(KEY_INPUT_A)) {
        velocity.x -= accel;
        if (velocity.x < -MAX_SPEED) velocity.x = -MAX_SPEED;
    }
    else if (input->GetKey(KEY_INPUT_D)) {
        velocity.x += accel;
        if (velocity.x > MAX_SPEED) velocity.x = MAX_SPEED;
    }
    else if (!isJumping) {
        if (velocity.x > 0.0f) {
            velocity.x -= friction;
            if (velocity.x < 0.0f) velocity.x = 0.0f;
        }
        else if (velocity.x < 0.0f) {
            velocity.x += friction;
            if (velocity.x > 0.0f) velocity.x = 0.0f;
        }
    }

    position.x += velocity.x;

    // --- ��ʒ[�����iX���j --- //
    if (position.x < 0) {
        position.x = 0;
        velocity.x = 0;
    }
    else if (position.x + PLAYER_WIDTH > SCREEN_WIDTH) {
        position.x = SCREEN_WIDTH - PLAYER_WIDTH;
        velocity.x = 0;
    }

    // --- �W�����v���� --- //
    if (!isJumping) {
        if (input->GetKeyDown(KEY_INPUT_SPACE)) {
            isCharging = true;
            chargePower = JUMP_POWER_MIN;
        }

        if (isCharging && input->GetKey(KEY_INPUT_SPACE)) {
            chargePower += CHARGE_SPEED;
            if (chargePower > JUMP_POWER_MAX) chargePower = JUMP_POWER_MAX;
        }

        if (isCharging && input->GetKeyUp(KEY_INPUT_SPACE)) {
            isCharging = false;
            isJumping = true;
            velocity.y = -chargePower;
        }
    }
    else {
        velocity.y += GRAVITY;
        position.y += velocity.y;

        if (position.y >= GROUND_Y - PLAYER_HEIGHT) {
            position.y = GROUND_Y - PLAYER_HEIGHT;
            velocity.y = 0.0f;
            isJumping = false;
        }
    }
}

// === �v���C���[�̕`�揈�� === //
void Player::Draw() const
{
    // �n�ʕ`��
    DrawBox(0, GROUND_Y, SCREEN_WIDTH, SCREEN_HEIGHT, GetColor(100, 255, 100), TRUE);

    // �v���C���[�`��i�Ԃ����j
    DrawBox(
        (int)position.x,
        (int)position.y,
        (int)(position.x + PLAYER_WIDTH),
        (int)(position.y + PLAYER_HEIGHT),
        GetColor(255, 0, 0), TRUE
    );

    // �W�����v���߃Q�[�W�\��
    if (isCharging) {
        int gaugeWidth = (int)((chargePower / JUMP_POWER_MAX) * 100);
        DrawBox(10, 10, 10 + gaugeWidth, 30, GetColor(255, 255, 0), TRUE);
    }
}
