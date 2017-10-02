all:
	g++ main.cpp models/celestial_body.cpp models/planet.cpp models/sun.cpp types/position.cpp types/time.cpp types/gravitational_parameter.cpp utils/clamp_radians.cpp -o main
