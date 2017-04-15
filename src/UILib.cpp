#include "UILib.h"

void UILib::init(int *argc, char *argv[]) {
	//�ϐ�������
	f_exit = 0;

	//GLFW������
	if (glfwInit() == GL_FALSE) {
		f_exit = 1;
		return;
	}
	
	// �E�B���h�E����
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
	if (win.hwnd == NULL)
	{
		f_exit = 1;
		return;
	}
	
	//���������E�B���h�E��OpenGL�̏����Ώۂɂ���
	glfwMakeContextCurrent(GLhwnd);
	
	//�u�����h���[�h�L����
	glEnable(GL_BLEND); //�u�����h���[�h�L����
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //�A���t�@�u�����h�K�p

	//�E�B���h�E�ƃr���[�|�[�g�̓���
	resize();
	return;
}

void UILib::resize() {
	if (f_exit) return;
	//�E�B���h�E�S�̂��r���[�|�[�g�ɂ���
	glViewport(0, 0, win.size.x, win.size.y);

	//�ϊ��s��̏�����
	glLoadIdentity();

	//�X�N���[����̕\���̈���r���[�|�[�g�̑傫���ɔ�Ⴓ����
	glOrtho(0.0, (double)win.size.x, (double)win.size.y, 0.0, -1.0, 1.0);
}

void UILib::loop() {
	if (f_exit) return;
	//�E�B���h�E���J���Ă���ԌJ��Ԃ�
	while (glfwWindowShouldClose(GLhwnd) == GL_FALSE)
	{
		//�E�B���h�E����������
		glClear(GL_COLOR_BUFFER_BIT);

		//�E�B���h�E�̔w�i�F�ݒ�

		///debug///
		glClearColor(1.0, 1.0, 1.0, 1.0);
		///debug///

		//�`�揈��
		
		///debug///
		static int a = 50;
		a = (a + 1) % 100;
		glClear(GL_COLOR_BUFFER_BIT);
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
		///debug///

		//�J���[�o�b�t�@�����ւ���
		glfwSwapBuffers(GLhwnd);

		//�C�x���g����������܂őҋ@
		glfwWaitEvents();
	}
}

void UILib::exit() {
	//GLFW�̏I��
	glfwTerminate();
}