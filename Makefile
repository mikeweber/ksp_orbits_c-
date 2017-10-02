all:
	g++ main.cpp model/celestial_body.cpp model/planet.cpp model/sun.cpp model/position.cpp model/time.cpp clamp_radians.cpp -o kerbin
