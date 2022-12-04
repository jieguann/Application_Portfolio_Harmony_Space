
ParticleSystem ps;

PImage img1, img2,img3;

int time;

void setup() {
  size(1080, 1080, P3D);
  img1 = loadImage("01.png");
  img2 = loadImage("02.png");
  img3 = loadImage("03.png");

  

  ps = new ParticleSystem();

  ps.initial(img1);
  
  time=0;
}

void draw() {
  
  
  fill(0);
  noStroke();
  rect(0, 0, width*2, height*2);
  
  
  
  fill(255, 155);  



 
 
  ps.flow();
  

  ps.update();
  ps.render();
  
 
 time();
   
  
}

void time() {
  time++;
  
  if(time==201){time=0;};

  if (time==100) {
    ps.morph(img1);
  
  }
  if (time==150) {
    ps.morph(img2);
 
  }
  
    if (time==200) {
    ps.morph(img3);
 
  }
   println(time);
}
