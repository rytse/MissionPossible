#include "../include/rotaryencoder.h"

#define STORED_SAMPLES	50
#define DT				1

class Encoder {
public:
	Encoder(short _p_i, short _p_q);
	long get_counts(void);
	double get_vel(void);
	void zero_count(void);
	void update_iq(void);
private:
	struct encoder encoder;
	long counts;
};