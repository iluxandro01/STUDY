#pragma once

#include <Windows.h>
#include "Bonus.h"

class WeaponBonus : public Bonus { //����� ��������� ������ - ��� ������� �������� ������
public:
    WeaponBonus(int InitX, int InitY); //����������� 

    ~WeaponBonus(); //���������� 

    HPEN SetColor() override; //�������� ����
};

