#define STORED_SAMPLES 50

class Encoder {
public:
	long get_counts();
	double get_vel();
	void zero_count();
private:
	long counts;

};