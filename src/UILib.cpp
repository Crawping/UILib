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
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
	
	//�u�����h���[�h�L����
	glEnable(GL_BLEND);

	//�A���t�@�u�����h�K�p
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
		//glfwWaitEventsTimeout(0.7);
		glfwPollEvents();
		//glfwWaitEvents();
		//SetTimer(win.hwnd, NULL, 1000.0 / win.fps, NULL);

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
	glColor4d(0.0, 1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(0.0, 0.0);
	glVertex2d(100.0, 0.0);
	glVertex2d(100.0, 100.0);
	glVertex2d(0.0, 100.0);
	glEnd();
	glColor4d(1.0, 0.0, 0.0, 0.5);
	glBegin(GL_QUADS);
	glVertex2d(10.0 + (double)a, 10.0);
	glVertex2d(90.0 + (double)a, 10.0);
	glVertex2d(90.0 + (double)a, 90.0);
	glVertex2d(10.0 + (double)a, 90.0);
	glEnd();
	glFlush();
}

void UILib::exit() {
	if (f_exit) return;
	//GLFW�̏I��
	glfwTerminate();
}