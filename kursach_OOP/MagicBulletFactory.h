#pragma once
#include "Direction.h"
#include "IBulletFactory.h"
class MagicBulletFactory : public IBulletFactory //���������� ����
{
	void CreateBullet(int InitX, int InitY, DIRECTION direction) override;
};


