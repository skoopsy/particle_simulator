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
	m_speed = (0.0005 * rand())/RAND_MAX;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(int interval) {

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	// Move particles by amount proportional to time elapsed, will be similar for diff systems
	m_x += xspeed * interval;
	m_y += yspeed * interval;
}

} /* namespace dave_graphics */
