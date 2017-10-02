# KSP Orbits
A C++ version of my [JavaScript project](https://github.com/mikeweber/ksp_orbits) for calculating the positions
of the planets in KSP. Userful for planning missions, particularly long burns that may take hours or days.
The goal of this project is to calculate a constant acceleration trajectory from low Kerbin orbit to low Duna
orbit, then build a ship capable of the journey.

## Features
* Simulates the orbit of Kerbin (Duna and other moons to be added later)

## TODO
* [ ] Track a ship's location during various long-burn maneuvers
* [ ] Track fuel consumption, as this will change the acceleration of the ship over time
* [ ] Add a UI to display the planetary orbits, as well as the location of any missions
* [ ] Add a machine learning algorithm that can run on its own to refine any coarse flight plans
