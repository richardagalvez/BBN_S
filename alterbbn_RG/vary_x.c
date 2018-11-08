#include "src/include.h"

/*--------------------------------------------------------*/
/* Calculation of the observables in the Standard Model   */
/* with added reactions for the X particle -- RG 2017     */
/*--------------------------------------------------------*/

int main(int argc, char *argv[])
{ 
	// The program takes in two arguments to execute, A_x and Q_x, in that order.

	struct relicparam paramrelic;
	double ratioH[NNUC+1];
	double H2_H,He3_H,Yp,Li7_H,Li6_H,Be7_H;
	double AsBe7, AsLi7, AsHe4, AsHe3, AsH3, AsD, AsLi6;
	int print_abundance_evo_mode;

	sscanf(argv[1],"%lf",&AsBe7);
	sscanf(argv[2],"%lf",&AsLi7);
	sscanf(argv[3],"%lf",&AsHe4);
	sscanf(argv[4],"%lf",&AsHe3);
	sscanf(argv[5],"%lf",&AsH3);
	sscanf(argv[6],"%lf",&AsD);
	sscanf(argv[7],"%lf",&AsLi6);
	sscanf(argv[8],"%d", &print_abundance_evo_mode);

	Init_cosmomodel(&paramrelic, AsBe7, AsLi7, AsHe4, AsHe3, AsH3, AsD, AsLi6);
	nucl(0,paramrelic,ratioH,print_abundance_evo_mode);

	if (print_abundance_evo_mode == 0) 
	{
		H2_H=ratioH[3];Yp=ratioH[6];Li7_H=ratioH[8];Be7_H=ratioH[9];He3_H=ratioH[5];Li6_H=ratioH[7];
		//printf("Yp\t\t H2\t\t He3\t\t Li7\t\t Li6\t\t Be7\n");
		printf("%.5e\t %.5e\t %.5e\t %.5e\t %.5e\t %.5e\t %.5e\n",AsBe7,Yp,H2_H,He3_H,Li7_H,Li6_H,Be7_H);
	} 
	
	return 1;
}
