#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation {
public:
        Simulation(int) ;
        ~Simulation();

        void initialize(); // permet de reinitaliser simulation au cas ou on veut relancer avec de nouveaux params
        void run(); // lance la boucle de calcul
	void loop() ; 
        void finalize(); // nettoie les allocs

private:


        int totalSteps ;
	int currentSteps ;
        double currentTime ;
	double totalTime;
	

	Solver solver ; // description du solver (explicit, implicit, interpolations, explicit scheme, etc)
//	Context context ;  // descripton du contexte (gravite, conditions limites, etc)
//			   // A noter que les CL peuvent changer d'une itération à l'autre
//	Bodies bodies ; // description des proprietes des differents corps solides ou liquides
//			// (loi de comportement, volume occupé, valeurs physiques, ...)
//			// reste à savoir comment prendre en compte le multi solides
//	Bake bake ; // bake is the simulation data saved
//	Error error ; // gestion d'erreur dans le future
//	Hardware hardware ; // hardware information 
	

};      

#endif
