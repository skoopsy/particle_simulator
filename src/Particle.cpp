/*
 * Particle.cpp
 *
 *  Created on: 11 Sept 2024
 *      Author: dave
 */
#include <stdlib.h>
#include <math.h>

#include "Particle.h"

namespace dave_graphics {

Particle::Particle(): m_x(0), m_y(0) {

	m_direction = (2 * M_PI * rand())/RAND_MAX;
	m_speed = (0.005 * rand())/RAND_MAX;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update() {

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed;
	m_y += yspeed;
}

} /* namespace dave_graphics */
