#pragma once
#include "IWeapon.h"
class TripleWeapon: public IWeapon //������� �������
{
	void Attack(int MuzzleX, int MuzzleY, DIRECTION direction, IBulletFactory* bullet) override;
};

