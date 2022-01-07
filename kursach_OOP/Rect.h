#pragma once

#include "Point.h"

class Rect : public Point { //����� ������������� ������������ ��� ����� ������� �������� ��������
                            //� ����� �������� ��������������� ��� ������ ������� ������������
protected:
    int Width;
    int Height;
public:
    Rect(int InitX, int InitY, int InitWidth, int InitHeight);

    Rect(int InitX, int InitY);
    
    ~Rect();

    int GetWidth();

    int GetHeight();

    virtual void Show() override;

    virtual void Hide() override;
};

