#pragma once

#include <Windows.h>
#include "Bonus.h"

class BulletBonus : public Bonus { //����� ��������� �� ������ - �������� ���� ������ ��� �������
public:
    BulletBonus(int InitX, int InitY);//�����������

    ~BulletBonus(); //����������

    HPEN SetColor() override; //�������� ����
};

