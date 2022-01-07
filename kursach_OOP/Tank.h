#include "Direction.h"
#include "Entity.h"
#include "IWeapon.h"
#include "IBulletFactory.h"
class Tank : public Entity
{
protected:
	int Scale;
private:
	int Step = 5; //��� ������������
	int CurrentX; //������� ����������
	int CurrentY;

	DIRECTION direction;

	IBulletFactory *bulletFactory;
	IWeapon *weapon;

	IBulletFactory *bulletLevels[4];
	IWeapon *weaponLevels[4];

	int currentBulletLevel = 0;
	int currentWeaponLevel= 0;

	int Clamp(int value, int min, int max); //�������� ������
public:
	Tank(int initX, int initY); //����������� 
	virtual void Show();
	virtual void Hide();
	void Shoot();
	void SetDirection(DIRECTION direction);
	void MoveTo(DIRECTION direction);
	virtual void Update() override;
	virtual void OnCollision(Entity* entity) override;

	void IncreaseWeapon();
	void IncreaseBullet();

	void SetWeapon(IWeapon* weapon);
	void SetBulletFactory(IBulletFactory* bulletFactory);
};
