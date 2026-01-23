---
layout: project
title: Online Interactive Gravity Simulator
front_image: /assets/img/projects/gravity-sim/gravity-sim-banner.jpg
thumbnail: /assets/img/projects/gravity-sim/gravity-sim-thumb.jpg
accent_color: "#3739b1"
tags:
  - Physics
  - Vue.js
  - Rust
  - WebGL
  - Web app
---

I developed an interactive gravity simulator using Vue.js and Rust. In this simulation you can add, modify, delete, and inspect objects with different masses. Among the available tools are a force vector visualization, graphing relative positions of objects, and displaying orbital characteristics. The application is mainly intended for educational purposes, not highly accurate simulation.

{% include center-button.html icon="link" text="Open web app" href="https://dirck.dev/gravity-sim" %}

Below I describe some of the sim's features. At the end you can find some implementation details. The source code for the project can be found on [GitHub](https://github.com/dirckvdende/gravity-sim).

## Features and examples

Below are some examples of things that can be observed using the sim. These examples are all taken from presets that can be loaded into the sim directly from the website, without the user having to add the objects manually. Some images have been edited slightly for clarification.

### Pluto and Charon

The largest moon of dwarf planet Pluto, Charon, is relatively large mass compared to Pluto. Charon's mass is 12% that of Pluto. By comparison: Our moon only has about 1.2% of the Earth's mass. This large mass has such a strong gravitational effect on Pluto that the center of gravity between the two objects is actually outside Pluto. The two objects orbit this center of gravity (called the "barycenter") together.

![Pluto and Charon](/assets/img/projects/gravity-sim/pluto-charon-light.jpg)

### Orbits of Venus and Earth

The orbital peroid of Venus is roughly 3/5 times that of Earth. This near-perfect integer ratio creates a nice picture when plotting the position of Earth relative to Venus. In this instance the integer ratio between the orbital periods is a coincidence. However, there are cases where these ratios cause more stable orbits, which is what the next example shows.

<img src="{{ '/assets/img/projects/gravity-sim/venus-earth.svg' | relative_url }}" alt="Position of Earth relative to Venus" style="width: 100%;">

*Note: You can download images likes this as SVGs from the object details menu, by clicking on an object*

### Orbits of Jupiter's moons

The orbits of three of Jupiter's moons &mdash; Ganymede, Europa, and Io &mdash; have a 1:2:4 ratio of orbital periods. This phenomenon is due to "orbital resonance". The moons have a gravitational effect on each other that causes them to stabalize into integer-ratio orbital periods. Like with Venus and the Earth, this creates a nice picture. The image below shows the position of Europa relative to Io.

You may notice that the path is not perfectly closed. This small difference is because the true ratio of the orbital periods changes of over time, but averages out to a ratio of 1:2 (also, the simulator is not perfectly accurate). You can read more about orbital resonance on [Wikipedia](https://en.wikipedia.org/wiki/Orbital_resonance).

<img src="{{ '/assets/img/projects/gravity-sim/io-europa.svg' | relative_url }}" alt="Position of Europa relative to Io" style="width: 100%;">


### 153 Hilda asteroid

The 153 Hilda asteroid is in a 3:2 orbital resonance with Jupiter. The orbit is quite elliptical (with an eccentricity of 0.11). In the picture below you can see the orbit's [perihelion](https://en.wikipedia.org/wiki/Apsis#Perihelion_and_aphelion) slowly rotate in the opposite direction of Jupiter's orbit.

This asteroid was the first discovered of a group of asteroids now known as Hildas, which all have a similar elliptical orbit and a 3:2 orbital resonance with Jupiter.

![The orbit of 153 Hilda](/assets/img/projects/gravity-sim/153-hilda.jpg)

### Earth's trojans

Objects with a 1:1 orbital resonance also exist. Perhaps the best example of this is Jupiter's trojans. These objects orbit the sun in almost the same orbital plane as Jupiter, close to the L4 and L5 [Lagrange points](https://en.wikipedia.org/wiki/Lagrange_point). These are points where the gravitational pull from Jupiter and the sun roughly cancel out. Due to this stability, many asteroids end up around these points.

The Earth has two discovered trojan asteroids (both are less than 2 km in diameter, so you can imagine they're hard to detect). These asteroids ([(614689) 2020 XL<sub>5</sub>](https://en.wikipedia.org/wiki/(614689)_2020_XL5) and [(706765) 2010 TK<sub>7</sub>](https://en.wikipedia.org/wiki/(706765)_2010_TK7)) orbit the L4 point of Earth. The image below shows the orbit of 2020 XL<sub>5</sub> relative to Earth's orbit (with Earth in the center). Over time the orbit oscillates around the L4 point.

<img src="{{ '/assets/img/projects/gravity-sim/2020-xl5.svg' | relative_url }}" alt="Position of 2020 XL5 relative to earth, rotated with Earth's orbit" style="width: 100%;">

### Saturn's moons

The interactions between objects are simulated in 3D. By default these coordinates are orthogonally projected along the z-axis when displayed in the browser. However, in some situations it can be more insightful to have a 3D view. This can be enabled in the menu at the bottom. Below is an example of the difference between the modes when viewing the moons of saturn.

![Comparison between 2D and 3D mode](/assets/img/projects/gravity-sim/saturns-moons-compare.jpg)

# Development

Most of the application is written in Vue.js and TypeScript (with Vite). I also used the [VueUse](https://vueuse.org/) package, which has some very nice utility composables.

The core of the simulator is written in Rust and compiled to WebAssembly, which has a significant performance advantage over using TypeScript. The state of the sim (i.e. object positions, velocities, etc.) is stored in TypeScript, and passed to the Rust code every frame. The simulator itself uses the [Runge-Kutta-Fehlberg method](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta%E2%80%93Fehlberg_method), with an upper bound on the error that is linearly dependent on the largest distance between any two objects.

The orbits are drawn using custom WebGL shaders. For every object a buffer of a fixed size is stored in memory. This buffer fills up from the front with the positions along the orbit. Once the buffer is full, the first positions are overwritten with new ones, creating a circular data structure.

The state of the sim can be saved to a JSON formatted file (with the `.grav` extension). The schema of this format is available [here](https://github.com/dirckvdende/gravity-sim/blob/main/src/assets/json/save.schema.json). A more detailed description of the format can be found [here](https://github.com/dirckvdende/gravity-sim/blob/main/docs/fileformat.md).

There is also a tool available for more easily importing data from NASA's [Horizons System](https://ssd.jpl.nasa.gov/horizons/app.html#/). This tool automatically rotates the objects around their barycenter to produce as little variation along the z-axis as possible. View the tool [on this page](https://dirck.dev/gravity-sim/horizons-data-import).