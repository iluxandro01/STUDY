#pragma once
#include "Direction.h"
#include "IBulletFactory.h"
class ShieldBulletFactory : public IBulletFactory //���� ������� �������� ��������� ��������� ������
{
	void CreateBullet(int InitX, int InitY, DIRECTION direction) override;
};

