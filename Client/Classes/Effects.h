#pragma once
#include "cocostudio\CocoStudio.h"

namespace Effects
{
	void Moveable(Sprite *sprite);				//δ�ƶ��ĵ�λ
	void Moved(Sprite *sprite);					//���ƶ��ĵ�λ
	void Normal(Sprite *sprite);				//ͨ��״̬
	void Blink(Sprite *sprite, Point position);	//��˸��ĳ��
	void MoveTo(Sprite *sprite, Point position);
}