#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <Windows.h>
#include "define.h"
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
	HWND hwnd; //OpenGL�̐����E�B���h�E�̃n���h��
	GLFWwindow *gl_hwnd; //OpenGL�̐���GL�E�B���h�E�̃n���h��
	MOUSE mouse; //�}�E�X�C�x���g�ێ��N���X
	FPS fps; //�t���[�����[�g�Ǘ��N���X
	std::string title; //�E�B���h�E�^�C�g��

//�֐��錾
	//GL�E�B���h�E�n���h���ݒ�֐�
	void set_GLhwnd(GLFWwindow *set_gl_hwnd);

	//�`��O���[�v�֐�
	void b_loop();

	//�`��ニ�[�v�֐�
	void a_loop();
};