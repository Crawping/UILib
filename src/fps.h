#pragma once
#pragma comment(lib, "winmm.lib")

#include <Windows.h>
#include <mmsystem.h>

class FPS{
private:
	//�ϐ�������
	DWORD bef; //�O�t���[���̎���
	DWORD gap; //�O�t���[���Ŏ擾���������Ƃ̍�
	double fps; //�ݒ肷��t���[�����[�g
	double r_fps; //���݂̃t���[�����[�g
	double speed; //60fps����Ƃ����A�j���[�V�����̃t���[���Ԃ̈ړ����x�̔{��

public:
	//�֐�������
	void SetFPS(double f); //�������֐�
	void Wait(); //�t���[�����[�g���ߗp�ҋ@�֐�
	double GetFPS(); //���݂̃t���[�����[�g�擾�֐�
	double GetSpeed(); //60fps����Ƃ����A�j���[�V�����̃t���[���Ԃ̈ړ����x�̔{���擾
};