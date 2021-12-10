#include "Enemy.h"

Enemy::Enemy() 
{

}

Enemy::Enemy(const char* textureSheet, Transform transform, Player* currentPlayer) : Actor(textureSheet, transform)
{
	this->currentPlayer = currentPlayer;
	this->isRight = false;
}

Enemy::~Enemy() 
{

}

void Enemy::update()
{
	Actor::update();
	int fireballMaxSize = FireballList.size();
	for (int i = 0; i < fireballMaxSize; i++)
	{
		if ((abs(FireballList[i]->transform.x) - abs(this->transform.x)) >= AttackRange)
		{
			GameObject* ballToRem = FireballList[i];
			FireballList.erase(FireballList.begin() + i);
			SDL_DestroyTexture(ballToRem->texture);
			delete ballToRem;
			i--;
			fireballMaxSize--;
		}
		else if (FireballList[i]->handleCollision(currentPlayer))
		{
			GameObject* ballToRem = FireballList[i];
			FireballList.erase(FireballList.begin() + i);
			SDL_DestroyTexture(ballToRem->texture);
			delete ballToRem;
			i--;
			fireballMaxSize--;
			//Can change this to decrease health
			currentPlayer->isDead = true;
			currentPlayer->horizontal = 0;
			if (currentPlayer->isRight)
				currentPlayer->PlayAnimation(currentPlayer->anim_DeathRight, false);
			else
				currentPlayer->PlayAnimation(currentPlayer->anim_DeathLeft, false);
		}
	}
	for (GameObject* fBall : FireballList) {
		fBall->update();
	}

	if (this->isDead) 
	{
		if (this->isRight)
			this->PlayAnimation(this->anim_RightDeath, false);
		else
			this->PlayAnimation(this->anim_LeftDeath, false);
		return;
	}

	if (!currentPlayer->isDead && (DistanceToPlayer() <= AttackRange || this->isAttacking))
	{
		if ((currentAnimationPlaying.clips == anim_LeftAttack.clips || currentAnimationPlaying.clips == anim_RightAttack.clips))
		{
			int roundedFrame = (int)currentAnimFrame;
			//Spawn a fireball at end of animation
			if (roundedFrame == currentAnimationPlaying.animationLength - 2 && !hasFired)
			{
				hasFired = true;
				GameObject* Fireball;
				if (isRight) {
					Fireball = new GameObject("assets/EnemyAnims/anim_FireballRight/frame_0.png", Transform(this->transform.x + 5, this->transform.y, 0.75f));
					Fireball->isRight = true;
					Fireball->horizontal = 1;
					FireballList.push_back(Fireball);
					Fireball->update();
				}
				else {
					Fireball = new GameObject("assets/EnemyAnims/anim_FireballLeft/frame_0.png", Transform(this->transform.x - 5, this->transform.y, 0.75f));
					Fireball->isRight = false;
					Fireball->horizontal = -1;
					FireballList.push_back(Fireball);
					Fireball->update();
				}
			}
			if (roundedFrame == currentAnimationPlaying.animationLength - 2 && this->isAttacking) {
				this->isAttacking = false;
				this->hasFired = false;
				return;
			}
		}
		//Ensures enemy doesn't turn around until after they finish their attack.
		if (!this->isAttacking) {
			this->isAttacking = true;
			if (this->transform.x > currentPlayer->transform.x){
				this->isRight = false;
				this->PlayAnimation(anim_LeftAttack, true);
			}
			else {
				this->isRight = true;
				this->PlayAnimation(anim_RightAttack, true);
			}
			return;
		}

		if (this->isRight) {
			this->PlayAnimation(this->anim_RightAttack, true);
		}
		else {
			this->PlayAnimation(this->anim_LeftAttack, true);
		}
		return;
	}

	if (this->transform.x > currentPlayer->transform.x  && !isDead) 
	{
		this->PlayAnimation(this->anim_LeftIdle, true);
		this->isRight = false;
	}
	else if (!isDead)
	{
		this->PlayAnimation(this->anim_RightIdle, true);
		this->isRight = true;
	}
}

float Enemy::DistanceToPlayer()
{
	return abs(abs(this->transform.x) - abs(currentPlayer->transform.x));
}

void Enemy::LoadAllAnimations()
{
	anim_LeftIdle = Animation("assets/EnemyAnims/anim_IdleLeft", 6, 0.05f);
	anim_RightIdle = Animation("assets/EnemyAnims/anim_IdleRight", 6, 0.05f);
	anim_LeftAttack = Animation("assets/EnemyAnims/anim_AttackLeft", 8, 0.05f);
	anim_RightAttack = Animation("assets/EnemyAnims/anim_AttackRight", 8, 0.05f);
	anim_LeftDeath = Animation("assets/EnemyAnims/anim_DeathLeft", 7, 0.05f);
	anim_RightDeath = Animation("assets/EnemyAnims/anim_DeathRight", 7, 0.05f);
}

void Enemy::render() 
{
	std::cout << "Render" << std::endl;
	Actor::render();
	for(GameObject* fBall : this->FireballList)
	{
		fBall->render();
	}
}