#pragma once
#include "IWeapon.h"
class DoubleWeapon : public IWeapon //������� �������
{
	void Attack(int MuzzleX, int MuzzleY, DIRECTION direction, IBulletFactory* bullet) override;
};

