#pragma once
#include "Bullet.h"
class IBulletFactory 
	//���������, ���� �������� ������� ������ �������� ���� � ��������� �����
	//����� �������, ��������� ��������� ����� ����� ����������� �������� �����
	//���� �� ����� �������, �.�. ������� �� ������ � ��������� ���� enum ���� ������
	//����� �������� ������� OCP � ����� ������ 
{
public:
	virtual void CreateBullet(int InitX, int InitY, DIRECTION direction) = 0;
};

 