#include "win_info.h"

WINDOW_INFO::WINDOW_INFO() {
	size = { 640,480 }; //�E�B���h�E�T�C�Y
	b_size = { 640, 480 }; //�O�t���[���̃E�B���h�E�T�C�Y
	hwnd = nullptr; //OpenGL�̐����E�B���h�E�̃n���h��
	fps.SetFPS(30.0); //�t���[�����[�g�ݒ�
	title = "UILib"; //�E�B���h�E�^�C�g���ݒ�
}

WINDOW_INFO *WINDOW_INFO::get_instance(GLFWwindow *const window) {
	return (WINDOW_INFO*)glfwGetWindowUserPointer(window);
}

void WINDOW_INFO::set_GLhwnd(GLFWwindow *set_gl_hwnd) {
	//���
	gl_hwnd = set_gl_hwnd;
	hwnd = (HWND)gl_hwnd;

	//�R�[���o�b�N�֐��p���N���X�̃|�C���^�w��
	glfwSetWindowUserPointer(gl_hwnd, this);

	//���
	mouse.SetGLhwnd(gl_hwnd);
}

void WINDOW_INFO::b_loop() {
	mouse.loop();
}

void WINDOW_INFO::a_loop() {
	fps.Wait();
}