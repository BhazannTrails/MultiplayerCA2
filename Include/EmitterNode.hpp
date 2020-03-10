#ifndef Include_EMITTERNODE_HPP
#define Include_EMITTERNODE_HPP

#include <Include/SceneNode.hpp>
#include <Include/Particle.hpp>


class ParticleNode;

class EmitterNode : public SceneNode
{
	public:
		explicit				EmitterNode(Particle::Type type);


	private:
		virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
		
		void					emitParticles(sf::Time dt);


	private:
		sf::Time				mAccumulatedTime;
		Particle::Type			mType;
		ParticleNode*			mParticleSystem;
};

#endif // Include_EMITTERNODE_HPP
