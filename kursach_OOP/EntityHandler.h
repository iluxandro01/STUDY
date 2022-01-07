#pragma once

#include <map>
#include <stack>
#include "Entity.h"

class EntityHandler { 
    //����� � ������� ���� ��� ���������� ����������
private:
    static int entityID; //��������� ���� � ���������� id ������ ��������, ������������� ��� ������ ������
    static std::map<int, Entity*> entityMap; //��������� ����������� ��������
    static std::stack<int> toDelEntity; //��� ���������� ������ ��������

    static bool WasCollision(Entity* one, Entity* two); //�������� ������������

    static void DeleteEntities(); //�������� ���������� ���������

    static void Update();

    static void CheckCollision();

public:
    static int GetEntityID();

    static void AddEntity(int id, Entity* entity);

    static void RemoveEntity(int id);

    static void UpdateAll();

};


