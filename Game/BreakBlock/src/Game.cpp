
# include "Game.hpp"

Game::Game(const InitData& init)
	: IScene(init)
{
	// �� (Scene::Width() / blockSize.x) �A�c 5 �̃u���b�N��z��ɒǉ�����
	for (auto p : step(Size((Scene::Width() / blockSize.x), 5)))
	{
		m_blocks << Rect(p.x * blockSize.x, 60 + p.y * blockSize.y, blockSize);
	}
}

void Game::update()
{
	// �p�h���𑀍�
	m_paddle = Rect(Arg::center(Cursor::Pos().x, 500), 60, 10);

	// �{�[�����ړ�
	m_ball.moveBy(m_ballVelocity * Scene::DeltaTime());

	// �u���b�N�����Ƀ`�F�b�N
	for (auto it = m_blocks.begin(); it != m_blocks.end(); ++it)
	{
		// �{�[���ƃu���b�N���������Ă�����
		if (it->intersects(m_ball))
		{
			// �{�[���̌����𔽓]����
			(it->bottom().intersects(m_ball) || it->top().intersects(m_ball) ? m_ballVelocity.y : m_ballVelocity.x) *= -1;

			// �u���b�N��z�񂩂�폜�i�C�e���[�^�������ɂȂ�̂Œ��Ӂj
			m_blocks.erase(it);

			// �X�R�A�����Z
			++m_score;

			// ����ȏ�`�F�b�N���Ȃ�  
			break;
		}
	}

	// �V��ɂԂ�������͂˕Ԃ�
	if (m_ball.y < 0 && m_ballVelocity.y < 0)
	{
		m_ballVelocity.y *= -1;
	}

	if (m_ball.y > Scene::Height())
	{
		changeScene(State::Title);
		getData().highScore = Max(getData().highScore, m_score);
	}

	// ���E�̕ǂɂԂ�������͂˕Ԃ�
	if ((m_ball.x < 0 && m_ballVelocity.x < 0) || (Scene::Width() < m_ball.x && m_ballVelocity.x > 0))
	{
		m_ballVelocity.x *= -1;
	}

	// �p�h���ɂ���������͂˕Ԃ�
	if (m_ballVelocity.y > 0 && m_paddle.intersects(m_ball))
	{
		// �p�h���̒��S����̋����ɉ����Ă͂˕Ԃ������ς���
		m_ballVelocity = Vec2((m_ball.x - m_paddle.center().x) * 10, -m_ballVelocity.y).setLength(speed);
	}
}

void Game::draw() const
{
	FontAsset(U"Score")(m_score).drawAt(Scene::Center().x, 30);

	// ���ׂẴu���b�N��`�悷��
	for (const auto& block : m_blocks)
	{
		block.stretched(-1).draw(HSV(block.y - 40));
	}

	// �{�[����`��
	m_ball.draw();

	// �p�h����`��
	m_paddle.draw();
}
