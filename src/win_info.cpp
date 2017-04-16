#include "win_info.h"

MOUSE::MOUSE() {
	push.l = 0;
	push.r = 0;
	push.wheel = 0;
	b_push.l = 0;
	b_push.r = 0;
	b_push.wheel = 0;
	click.l = 0;
	click.r = 0;
	click.wheel = 0;
	mouse.x = 0;
	mouse.y = 0;
	b_mouse.x = 0;
	b_mouse.y = 0;
}

bool MOUSE::in(RECT area) {
	if (
		(area.left <= mouse.x) &&
		(area.top <= mouse.y) &&
		(area.right >= mouse.x) &&
		(area.bottom >= mouse.y)
		) {
		return 1;
	}
	return 0;
}

bool MOUSE::in(POINT pos, int size) {
	return in({
		pos.x - size / 2,
		pos.y - size / 2,
		pos.x + size / 2,
		pos.y + size / 2
	});
}

void MOUSE::hudg_click() {
	if ((push.l == 1) && (b_push.l == 0)) {
		click.l = 1;
	}
	else {
		click.l = 0;
	}
	if ((push.r == 1) && (b_push.r == 0)) {
		click.r = 1;
	}
	else {
		click.r = 0;
	}
	if ((push.wheel == 1) && (b_push.wheel == 0)) {
		click.wheel = 1;
	}
	else {
		click.wheel = 0;
	}
}

void MOUSE::loop() {
	hudg_click();
}

WINDOW_INFO::WINDOW_INFO() {
	size = { 640,480 }; //�E�B���h�E�T�C�Y
	b_size = { 640, 480 }; //�O�t���[���̃E�B���h�E�T�C�Y
	window = { 0, 0, 640, 480 }; //�E�B���h�E����E�����W(�f�X�N�g�b�v�)
	hwnd = nullptr; //OpenGL�̐����E�B���h�E�̃n���h��
	fps = 30.0; //�E�B���h�E�̕`��t���[�����[�g
	speed = 60.0 / fps; //60fps����Ƃ����A�j���[�V�����̃t���[���Ԃ̈ړ����x�̔{��
	title = "UILib";
}

void WINDOW_INFO::loop() {
	speed = 60.0 / fps;
	mouse.loop();
}