#pragma once
#include "Entity.h"
#include "Point.h"
#include "IDyeable.h"
class Wall : public Entity, public IDyeable //����������� ����� �����
{
public:
	Wall(int InitX, int InitY, int Width, int Height);
	~Wall();
	virtual void Update() override = 0;
	virtual void OnCollision(Entity* entity) override;
	virtual void Show();
	virtual HPEN SetColor() = 0;
	virtual void Destroy() = 0;
};

