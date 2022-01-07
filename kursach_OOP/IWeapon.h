#pragma once
#include "Bullet.h"
#include "IBulletFactory.h"
class IWeapon //��������� ��� ������
{
public:
	virtual void Attack(int MuzzleX, int MuzzleY, DIRECTION direction, IBulletFactory *bullet) = 0;
};

