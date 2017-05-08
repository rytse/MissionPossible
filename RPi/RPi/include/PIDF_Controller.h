#pragma once
#ifdef PIDF_CONTROLLER_H

class PIDF_Controller {
private:
	float k_p, k_i, k_d, k_f, prev_er, i_accum;

public:
	PIDF_Controller(void);
	float get_output(float, float, float);
}

#endif // PIDF_CONTROLLER_H 
