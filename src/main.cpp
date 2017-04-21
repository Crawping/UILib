#include "UILib.h"

int main(int argc, char *argv[])
{
//�R���X�g���N�g
	//UI���C�u����
	UILib ui;

//�ϐ��錾
	Frame *test[100];

//���C�����[�`��
	ui.init();

	std::cout << "OpenGL ver. " << glGetString(GL_VERSION) << std::endl;

	//�t���[�����[�g�ݒ�
	ui.win.fps.SetFPS(30);

	//�t���[���ǉ�
	test[0] = ui.window.add<Frame>();
	test[1] = ui.window.add<Frame>();

	test[2] = ui.window.add<Frame>();
	test[3] = test[1]->add<Frame>();
	test[4] = test[1]->add<Frame>();

	test[5] = test[3]->add<Frame>();
	test[6] = test[3]->add<Frame>();
	test[7] = test[4]->add<Frame>();
	test[8] = test[4]->add<Frame>();

	test[1]->mode = 1;
	test[3]->mode = 1;
	test[4]->mode = 0;

	ui.window.orderliness();

	ui.loop();
	ui.exit();
	return 0;
}