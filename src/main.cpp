#include "UILib.h"

int main(int argc, char *argv[])
{
//�R���X�g���N�g
	//UI���C�u����
	UILib ui;

//�ϐ��錾

//���C�����[�`��
	ui.init();
	ui.loop();
	ui.exit();
	return 0;
}