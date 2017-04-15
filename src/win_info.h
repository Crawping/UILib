#pragma once

#include "define.h"
#include <iostream>
#include <Windows.h>

//�}�E�X�C�x���g�����N���X
//�}�E�X�C�x���g�����̕��@
/*
	GLUT�̃}�E�X�C�x���g�̎擾�֐��ꗗ
	http://d.hatena.ne.jp/nakamura001/20080924/1222268928
	�R�[���o�b�N�֐��̎������@
	http://d.hatena.ne.jp/prettysoft/20100909/1283529670
*/
class MOUSE {
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

//�E�B���h�E���ێ��ϐ�
class WINDOW_INFO {
public:
//�R���X�g���N�^
	WINDOW_INFO();

//�ϐ��錾
	POINT size; //�E�B���h�E�T�C�Y
	POINT b_size; //�O�t���[���̃E�B���h�E�T�C�Y
	RECT window; //�E�B���h�E����E�����W(�f�X�N�g�b�v�)
	HWND hwnd; //OpenGL�̐����E�B���h�E�̃n���h��
	double fps; //�E�B���h�E�̕`��t���[�����[�g
	double speed; //60fps����Ƃ����t���[���P�ʂ̃A�j���[�V�������x
	MOUSE mouse; //�}�E�X�C�x���g�ێ��N���X
	std::string title;

//�֐��錾
	//���[�v�֐�
	void loop();
};