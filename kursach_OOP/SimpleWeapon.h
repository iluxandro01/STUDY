#pragma once
#include "IWeapon.h"
class SimpleWeapon : public IWeapon //������� ��������
{
	void Attack(int MuzzleX, int MuzzleY, DIRECTION direction, IBulletFactory* bullet) override;
};

