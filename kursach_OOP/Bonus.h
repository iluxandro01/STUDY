#pragma once

#include "Entity.h"
#include "IDyeable.h"

class Bonus : public Entity, public IDyeable { //����������� ����� ������
public:
    Bonus(int InitX, int InitY); //�����������

    ~Bonus(); //����������

    virtual void Show() override; //����� ����� �� ������

    virtual void Update() override; //������������ �����

    virtual void OnCollision(Entity* entity) override; //������������

    virtual HPEN SetColor() override = 0;//��������� �����
};

