#pragma once                  
#include <windows.h>
#include <conio.h>
#include <iostream>   
#include <thread>
#include <chrono>
using namespace std;        // ������������ ���� std

#include "Tank.h" 	//���������� �������
#include "GetConlWin.h"		//��������� �� ���������� ����
#include "Entity.h"
#include "EntityHandler.h"
#include "Bullet.h"
#include "Wall.h"
#include "WallGenerator.h"
#include "GameWorld.h"
//������ ��� ����������� ���� ������� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   � � � � � � � � � �   � � � � � � � � � �  �  � � � � � � � � �   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

//��������� ���������� ���������� ����������
//���������� ���������� ��������� �� ����� ���������� �� ����� �����
//, � ������� ���������

HDC hdc;	// ������� �������� ����������
			// �������� ���������� �� ���� ��� ���������,
			// ���������� �������� ���������� �� ����� ����������
			// � ���� ����������� ����������� ���������


/***********************************************************************/
/*               � � � � � � � �    � � � � � � � � �                  */
/***********************************************************************/
void WINAPI EntitySystem() {
	while (true)
	{
		EntityHandler::UpdateAll();
		Sleep(25);
	}	
}


void WINAPI GameLoop() {
	while (true)
	{
		GameWorld::Update();
		Sleep(500);
	}

}

void WINAPI WallGeneratorSystem() {
	while (true)
	{
		WallGenerator::Update();
		Sleep(25);
	}
}


int main()
{
	HWND hwnd = GetConcolWindow();
	system("color F0");

	if (hwnd != NULL)
	{
		//������� �������� ���������� ��� ����������� ����
		hdc = GetWindowDC(hwnd);
		//���� �������� ���������� - ����� ��������
		if (hdc != 0)
		{
			

			WallGenerator::SetDelay(4500); //�������� ����� ��������� ����� ������ ������
			WallGenerator::SetChance(3); //���� ��������� �������� ������ - ��� ���� ��� ����

			Tank tank(100, 200);  //������������� �������
			
			HANDLE CollThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GameLoop, 0, 0, 0);
			HANDLE SecondThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)WallGeneratorSystem, 0, 0, 0);
			HANDLE Thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)EntitySystem, 0, 0, 0);

			GameWorld::Start();
			while (1)	//����������� ���� ���������� ������
			{
				if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27
					break;

				//����������� �������� �������

				if (KEY_DOWN(VK_LEFT)) //������� �����  37
				{
					tank.MoveTo(LEFT);
					Sleep(5);
				}

				if (KEY_DOWN(VK_RIGHT)) //������� ������  39
				{
					tank.MoveTo(RIGHT);
					Sleep(5);
				}

				if (KEY_DOWN(VK_DOWN)) //������� ����  40
				{
					tank.MoveTo(DOWN);
					Sleep(5);
				}

				if (KEY_DOWN(VK_UP)) //������� �����  38
				{
					tank.MoveTo(UP);
					Sleep(5);
				}

				if (KEY_DOWN(VK_SPACE)) //������� �����  38
				{
					tank.Shoot();
					Sleep(500);
				}
			}
		}
	}
	return 0;
}

