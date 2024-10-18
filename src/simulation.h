#ifndef SIMULATION_H
#define SIMULATION_H

#include "solver.h"
#include "body.h"
#include "grid.h"


class Simulation {
public:
        Simulation(int) ;
        ~Simulation();

        void initialize(); // permet de reinitaliser simulation au cas ou on veut relancer avec de nouveaux params
        void run(); // lance la boucle de calcul
	void loop() ; 
        void finalize(); // nettoie les allocs
	void addBody(int);
	void addGrid(float, float, float, float) ; 
	void computeInterpolation() ; 

	void G2PVelocity();
	void P2GVelocity();


private:


        int totalSteps ;
	int currentSteps ;
        double currentTime ;
	double totalTime;
	

	Solver solver ; // description du solver (explicit, implicit, interpolations, explicit scheme, etc)
	
	Grid grid ; // data de la grille, CPU + GPU

//	Context context ;  // descripton du contexte (gravite, conditions limites, etc)
//			   // A noter que les CL peuvent changer d'une itération à l'autre
	Body body ; // description des proprietes des differents corps solides ou liquides
//			// (loi de comportement, volume occupé, valeurs physiques, ...)
//			// reste à savoir comment prendre en compte le multi solides
//			// Note : dans un premier temps, qu'un seul body sera géré
//	Bake bake ; // bake is the simulation data saved
//	Error error ; // gestion d'erreur dans le future
//	Hardware hardware ; // hardware information 
	

};      

#endif
