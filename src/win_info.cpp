#include "win_info.h"

WINDOW_INFO::WINDOW_INFO() {
	size = { 640,480 }; //�E�B���h�E�T�C�Y
	b_size = { 640, 480 }; //�O�t���[���̃E�B���h�E�T�C�Y
	hwnd = nullptr; //OpenGL�̐����E�B���h�E�̃n���h��
	fps.SetFPS(30.0);
	title = "UILib";
}

void WINDOW_INFO::set_GLhwnd(GLFWwindow *set_gl_hwnd) {
	gl_hwnd = set_gl_hwnd;
	hwnd = (HWND)gl_hwnd;
	mouse.SetGLhwnd(gl_hwnd);
}

void WINDOW_INFO::b_loop() {
	mouse.loop();
}

void WINDOW_INFO::a_loop() {
	fps.Wait();
}