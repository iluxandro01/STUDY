#pragma once
#include "IWeapon.h"
class QueueWeapon : public IWeapon //�������� ��������
{
	void Attack(int MuzzleX, int MuzzleY, DIRECTION direction, IBulletFactory* bullet) override;
};

