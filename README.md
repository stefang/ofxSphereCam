A port to openFrameworks for my simple 3d camera class for openFrameworks to control an inward pointing camera with zenith and azimuth angles instead of cartesian coords.

The movement is damped so you set the target angles, not the actual angles like so...

sCam.azimuthTarget = ofRandom(-85,85);
sCam.zenithTarget = ofRandom(0,360);
sCam.sphereRadiusTarget = ofRandom(400)+500;
sCam.targTarget = ofRandom(1,10);

And it will make it's way there.  

To slow down or speed up the movement you use the setSpeed() method. Lower numbers are faster.

sCam.setSpeed(64);

The targTarget is the cartesian coords of what the camera is pointing at but only accepts one number and adjusts X, Y and Z all at once which is a bit crap but I never really ever used it to do anything but slightly adjust the view so never got round to making it a full coord.

The boolean 'handheld' set to true will add a small amount of 3d perlin noise to the target to simulate the slight wobble you get with hand held cameras.

The sCam.axis() method called in the render loop will draw an XYZ axis at 0,0,0 cartesian to give you a starting point.

You can find the original Processing version here: https://github.com/stefang/SphereCamera