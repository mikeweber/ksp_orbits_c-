all:
	g++ main.cpp models/celestial_body.cpp models/planet.cpp models/sun.cpp models/ship.cpp types/position.cpp types/angle.cpp types/prograde.cpp types/heading.cpp types/velocity.cpp types/time.cpp types/gravitational_parameter.cpp utils/clamp_radians.cpp -o main
