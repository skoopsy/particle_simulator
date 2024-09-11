/*
 * Particle.h
 *
 *  Created on: 11 Sept 2024
 *      Author: dave
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace dave_graphics {

struct Particle { // class and struct, in a struct the members are public by default, whereas in a class they are private

	// double so values can be changed gradually and rounded to nearest position.
	double m_x;
	double m_y;

public:
	Particle();
	virtual ~Particle();
};

} /* namespace dave_graphics */

#endif /* PARTICLE_H_ */
