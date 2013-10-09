Originally a port to openFrameworks of my simple sphere camera class (https://github.com/stefang/SphereCamera) this is now an extension of the ofCamera class for openFrameworks. 

It was originally designed to control an inward pointing camera with zenith and azimuth angles but it now supports the standard linear cartesian model for both position and lookAt target. You've can move (moveTo) the camera and target in a cartesian space and you can use the spherical coordinate space to rotate around the current lookAt (sphereTo).

The movement is tweened so you set the target angles, positions and speed and it will make it's way there. You can use three methods:

### moveTo(ofVec3f(x,y,z), speed_in_ms);

Linear tweened movement from current position to passed in vector over the specified time.

### lookAtTo(ofVec3f(x,y,z), speed_in_ms);

Linear tweened movement from current target to passed in vector over the specified time.

### sphereTo(ofVec3f(r,a,z), speed_in_ms); Where r = radius, a = azimuth and z = zenith

Spherical tweened rotation round current camera target over the specified time.

The boolean 'handheld' set to true will add a small amount of 3d perlin noise to the target to simulate the slight wobble you get with hand held cameras.

The drawAxis() method called in draw() will draw an XYZ axis at 0,0,0 cartesian to give you a starting point so you can tell if it's working. 

The drawTarget() method called in draw() will draw an XYZ axis at the lookAt cartesian coordinates to give you a clue as to what the cam is looking at.

There's an example project to show you how I use it.

Requires ofxTween (https://github.com/arturoc/ofxTween)