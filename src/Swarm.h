/*
 * Swarm.h
 *
 *  Created on: 11 Sept 2024
 *      Author: dave
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace dave_graphics {

class Swarm {
public:
	const static int N_PARTICLES = 3000;

private:
	Particle * m_pParticles; // instance variable pointer
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int timeElapsed);

	const Particle * const getParticles(){ return m_pParticles; };
};

} /* namespace dave_graphics */

#endif /* SWARM_H_ */
