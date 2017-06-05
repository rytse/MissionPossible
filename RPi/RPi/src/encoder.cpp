#include "../include/encoder.h"
#include "../include/rotaryencoder.h"

Encoder::Encoder(short _p_i, short _p_q) {
	setupencoder(&encoder, _p_i, _p_q);
}

long Encoder::get_counts(void) {
	return encoder.value;
}

