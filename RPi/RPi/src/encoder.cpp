#include "../include/encoder.h"
#include "../include/mmapGpio.h"

Encoder::Encoder(short _p_i, short _p_q) {
	gpio = new mmapGpio();
	c_i = c_q = p_i = p_q = 0;
}

void Encoder::update_iq(void) {
	p_i = c_i;
	p_q = c_q;
	c_i = gpio->readPin(p_i);
}