#pragma once

#include "define.h"
#include <iostream>
#include <Windows.h>
#include "mouse.h"
#include "fps.h"

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
	//double fps; //�E�B���h�E�̕`��t���[�����[�g
	MOUSE mouse; //�}�E�X�C�x���g�ێ��N���X
	FPS fps;
	std::string title;

//�֐��錾
	//�`��O���[�v�֐�
	void b_loop();

	//�`��ニ�[�v�֐�
	void a_loop();
};