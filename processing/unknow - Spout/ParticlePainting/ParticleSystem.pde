class ParticleSystem {
  ArrayList<Particle> particles = new ArrayList<Particle>();
  ArrayList<Particle> caches = new ArrayList<Particle>();
  PImage cacheImg;
  ParticleSystem() {
    
    
  }


  void morph(PImage img) {
    
    if (cacheImg!=img) {
      reSet(img);
     

      if (particles.size()>caches.size()) {
      
        while (particles.size()!=caches.size()) {
          for (int i  = caches.size(); i<particles.size(); i++) {
            particles.remove(i);
          }
        }
     
        for (int i  = 0; i<caches.size(); i++) {
     
          particles.get(i).targtLoc = caches.get(i).targtLoc.copy();
          particles.get(i).pixLoc = caches.get(i).pixLoc.copy();
          particles.get(i).col = caches.get(i).col;
        }
      } else {
        for (int i  = particles.size(); i<caches.size(); i++) {
          caches.get(i).loc = particles.get((int)random(particles.size())).loc.copy();
        }
        for (int i  = 0; i<particles.size(); i++) {
          caches.get(i).loc = particles.get(i).loc.copy();
        }
        particles.clear();
        particles = (ArrayList<Particle>)caches.clone();
      }
    }
  }

  void initial(PImage img) {
    reSet(img);
    
    particles.clear();
    particles = (ArrayList<Particle>)caches.clone();
    
  }

  void reSet(PImage img) {
    cacheImg = img;
    caches.clear();
   
   
    for (int i=0; i<img.width; i=i+3) {
      for (int j=0; j<img.height; j=j+3) {
        if (alpha(img.get(i, j))>0) {
          
          PVector loc = new PVector(i, j);
          PVector targetLoc = new PVector(i, j);
          PVector pixtLoc = new PVector(i, j);
          float rad = random(TWO_PI);
          PVector speed = new PVector(random(40.0, 500.0), random(40, 500));
          PVector acc = new PVector(cos(rad), sin(rad));

          Particle p = new Particle(loc, speed, acc, targetLoc, pixtLoc);
          p.col = img.get(i, j);
         
          caches.add(p);
        }
      }
    }
    for (int i = 0; i<caches.size(); i++) {
      caches.get(i).index = i;
    }
  }

  void render() {
    for (int i  = 0; i<particles.size(); i++) {
      particles.get(i).render();
    }
  }

  void update() {
    for (int i  = 0; i<particles.size(); i++) {
      particles.get(i).update();
    }
  }

  void toPix() {
    for (int i  = 0; i<particles.size(); i++) {
      particles.get(i).toPix();
    }
  }
  void flow() {
    for (int i  = 0; i<particles.size(); i++) {
      particles.get(i).flow();
    }
  }
}
