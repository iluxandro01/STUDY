
#include "Bullet.h"

class ShieldBullet : public Bullet { //����, ��������� ��������� ��������� ������
private:
    int counterCollision = 0; //������� ������������
public:
    ShieldBullet(int InitX, int InitY, DIRECTION direction);

    ~ShieldBullet();

    HPEN SetColor() override;

    void virtual OnCollision(Entity* entity) override;
};

