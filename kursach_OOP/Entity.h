#pragma once

#include "Rect.h"

class Entity : public Rect { 
    //����� ��������, ������������ ��� ���������� ������ ���� �������:
    //Update - ����� ��� ���������� ��������� ������� ������ ���� �� �������� ������� �� ���
    //OnCollision - ������� ������������
private:
    int id; //���������� ����������� ��������
public:
    Entity(int initX, int initY); 
    Entity(int InitX, int InitY, int Width, int Height);
    //�����������, � ������� ������� id �� entityHandler
    //� ����������� � ������ �������� ������� ����� ���������
    virtual ~Entity();

    virtual void Update() = 0;

    virtual void OnCollision(Entity* entity) = 0;

    void Destroy(); //�������� ������� �� �������
};

