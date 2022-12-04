
class Particle {
 
  PVector loc, targtLoc, pixLoc, speed;
  color col;
  float rad;
  float maxVel = 1.6;
  int index;


  Particle(PVector _loc, PVector _speed, PVector _acc, 
    PVector _tLoc, PVector _pixLoc) {
    loc = _loc;
    speed = _speed;

    targtLoc = _tLoc;
    pixLoc = _pixLoc;
  }

  Particle() {
    loc = new PVector(random(width), random(height));

    speed = new PVector(0, 0);
    targtLoc = new PVector(0, 0);
    pixLoc = new PVector(0, 0);
  }
  void update() {
    move();
    checkEdges();
  }

  void toPix() {
    targtLoc.lerp(pixLoc, 0.01);
  }


  void move() {
    if (loc.dist(targtLoc)<1) {
      loc = targtLoc.copy();
    } else {
      loc.lerp(targtLoc, 0.1);
    }
  }

  void flow() {

    float deg = 180*noise(
      loc.x/600.0, 
      loc.y/600.0, 
      millis()/100000.0);

    float noiseStrength = 106.3;
   
    rad=radians(deg*noiseStrength);
 
    speed.set(cos(rad)*20.0,sin(rad)*20.0);


    if (speed.magSq()>(maxVel)) {
      speed.normalize();
     
    }
    targtLoc.add(speed);
  }




  void checkEdges() {
    if (loc.x<0 || loc.x>width || loc.y<0 || loc.y>height) {    
      loc.x = random(width);
      loc.y = random(height);
      targtLoc = loc.copy();
    }
  }

  void render() {
    fill(col, 100);
    ellipse(loc.x, loc.y, 6, 6);
  }
}
