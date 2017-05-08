
/*! \brief Class that represents a PIDF velocity controller
*/

/*! \brief Construct a new PIDF velocity controller
	\param _k_p k_p
	\param _k_i k_i
	\param _k_d k_d
	\param _k_f k_f
*/
PIDF_Controller::PIDF_Controller(float _k_p, float _k_i, float _k_d, float _k_f) {
	k_p = _k_p;
	k_i = _k_i;
	k_d = _k_d;
	k_f = _k_f;

	i_accum = 0;
	prev_er = 0;
}

/*! \brief Update and get the output of the PIDF loop for the next sample point
	\param sp Setpoint to the PIDF controller
	\param pv Process variable (measured value) of the PIDF controller
	\param dt Change in time since the last sample point
	\return the updated control value
*/
float PIDF_Controller::get_output(float sp, float pv, float dt) {
	float er = sp - pv, out;
	i_accum += pv * dt;

	out = (k_f * sp) + (k_p * er) + (k_i * i_accum) + (k_d * (er - prev_er));

	prev_er = er;
	return out;
}