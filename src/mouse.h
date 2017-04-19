#pragma once

#include "define.h"
#include "get_event.h"

class MOUSE : public GET_EVENT {
public:
	struct Click {
		bool l; //l�N���b�N
		bool r; //r�N���b�N
		bool wheel; //�z�C�[��
	};
	//�ϐ��錾
	WindowPos mouse; //�}�E�X���W
	WindowPos b_mouse; //�O�t���[���̃}�E�X���W
	Click push; //������Ă��炸����1
	Click b_push; //�O�t���[����push
	Click click; //�����ꂽ�t���[���̂�1

	MOUSE();
	//�w��RECT���ɑ��݂��邩�ǂ���
	bool in(RECT area);
	bool in(POINT pos, int size);
	//�N���b�N����
	void hudg_click();
	//���[�v�֐�
	void loop();
};