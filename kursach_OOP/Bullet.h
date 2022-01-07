#pragma once

#include "Point.h"
#include "Entity.h"
#include "Direction.h"
#include "IDyeable.h"

class Bullet : public Entity, public IDyeable { //����� ��� ����
protected:
    DIRECTION direction; //����������� �������� ����
public:
    Bullet(int InitX, int InitY, DIRECTION direction); //�����������

    ~Bullet(); //����������

    void virtual Show() override; 

    void virtual Update() override;

    void virtual OnCollision(Entity* entity) override;

    virtual HPEN SetColor() override;
};

