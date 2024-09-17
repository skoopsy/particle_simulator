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
	init();
}

void Particle::init() {
	// Initialise particle parameters
	m_x = 0;
	m_y = 0;

	// Set random normalised direction and speed of particle
	m_direction = (2 * M_PI * rand())/RAND_MAX;
	m_speed = (0.04 * rand())/RAND_MAX;

	// make speed differences between particles greater
	m_speed *= m_speed; // squared
}
Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(int interval) {

	// make the particle curve
	m_direction += 0.0003 * interval;

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	// Move particles by amount proportional to time elapsed, will be similar for diff systems
	m_x += xspeed * interval;
	m_y += yspeed * interval;

	// Reinitialise a particle if it goes out of bounds
	//if(m_x < -1 || m_x > 1 || m_y < -1 || m_x > 1) {
	//	init();
	//}


	/*
	// Rnadomly reinitialise some particles
	if(rand() < RAND_MAX/100) {
		init();
	}
	*/
}

} /* namespace dave_graphics */
