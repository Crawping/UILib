/*
---�Q�l�T�C�g---
http://qiita.com/edo_m18/items/95483cabf50494f53bb5
http://marina.sys.wakayama-u.ac.jp/~tokoi/?date=20040914

---����---
�_���ŋ�؂�ꂽ�������ƂɃR�s�y�������̂�������Ă�
�ǂꂪ�K�v�łǂꂪ����Ȃ����̂Ȃ̂��킩��Ȃ��ׁA�Ƃ������Ђ����������肵�Ċm���߂�
*/

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "define.h"

class FBOtest {
public:
//�ϐ��錾
	/*---------------------------------------------------------------------------------------------------*/
	GLuint color_render_buffer;
	GLuint depth_render_buffer;
	GLuint frame_buffer;
	/*---------------------------------------------------------------------------------------------------*/
	GLuint texture;
	/*---------------------------------------------------------------------------------------------------*/
	WindowPoint size;
	/*---------------------------------------------------------------------------------------------------*/

//�֐��錾
	//������
	void init(WindowPoint set_size) {
		size = set_size;
		/*---------------------------------------------------------------------------------------------------*/
		// �J���[�o�b�t�@�p�����_�[�o�b�t�@�𐶐��iGenerate�j
		glGenRenderbuffers(1, &color_render_buffer);
		glBindRenderbuffer(GL_RENDERBUFFER, color_render_buffer);

		// �f�v�X�o�b�t�@�p�����_�[�o�b�t�@�𐶐�
		glGenRenderbuffers(1, &depth_render_buffer);
		glBindRenderbuffer(GL_RENDERBUFFER, depth_render_buffer);

		// �t���[���o�b�t�@�𐶐�
		glGenFramebuffers(1, &frame_buffer);
		glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer);

		// �t���[���o�b�t�@�Ƀ����_�[�o�b�t�@���A�J���[�o�b�t�@�Ƃ��ăA�^�b�`
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, color_render_buffer);

		// �t���[���o�b�t�@�Ƀ����_�[�o�b�t�@���A�f�v�X�o�b�t�@�Ƃ��ăA�^�b�`
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depth_render_buffer);
		/*---------------------------------------------------------------------------------------------------*/
		/*
		// �e�N�X�`���𐶐�
		glGenTextures(GL_TEXTURE_2D, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, size.x, size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		// �t���[���o�b�t�@�̃J���[�o�b�t�@�Ƃ��ăe�N�X�`����ݒ�
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
		*/
		/*---------------------------------------------------------------------------------------------------*/
		//�E�B���h�E�S�̂��r���[�|�[�g�ɂ���
		glViewport(0, 0, size.x, size.y);

		//�ϊ��s��̏�����
		glLoadIdentity();

		//�X�N���[����̕\���̈���r���[�|�[�g�̑傫���ɔ�Ⴓ����
		glOrtho(0.0, (double)size.x, (double)size.y, 0.0, -1.0, 1.0);
		/*---------------------------------------------------------------------------------------------------*/
		//�����_�[����E�B���h�E�ɐ؂�ւ�
		changeWindow();
		/*---------------------------------------------------------------------------------------------------*/
	}

	//�����_�[����t���[���o�b�t�@�ɐ؂�ւ�
	void changeFBO(){
		glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer);
	}

	//�����_�[����E�B���h�E�ɐ؂�ւ�
	void changeWindow(){
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	//�t���[���o�b�t�@��`��
	void DrawFBO() {
		/* �e�N�X�`���}�b�s���O�J�n */
		glEnable(GL_TEXTURE_2D);

		/* �P���̂S�p�`��`�� */
		glNormal3d(0.0, 0.0, 1.0);
		glBegin(GL_QUADS);
		glTexCoord2d(0.0, 1.0);
		glVertex3d(-1.0, -1.0, 0.0);
		glTexCoord2d(1.0, 1.0);
		glVertex3d(1.0, -1.0, 0.0);
		glTexCoord2d(1.0, 0.0);
		glVertex3d(1.0, 1.0, 0.0);
		glTexCoord2d(0.0, 0.0);
		glVertex3d(-1.0, 1.0, 0.0);
		glEnd();

		/* �e�N�X�`���}�b�s���O�I�� */
		glDisable(GL_TEXTURE_2D);
	}
};