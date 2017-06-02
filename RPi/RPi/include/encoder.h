#include "../include/mmapGpio.h"

#define STORED_SAMPLES 50

class Encoder {
public:
	Encoder(short _p_i, short _p_q);
	long get_counts(void);
	double get_vel(void);
	void zero_count(void);
	void update_iq(void);
private:
	mmapGpio *gpio;
	short p_i;	// in phase port
	short p_q;	// quadrate port
	bool c_i;
	bool c_q;
	bool p_i;
	bool p_q;
	long counts;
};