/*
 * Particle.cpp
 *
 *  Created on: 11 Sept 2024
 *      Author: dave
 */
#include <stdlib.h>

#include "Particle.h"

namespace dave_graphics {

Particle::Particle() {

	m_x = ((2.0 * rand())/RAND_MAX) -1; // rand value from 0-1?
	m_y = ((2.0 * rand())/RAND_MAX) -1;

	m_xspeed = 0.005 * ((2.0 * rand())/RAND_MAX - 1);
	m_yspeed = 0.005 * ((2.0 * rand())/RAND_MAX - 1);
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update() {

	m_x += m_xspeed;
	m_y += m_yspeed;

}

} /* namespace dave_graphics */
