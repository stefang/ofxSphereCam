A port to openFrameworks for my simple extension of the ofCamera class for openFrameworks to control an inward pointing camera with zenith and azimuth angles instead of cartesian coords as well as a standard tweened linear cartesian model.

The movement is tweened so you set the target angles or positions and speed, not the actual angles like and it will make it's way there. You can use three methods:

### moveTo(ofVec3f(x,y,z), speed_in_ms);

Linear tweened movement from current position to passed in vector over the specified time.

### lookAtTo(ofVec3f(x,y,z), speed_in_ms);

Linear tweened movement from current target to passed in vector over the specified time.

### sphereTo(ofVec3f(r,a,z), speed_in_ms); Where r = radius, a = azimuth and z = zenith

Spherical tweened rotation round current camera target over the specified time.

The boolean 'handheld' set to true will add a small amount of 3d perlin noise to the target to simulate the slight wobble you get with hand held cameras.

The axis() method called in the render loop will draw an XYZ axis at 0,0,0 cartesian to give you a starting point.

There's an example project to show you how it's working.

You can find the original Processing version here: https://github.com/stefang/SphereCamera