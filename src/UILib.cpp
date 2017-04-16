#include "UILib.h"

void UILib::resize() {
	if (f_exit) return;
	//�E�B���h�E�S�̂��r���[�|�[�g�ɂ���
	glViewport(0, 0, win.size.x, win.size.y);

	//�ϊ��s��̏�����
	glLoadIdentity();

	//�X�N���[����̕\���̈���r���[�|�[�g�̑傫���ɔ�Ⴓ����
	glOrtho(0.0, (double)win.size.x, (double)win.size.y, 0.0, -1.0, 1.0);
}

bool UILib::error(bool val) {
	if (val) {
		exit();
		f_exit = 1;
	}
	return val;
}

void UILib::init() {
	//�ϐ�������
	f_exit = 0;

	//GLFW������
	if (error(glfwInit() == GL_FALSE)) return;

	//OpenGL Version 3.2 Core Profile ��I������
	//glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	//�E�B���h�E����
	GLhwnd = glfwCreateWindow
	(
		win.size.x,
		win.size.y,
		win.title.c_str(),
		NULL,
		NULL
	);
	
	//�E�B���h�E�n���h���擾
	win.hwnd = (HWND)GLhwnd;
	
	//�E�B���h�E����������Ă��Ȃ���ΏI��
	if (error(win.hwnd == NULL)) return;
	
	//���������E�B���h�E��OpenGL�̏����Ώۂɂ���
	glfwMakeContextCurrent(GLhwnd);

	//GLEW������
	glewExperimental = GL_TRUE;
	if (error(glewInit() != GLEW_OK)) return;
	
	//�f�t�H���g�Ńu�����h���[�h�L����
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //�A���t�@�u�����h�K�p

	//�f�t�H���g�ŃA���`�G�C���A�X�K��
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); //�_�̃A���`�G�C���A�X���x�ő剻
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); //���̃A���`�G�C���A�X���x�ő剻
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST); //�ʂ̃A���`�G�C���A�X���x�ő剻
	glEnable(GL_POINT_SMOOTH); //�_
	glEnable(GL_LINE_SMOOTH); //��
	glEnable(GL_POLYGON_SMOOTH); //��

	//�E�B���h�E�ƃr���[�|�[�g�̓���
	resize();

	//���������̃^�C�~���O��҂�
	glfwSwapInterval(1);

	return;
}

void UILib::loop() {
	if (f_exit) return;
	//�E�B���h�E���J���Ă���ԌJ��Ԃ�
	while (glfwWindowShouldClose(GLhwnd) == GL_FALSE)
	{
		//�C�x���g����������܂őҋ@
		glfwPollEvents();

		//��ʏ�����
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//�`��
		render();

		//�J���[�o�b�t�@�����ւ���
		glfwSwapBuffers(GLhwnd);
	}
}

void UILib::render() {
	static int a = 50;
	a = (a + 1) % 100;

	glLineWidth(10);
	glColor4d(0.0, 1.0, 1.0, 1.0);
	glDisable(GL_POLYGON_SMOOTH);
	glBegin(GL_QUADS);
	glVertex2d(0.0, 0.0);
	glVertex2d(100.0, 0.0);
	glVertex2d(100.0, 100.0);
	glVertex2d(0.0, 70.0);
	glEnd();
	glEnable(GL_POLYGON_SMOOTH);
	glColor4d(1.0, 0.0, 0.0, 0.5);
	glBegin(GL_LINES);
	glVertex2d(10.0 + (double)a, 10.0);
	glVertex2d(90.0 + (double)a, 10.0);
	glVertex2d(90.0 + (double)a, 90.0);
	glVertex2d(10.0 + (double)a, 20.0);
	glEnd();
	glFlush();

	return;
}

void UILib::exit() {
	if (f_exit) return;
	//GLFW�̏I��
	glfwTerminate();

	return;
}