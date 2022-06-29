#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _calH_reg();
extern void _cdp_reg();
extern void _id_reg();
extern void _kad_reg();
extern void _kap_reg();
extern void _kdr_reg();
extern void _na3_reg();
extern void _nmdaSyn_reg();
extern void _spgen2_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," calH.mod");
fprintf(stderr," cdp.mod");
fprintf(stderr," id.mod");
fprintf(stderr," kad.mod");
fprintf(stderr," kap.mod");
fprintf(stderr," kdr.mod");
fprintf(stderr," na3.mod");
fprintf(stderr," nmdaSyn.mod");
fprintf(stderr," spgen2.mod");
fprintf(stderr, "\n");
    }
_calH_reg();
_cdp_reg();
_id_reg();
_kad_reg();
_kap_reg();
_kdr_reg();
_na3_reg();
_nmdaSyn_reg();
_spgen2_reg();
}
