#pragma once

//Entity/SceneNode category, used to dispatch commands
enum class CategoryID
{
	None = 0,
	SceneAirLayer = 1 << 0,
	PlayerAircraft = 1 << 1,
	AlliedAircraft = 1 << 2,
	Player2Aircraft,
	EnemyAircraft = 1 << 3,
	Pickup = 1 << 4,
	AlliedProjectile = 1 << 5,
	EnemyProjectile = 1 << 6,
	ParticleSystem = 1 << 7,
	SoundEffect = 1 << 8,
	Network = 1 << 9,

	Aircraft = PlayerAircraft | AlliedAircraft | EnemyAircraft | Player2Aircraft,
	Projectile = AlliedProjectile | EnemyProjectile,
};