class particleRandom {
    ArrayList<Particle> particles;
    PVector origin;

    particleRandom() {
        origin = new PVector(width/2,50);
        particles = new ArrayList<Particle>();
    }

    void addParticle(){
	    particles.add(new SquareParticle(origin));
	}

    void run() {
	    for(int i = particles.size()-1; i>= 0; i--){
		    Particle p = particles.get(i);
		    p.run();
		    if (p.isDead()) {
			    particles.remove(i);
			}
		}
	}
}