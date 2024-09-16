/*
 * Swarm.cpp
 *
 *  Created on: 11 Sept 2024
 *      Author: dave
 */

#include "Swarm.h"

namespace dave_graphics {

Swarm::Swarm() {
	// Allocate and fill memory with loads of particles, with rand location
	m_pParticles = new Particle[N_PARTICLES];
}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

void Swarm::update() {
	for(int i=0; i<dave_graphics::Swarm::N_PARTICLES; i++) {
		m_pParticles[i].update();
		}

}

} /* namespace dave_graphics */
