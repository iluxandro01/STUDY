#pragma once
#include "IBulletFactory.h"
class SimpleBulletFactory : public IBulletFactory //������� ����
{
	void CreateBullet(int InitX, int InitY, DIRECTION direction) override;
};

