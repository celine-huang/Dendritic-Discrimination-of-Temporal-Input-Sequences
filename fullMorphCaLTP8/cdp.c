/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 static void _difusfunc(ldifusfunc2_t, _NrnThread*);
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__cdp
#define _nrn_initial _nrn_initial__cdp
#define nrn_cur _nrn_cur__cdp
#define _nrn_current _nrn_current__cdp
#define nrn_jacob _nrn_jacob__cdp
#define nrn_state _nrn_state__cdp
#define _net_receive _net_receive__cdp 
#define factors factors__cdp 
#define state state__cdp 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define ica_pmp _p[0]
#define ca (_p + 1)
#define CaBuffer (_p + 5)
#define Buffer (_p + 9)
#define CaIndicator (_p + 13)
#define Indicator (_p + 17)
#define pump _p[21]
#define pumpca _p[22]
#define ica _p[23]
#define ica_pmp_last _p[24]
#define parea _p[25]
#define cai _p[26]
#define cao _p[27]
#define Kd _p[28]
#define B0 _p[29]
#define Kd_ind _p[30]
#define B0_ind _p[31]
#define Dca (_p + 32)
#define DCaBuffer (_p + 36)
#define DBuffer (_p + 40)
#define DCaIndicator (_p + 44)
#define DIndicator (_p + 48)
#define Dpump _p[52]
#define Dpumpca _p[53]
#define _g _p[54]
#define _ion_cao	*_ppvar[0]._pval
#define _ion_cai	*_ppvar[1]._pval
#define _ion_ica	*_ppvar[2]._pval
#define _ion_dicadv	*_ppvar[3]._pval
#define _style_ca	*((int*)_ppvar[4]._pvoid)
#define diam	*_ppvar[5]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_factors(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_cdp", _hoc_setdata,
 "factors_cdp", _hoc_factors,
 0, 0
};
 /* declare global and static user variables */
#define Dogb Dogb_cdp
 double Dogb = 0.3;
#define DCa DCa_cdp
 double DCa = 0.6;
#define TotalIndicator TotalIndicator_cdp
 double TotalIndicator = 0.05;
#define TotalPump TotalPump_cdp
 double TotalPump = 1e-11;
#define TotalBuffer TotalBuffer_cdp
 double TotalBuffer = 0.003;
#define k4 k4_cdp
 double k4 = 0.005;
#define k3 k3_cdp
 double k3 = 1;
#define k2 k2_cdp
 double k2 = 0.005;
#define k1 k1_cdp
 double k1 = 1;
#define k2ind k2ind_cdp
 double k2ind = 0.14;
#define k1ind k1ind_cdp
 double k1ind = 430;
#define k2buf k2buf_cdp
 double k2buf = 0.1;
#define k1buf k1buf_cdp
 double k1buf = 100;
#define vrat vrat_cdp
 double vrat[4];
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "DCa_cdp", "um2/ms",
 "k1buf_cdp", "/mM-ms",
 "k2buf_cdp", "/ms",
 "TotalBuffer_cdp", "mM",
 "Dogb_cdp", "um2/ms",
 "k1ind_cdp", "/mM-ms",
 "k2ind_cdp", "/ms",
 "TotalIndicator_cdp", "mM",
 "k1_cdp", "/mM-ms",
 "k2_cdp", "/ms",
 "k3_cdp", "/ms",
 "k4_cdp", "/mM-ms",
 "TotalPump_cdp", "mol/cm2",
 "vrat_cdp", "1",
 "ca_cdp", "mM",
 "CaBuffer_cdp", "mM",
 "Buffer_cdp", "mM",
 "CaIndicator_cdp", "mM",
 "Indicator_cdp", "mM",
 "pump_cdp", "mol/cm2",
 "pumpca_cdp", "mol/cm2",
 "ica_pmp_cdp", "mA/cm2",
 0,0
};
 static double Buffer0 = 0;
 static double CaIndicator0 = 0;
 static double CaBuffer0 = 0;
 static double Indicator0 = 0;
 static double ca0 = 0;
 static double delta_t = 0.01;
 static double pumpca0 = 0;
 static double pump0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "DCa_cdp", &DCa_cdp,
 "k1buf_cdp", &k1buf_cdp,
 "k2buf_cdp", &k2buf_cdp,
 "TotalBuffer_cdp", &TotalBuffer_cdp,
 "Dogb_cdp", &Dogb_cdp,
 "k1ind_cdp", &k1ind_cdp,
 "k2ind_cdp", &k2ind_cdp,
 "TotalIndicator_cdp", &TotalIndicator_cdp,
 "k1_cdp", &k1_cdp,
 "k2_cdp", &k2_cdp,
 "k3_cdp", &k3_cdp,
 "k4_cdp", &k4_cdp,
 "TotalPump_cdp", &TotalPump_cdp,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 "vrat_cdp", vrat_cdp, 4,
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[6]._i
 static void _ode_synonym(int, double**, Datum**);
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"cdp",
 0,
 "ica_pmp_cdp",
 0,
 "ca_cdp[4]",
 "CaBuffer_cdp[4]",
 "Buffer_cdp[4]",
 "CaIndicator_cdp[4]",
 "Indicator_cdp[4]",
 "pump_cdp",
 "pumpca_cdp",
 0,
 0};
 static Symbol* _morphology_sym;
 static Symbol* _ca_sym;
 static int _type_ica;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 55, _prop);
 	/*initialize range parameters*/
 	_prop->param = _p;
 	_prop->param_size = 55;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 7, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_morphology_sym);
 	_ppvar[5]._pval = &prop_ion->param[0]; /* diam */
 prop_ion = need_memb(_ca_sym);
  _type_ica = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[1]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 	_ppvar[4]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "ca_cdp", 1e-07,
 "CaBuffer_cdp", 1e-05,
 "Buffer_cdp", 1e-05,
 "CaIndicator_cdp", 1e-05,
 "Indicator_cdp", 1e-05,
 "pump_cdp", 1e-15,
 "pumpca_cdp", 1e-15,
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _cdp_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("ca", -10000.);
 	_morphology_sym = hoc_lookup("morphology");
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 55, 7);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "#ca_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "cvodeieq");
  hoc_register_dparam_semantics(_mechtype, 5, "diam");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_ldifus1(_difusfunc);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 cdp C:/Users/Celine/Dropbox/Desktop/Celine/Lab/NEURON/fullMorphCaLTP8_five_synapses_extended/fullMorphCaLTP8/cdp.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 
#define FARADAY _nrnunit_FARADAY[_nrnunit_use_legacy_]
static double _nrnunit_FARADAY[2] = {0x9.a60645c954db8p+0, 9.64853}; /* 9.64853321233100125 */
 
#define PI _nrnunit_PI[_nrnunit_use_legacy_]
static double _nrnunit_PI[2] = {0xc.90fdaa22168cp-2, 3.14159}; /* 3.14159265358979312 */
 static double volo = 1e10;
 static double _zfactors_done ;
 static double _zfrat [ 4 ] ;
 static double _zdsq , _zdsqvol ;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int factors();
 extern double *_getelm();
 
#define _MATELM1(_row,_col)	*(_getelm(_row + 1, _col + 1))
 
#define _RHS1(_arg) _coef1[_arg + 1]
 static double *_coef1;
 
#define _linmat1  0
 static void* _sparseobj1;
 static void* _cvsparseobj1;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[22], _dlist1[22]; static double *_temp1;
 static int state();
 
static int  factors (  ) {
   double _lr , _ldr2 ;
 _lr = 1.0 / 2.0 ;
   _ldr2 = _lr / ( 4.0 - 1.0 ) / 2.0 ;
   vrat [ 0 ] = 0.0 ;
   _zfrat [ 0 ] = 2.0 * _lr ;
   {int  _li ;for ( _li = 0 ; _li <= 4 - 2 ; _li ++ ) {
     vrat [ _li ] = vrat [ _li ] + PI * ( _lr - _ldr2 / 2.0 ) * 2.0 * _ldr2 ;
     _lr = _lr - _ldr2 ;
     _zfrat [ _li + 1 ] = 2.0 * PI * _lr / ( 2.0 * _ldr2 ) ;
     _lr = _lr - _ldr2 ;
     vrat [ _li + 1 ] = PI * ( _lr + _ldr2 / 2.0 ) * 2.0 * _ldr2 ;
     } }
    return 0; }
 
static void _hoc_factors(void) {
  double _r;
   _r = 1.;
 factors (  );
 hoc_retpushx(_r);
}
 
static int state ()
 {_reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<22;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(21) *= ( ( 1e10 ) * parea) ;
_MATELM1(21, 21) *= ( ( 1e10 ) * parea);  
for (_i=0; _i < 4; _i++) {
  	_RHS1(_i + 1) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 1, _i + 1) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 4; _i++) {
  	_RHS1(_i + 5) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 5, _i + 5) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 4; _i++) {
  	_RHS1(_i + 9) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 9, _i + 9) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 4; _i++) {
  	_RHS1(_i + 13) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 13, _i + 13) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 4; _i++) {
  	_RHS1(_i + 17) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 17, _i + 17) *= ( diam * diam * vrat [ ((int) _i ) ]);  } }
 /* COMPARTMENT _li , diam * diam * vrat [ ((int) _i ) ] {
     ca CaBuffer Buffer CaIndicator Indicator }
   */
 /* COMPARTMENT ( 1e10 ) * parea {
     pump pumpca }
   */
 /* COMPARTMENT volo {
     }
   */
 /* LONGITUDINAL_DIFFUSION _li , DCa * diam * diam * vrat [ ((int) _i ) ] {
     ca }
   */
 /* LONGITUDINAL_DIFFUSION _li , Dogb * diam * diam * vrat [ ((int) _i ) ] {
     CaIndicator Indicator }
   */
 /* ~ ca [ 0 ] + pump <-> pumpca ( k1 * parea * ( 1e10 ) , k2 * parea * ( 1e10 ) )*/
 f_flux =  k1 * parea * ( 1e10 ) * pump * ca [ 0] ;
 b_flux =  k2 * parea * ( 1e10 ) * pumpca ;
 _RHS1( 21) -= (f_flux - b_flux);
 _RHS1( 17 +  0) -= (f_flux - b_flux);
 
 _term =  k1 * parea * ( 1e10 ) * ca [ 0] ;
 _MATELM1( 21 ,21)  += _term;
 _MATELM1( 17 +  0 ,21)  += _term;
 _term =  k1 * parea * ( 1e10 ) * pump ;
 _MATELM1( 21 ,17 +  0)  += _term;
 _MATELM1( 17 +  0 ,17 +  0)  += _term;
 _term =  k2 * parea * ( 1e10 ) ;
 _MATELM1( 21 ,0)  -= _term;
 _MATELM1( 17 +  0 ,0)  -= _term;
 /*REACTION*/
  /* ~ pumpca <-> pump + cao ( k3 * parea * ( 1e10 ) , k4 * parea * ( 1e10 ) )*/
 f_flux =  k3 * parea * ( 1e10 ) * pumpca ;
 b_flux =  k4 * parea * ( 1e10 ) * cao * pump ;
 _RHS1( 21) += (f_flux - b_flux);
 
 _term =  k3 * parea * ( 1e10 ) ;
 _MATELM1( 21 ,0)  -= _term;
 _term =  k4 * parea * ( 1e10 ) * cao ;
 _MATELM1( 21 ,21)  += _term;
 /*REACTION*/
   /* pump + pumpca = TotalPump * parea * ( 1e10 ) */
 _RHS1(0) =  TotalPump * parea * ( 1e10 );
 _MATELM1(0, 0) = 1 * ( ( 1e10 ) * parea);
 _RHS1(0) -= pumpca * ( ( 1e10 ) * parea) ;
 _MATELM1(0, 21) = 1 * ( ( 1e10 ) * parea);
 _RHS1(0) -= pump * ( ( 1e10 ) * parea) ;
 /*CONSERVATION*/
 ica_pmp = 2.0 * FARADAY * ( f_flux - b_flux ) / parea ;
   /* ~ ca [ 0 ] < < ( - ( ica - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 17 +  0) += (b_flux =   ( - ( ica - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 4 - 2 ; _li ++ ) {
     /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 f_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li] ;
 b_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li + 1] ;
 _RHS1( 17 +  _li) -= (f_flux - b_flux);
 _RHS1( 17 +  _li + 1) += (f_flux - b_flux);
 
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 17 +  _li ,17 +  _li)  += _term;
 _MATELM1( 17 +  _li + 1 ,17 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 17 +  _li ,17 +  _li + 1)  -= _term;
 _MATELM1( 17 +  _li + 1 ,17 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ Indicator [ _li ] <-> Indicator [ _li + 1 ] ( Dogb * _zfrat [ _li + 1 ] , Dogb * _zfrat [ _li + 1 ] )*/
 f_flux =  Dogb * _zfrat [ _li + 1 ] * Indicator [ _li] ;
 b_flux =  Dogb * _zfrat [ _li + 1 ] * Indicator [ _li + 1] ;
 _RHS1( 13 +  _li) -= (f_flux - b_flux);
 _RHS1( 13 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dogb * _zfrat [ _li + 1 ] ;
 _MATELM1( 13 +  _li ,13 +  _li)  += _term;
 _MATELM1( 13 +  _li + 1 ,13 +  _li)  -= _term;
 _term =  Dogb * _zfrat [ _li + 1 ] ;
 _MATELM1( 13 +  _li ,13 +  _li + 1)  -= _term;
 _MATELM1( 13 +  _li + 1 ,13 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CaIndicator [ _li ] <-> CaIndicator [ _li + 1 ] ( Dogb * _zfrat [ _li + 1 ] , Dogb * _zfrat [ _li + 1 ] )*/
 f_flux =  Dogb * _zfrat [ _li + 1 ] * CaIndicator [ _li] ;
 b_flux =  Dogb * _zfrat [ _li + 1 ] * CaIndicator [ _li + 1] ;
 _RHS1( 5 +  _li) -= (f_flux - b_flux);
 _RHS1( 5 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dogb * _zfrat [ _li + 1 ] ;
 _MATELM1( 5 +  _li ,5 +  _li)  += _term;
 _MATELM1( 5 +  _li + 1 ,5 +  _li)  -= _term;
 _term =  Dogb * _zfrat [ _li + 1 ] ;
 _MATELM1( 5 +  _li ,5 +  _li + 1)  -= _term;
 _MATELM1( 5 +  _li + 1 ,5 +  _li + 1)  += _term;
 /*REACTION*/
  } }
   _zdsq = diam * diam ;
   {int  _li ;for ( _li = 0 ; _li <= 4 - 1 ; _li ++ ) {
     _zdsqvol = _zdsq * vrat [ _li ] ;
     /* ~ ca [ _li ] + Buffer [ _li ] <-> CaBuffer [ _li ] ( k1buf * _zdsqvol , k2buf * _zdsqvol )*/
 f_flux =  k1buf * _zdsqvol * Buffer [ _li] * ca [ _li] ;
 b_flux =  k2buf * _zdsqvol * CaBuffer [ _li] ;
 _RHS1( 1 +  _li) -= (f_flux - b_flux);
 _RHS1( 17 +  _li) -= (f_flux - b_flux);
 _RHS1( 9 +  _li) += (f_flux - b_flux);
 
 _term =  k1buf * _zdsqvol * ca [ _li] ;
 _MATELM1( 1 +  _li ,1 +  _li)  += _term;
 _MATELM1( 17 +  _li ,1 +  _li)  += _term;
 _MATELM1( 9 +  _li ,1 +  _li)  -= _term;
 _term =  k1buf * _zdsqvol * Buffer [ _li] ;
 _MATELM1( 1 +  _li ,17 +  _li)  += _term;
 _MATELM1( 17 +  _li ,17 +  _li)  += _term;
 _MATELM1( 9 +  _li ,17 +  _li)  -= _term;
 _term =  k2buf * _zdsqvol ;
 _MATELM1( 1 +  _li ,9 +  _li)  -= _term;
 _MATELM1( 17 +  _li ,9 +  _li)  -= _term;
 _MATELM1( 9 +  _li ,9 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + Indicator [ _li ] <-> CaIndicator [ _li ] ( k1ind * _zdsqvol , k2ind * _zdsqvol )*/
 f_flux =  k1ind * _zdsqvol * Indicator [ _li] * ca [ _li] ;
 b_flux =  k2ind * _zdsqvol * CaIndicator [ _li] ;
 _RHS1( 13 +  _li) -= (f_flux - b_flux);
 _RHS1( 17 +  _li) -= (f_flux - b_flux);
 _RHS1( 5 +  _li) += (f_flux - b_flux);
 
 _term =  k1ind * _zdsqvol * ca [ _li] ;
 _MATELM1( 13 +  _li ,13 +  _li)  += _term;
 _MATELM1( 17 +  _li ,13 +  _li)  += _term;
 _MATELM1( 5 +  _li ,13 +  _li)  -= _term;
 _term =  k1ind * _zdsqvol * Indicator [ _li] ;
 _MATELM1( 13 +  _li ,17 +  _li)  += _term;
 _MATELM1( 17 +  _li ,17 +  _li)  += _term;
 _MATELM1( 5 +  _li ,17 +  _li)  -= _term;
 _term =  k2ind * _zdsqvol ;
 _MATELM1( 13 +  _li ,5 +  _li)  -= _term;
 _MATELM1( 17 +  _li ,5 +  _li)  -= _term;
 _MATELM1( 5 +  _li ,5 +  _li)  += _term;
 /*REACTION*/
  } }
   cai = ca [ 0 ] ;
     } return _reset;
 }
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<22;_i++) _p[_dlist1[_i]] = 0.0;}
 /* COMPARTMENT _li , diam * diam * vrat [ ((int) _i ) ] {
   ca CaBuffer Buffer CaIndicator Indicator }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
   pump pumpca }
 */
 /* COMPARTMENT volo {
   }
 */
 /* LONGITUDINAL_DIFFUSION _li , DCa * diam * diam * vrat [ ((int) _i ) ] {
   ca }
 */
 /* LONGITUDINAL_DIFFUSION _li , Dogb * diam * diam * vrat [ ((int) _i ) ] {
   CaIndicator Indicator }
 */
 /* ~ ca [ 0 ] + pump <-> pumpca ( k1 * parea * ( 1e10 ) , k2 * parea * ( 1e10 ) )*/
 f_flux =  k1 * parea * ( 1e10 ) * pump * ca [ 0] ;
 b_flux =  k2 * parea * ( 1e10 ) * pumpca ;
 Dpump -= (f_flux - b_flux);
 Dca [ 0] -= (f_flux - b_flux);
 Dpumpca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ pumpca <-> pump + cao ( k3 * parea * ( 1e10 ) , k4 * parea * ( 1e10 ) )*/
 f_flux =  k3 * parea * ( 1e10 ) * pumpca ;
 b_flux =  k4 * parea * ( 1e10 ) * cao * pump ;
 Dpumpca -= (f_flux - b_flux);
 Dpump += (f_flux - b_flux);
 
 /*REACTION*/
   /* pump + pumpca = TotalPump * parea * ( 1e10 ) */
 /*CONSERVATION*/
 ica_pmp = 2.0 * FARADAY * ( f_flux - b_flux ) / parea ;
 /* ~ ca [ 0 ] < < ( - ( ica - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 Dca [ 0] += (b_flux =   ( - ( ica - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 4 - 2 ; _li ++ ) {
   /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 f_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li] ;
 b_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li + 1] ;
 Dca [ _li] -= (f_flux - b_flux);
 Dca [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ Indicator [ _li ] <-> Indicator [ _li + 1 ] ( Dogb * _zfrat [ _li + 1 ] , Dogb * _zfrat [ _li + 1 ] )*/
 f_flux =  Dogb * _zfrat [ _li + 1 ] * Indicator [ _li] ;
 b_flux =  Dogb * _zfrat [ _li + 1 ] * Indicator [ _li + 1] ;
 DIndicator [ _li] -= (f_flux - b_flux);
 DIndicator [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ CaIndicator [ _li ] <-> CaIndicator [ _li + 1 ] ( Dogb * _zfrat [ _li + 1 ] , Dogb * _zfrat [ _li + 1 ] )*/
 f_flux =  Dogb * _zfrat [ _li + 1 ] * CaIndicator [ _li] ;
 b_flux =  Dogb * _zfrat [ _li + 1 ] * CaIndicator [ _li + 1] ;
 DCaIndicator [ _li] -= (f_flux - b_flux);
 DCaIndicator [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  } }
 _zdsq = diam * diam ;
 {int  _li ;for ( _li = 0 ; _li <= 4 - 1 ; _li ++ ) {
   _zdsqvol = _zdsq * vrat [ _li ] ;
   /* ~ ca [ _li ] + Buffer [ _li ] <-> CaBuffer [ _li ] ( k1buf * _zdsqvol , k2buf * _zdsqvol )*/
 f_flux =  k1buf * _zdsqvol * Buffer [ _li] * ca [ _li] ;
 b_flux =  k2buf * _zdsqvol * CaBuffer [ _li] ;
 DBuffer [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DCaBuffer [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca [ _li ] + Indicator [ _li ] <-> CaIndicator [ _li ] ( k1ind * _zdsqvol , k2ind * _zdsqvol )*/
 f_flux =  k1ind * _zdsqvol * Indicator [ _li] * ca [ _li] ;
 b_flux =  k2ind * _zdsqvol * CaIndicator [ _li] ;
 DIndicator [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DCaIndicator [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  } }
 cai = ca [ 0 ] ;
 _p[_dlist1[0]] /= ( ( 1e10 ) * parea);
 for (_i=0; _i < 4; _i++) { _p[_dlist1[_i + 1]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 4; _i++) { _p[_dlist1[_i + 5]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 4; _i++) { _p[_dlist1[_i + 9]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 4; _i++) { _p[_dlist1[_i + 13]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 4; _i++) { _p[_dlist1[_i + 17]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 _p[_dlist1[21]] /= ( ( 1e10 ) * parea);
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<22;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(0) *= ( ( 1e10 ) * parea) ;
_MATELM1(0, 0) *= ( ( 1e10 ) * parea); 
_RHS1(21) *= ( ( 1e10 ) * parea) ;
_MATELM1(21, 21) *= ( ( 1e10 ) * parea);  
for (_i=0; _i < 4; _i++) {
  	_RHS1(_i + 1) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 1, _i + 1) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 4; _i++) {
  	_RHS1(_i + 5) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 5, _i + 5) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 4; _i++) {
  	_RHS1(_i + 9) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 9, _i + 9) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 4; _i++) {
  	_RHS1(_i + 13) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 13, _i + 13) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 4; _i++) {
  	_RHS1(_i + 17) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 17, _i + 17) *= ( diam * diam * vrat [ ((int) _i ) ]);  } }
 /* COMPARTMENT _li , diam * diam * vrat [ ((int) _i ) ] {
 ca CaBuffer Buffer CaIndicator Indicator }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
 pump pumpca }
 */
 /* COMPARTMENT volo {
 }
 */
 /* LONGITUDINAL_DIFFUSION _li , DCa * diam * diam * vrat [ ((int) _i ) ] {
 ca }
 */
 /* LONGITUDINAL_DIFFUSION _li , Dogb * diam * diam * vrat [ ((int) _i ) ] {
 CaIndicator Indicator }
 */
 /* ~ ca [ 0 ] + pump <-> pumpca ( k1 * parea * ( 1e10 ) , k2 * parea * ( 1e10 ) )*/
 _term =  k1 * parea * ( 1e10 ) * ca [ 0] ;
 _MATELM1( 21 ,21)  += _term;
 _MATELM1( 17 +  0 ,21)  += _term;
 _MATELM1( 0 ,21)  -= _term;
 _term =  k1 * parea * ( 1e10 ) * pump ;
 _MATELM1( 21 ,17 +  0)  += _term;
 _MATELM1( 17 +  0 ,17 +  0)  += _term;
 _MATELM1( 0 ,17 +  0)  -= _term;
 _term =  k2 * parea * ( 1e10 ) ;
 _MATELM1( 21 ,0)  -= _term;
 _MATELM1( 17 +  0 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ pumpca <-> pump + cao ( k3 * parea * ( 1e10 ) , k4 * parea * ( 1e10 ) )*/
 _term =  k3 * parea * ( 1e10 ) ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 21 ,0)  -= _term;
 _term =  k4 * parea * ( 1e10 ) * cao ;
 _MATELM1( 0 ,21)  -= _term;
 _MATELM1( 21 ,21)  += _term;
 /* ~ ca [ 0 ] < < ( - ( ica - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) )*/
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 4 - 2 ; _li ++ ) {
 /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 17 +  _li ,17 +  _li)  += _term;
 _MATELM1( 17 +  _li + 1 ,17 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 17 +  _li ,17 +  _li + 1)  -= _term;
 _MATELM1( 17 +  _li + 1 ,17 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ Indicator [ _li ] <-> Indicator [ _li + 1 ] ( Dogb * _zfrat [ _li + 1 ] , Dogb * _zfrat [ _li + 1 ] )*/
 _term =  Dogb * _zfrat [ _li + 1 ] ;
 _MATELM1( 13 +  _li ,13 +  _li)  += _term;
 _MATELM1( 13 +  _li + 1 ,13 +  _li)  -= _term;
 _term =  Dogb * _zfrat [ _li + 1 ] ;
 _MATELM1( 13 +  _li ,13 +  _li + 1)  -= _term;
 _MATELM1( 13 +  _li + 1 ,13 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CaIndicator [ _li ] <-> CaIndicator [ _li + 1 ] ( Dogb * _zfrat [ _li + 1 ] , Dogb * _zfrat [ _li + 1 ] )*/
 _term =  Dogb * _zfrat [ _li + 1 ] ;
 _MATELM1( 5 +  _li ,5 +  _li)  += _term;
 _MATELM1( 5 +  _li + 1 ,5 +  _li)  -= _term;
 _term =  Dogb * _zfrat [ _li + 1 ] ;
 _MATELM1( 5 +  _li ,5 +  _li + 1)  -= _term;
 _MATELM1( 5 +  _li + 1 ,5 +  _li + 1)  += _term;
 /*REACTION*/
  } }
 _zdsq = diam * diam ;
 {int  _li ;for ( _li = 0 ; _li <= 4 - 1 ; _li ++ ) {
 _zdsqvol = _zdsq * vrat [ _li ] ;
 /* ~ ca [ _li ] + Buffer [ _li ] <-> CaBuffer [ _li ] ( k1buf * _zdsqvol , k2buf * _zdsqvol )*/
 _term =  k1buf * _zdsqvol * ca [ _li] ;
 _MATELM1( 1 +  _li ,1 +  _li)  += _term;
 _MATELM1( 17 +  _li ,1 +  _li)  += _term;
 _MATELM1( 9 +  _li ,1 +  _li)  -= _term;
 _term =  k1buf * _zdsqvol * Buffer [ _li] ;
 _MATELM1( 1 +  _li ,17 +  _li)  += _term;
 _MATELM1( 17 +  _li ,17 +  _li)  += _term;
 _MATELM1( 9 +  _li ,17 +  _li)  -= _term;
 _term =  k2buf * _zdsqvol ;
 _MATELM1( 1 +  _li ,9 +  _li)  -= _term;
 _MATELM1( 17 +  _li ,9 +  _li)  -= _term;
 _MATELM1( 9 +  _li ,9 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + Indicator [ _li ] <-> CaIndicator [ _li ] ( k1ind * _zdsqvol , k2ind * _zdsqvol )*/
 _term =  k1ind * _zdsqvol * ca [ _li] ;
 _MATELM1( 13 +  _li ,13 +  _li)  += _term;
 _MATELM1( 17 +  _li ,13 +  _li)  += _term;
 _MATELM1( 5 +  _li ,13 +  _li)  -= _term;
 _term =  k1ind * _zdsqvol * Indicator [ _li] ;
 _MATELM1( 13 +  _li ,17 +  _li)  += _term;
 _MATELM1( 17 +  _li ,17 +  _li)  += _term;
 _MATELM1( 5 +  _li ,17 +  _li)  -= _term;
 _term =  k2ind * _zdsqvol ;
 _MATELM1( 13 +  _li ,5 +  _li)  -= _term;
 _MATELM1( 17 +  _li ,5 +  _li)  -= _term;
 _MATELM1( 5 +  _li ,5 +  _li)  += _term;
 /*REACTION*/
  } }
 cai = ca [ 0 ] ;
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 22;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
     _ode_spec1 ();
  _ion_cai = cai;
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 22; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 static void _ode_synonym(int _cnt, double** _pp, Datum** _ppd) { 
 	int _i; 
	for (_i=0; _i < _cnt; ++_i) {_p = _pp[_i]; _ppvar = _ppd[_i];
 _ion_cai =  ca [ 0 ] ;
 }}
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse(&_cvsparseobj1, 22, _dlist1, _p, _ode_matsol1, &_coef1);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 2);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 3, 4);
 }
 static void* _difspace1;
extern double nrn_nernst_coef();
static double _difcoef1(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  diam * diam * vrat [ ((int) _i ) ] ;
 if (_i ==  0) {
  *_pdfcdc = nrn_nernst_coef(_type_ica)*( ( - ( _ion_dicadv  - ica_pmp_last ) * PI * diam / ( 2.0 * FARADAY ) ));
 }else{ *_pdfcdc=0.;}
   return DCa * diam * diam * vrat [ ((int) _i ) ] ;
}
 static void* _difspace2;
extern double nrn_nernst_coef();
static double _difcoef2(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  diam * diam * vrat [ ((int) _i ) ] ; *_pdfcdc=0.;
   return Dogb * diam * diam * vrat [ ((int) _i ) ] ;
}
 static void* _difspace3;
extern double nrn_nernst_coef();
static double _difcoef3(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  diam * diam * vrat [ ((int) _i ) ] ; *_pdfcdc=0.;
   return Dogb * diam * diam * vrat [ ((int) _i ) ] ;
}
 static void _difusfunc(ldifusfunc2_t _f, _NrnThread* _nt) {int _i;
  for (_i=0; _i < 4; ++_i) (*_f)(_mechtype, _difcoef1, &_difspace1, _i,  1, 32 , _nt);
  for (_i=0; _i < 4; ++_i) (*_f)(_mechtype, _difcoef2, &_difspace2, _i,  13, 44 , _nt);
  for (_i=0; _i < 4; ++_i) (*_f)(_mechtype, _difcoef3, &_difspace3, _i,  17, 48 , _nt);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
 for (_i=0; _i<4; _i++) Buffer[_i] = Buffer0;
 for (_i=0; _i<4; _i++) CaIndicator[_i] = CaIndicator0;
 for (_i=0; _i<4; _i++) CaBuffer[_i] = CaBuffer0;
 for (_i=0; _i<4; _i++) Indicator[_i] = Indicator0;
 for (_i=0; _i<4; _i++) ca[_i] = ca0;
  pumpca = pumpca0;
  pump = pump0;
 {
   if ( _zfactors_done  == 0.0 ) {
     _zfactors_done = 1.0 ;
     factors ( _threadargs_ ) ;
     }
   Kd = k1buf / k2buf ;
   B0 = TotalBuffer / ( 1.0 + Kd * cai ) ;
   Kd_ind = k1ind / k2ind ;
   B0_ind = TotalIndicator / ( 1.0 + Kd_ind * cai ) ;
   {int  _li ;for ( _li = 0 ; _li <= 4 - 1 ; _li ++ ) {
     ca [ _li ] = cai ;
     Buffer [ _li ] = B0 ;
     CaBuffer [ _li ] = TotalBuffer - B0 ;
     Indicator [ _li ] = B0_ind ;
     CaIndicator [ _li ] = TotalIndicator - B0_ind ;
     } }
   parea = PI * diam ;
   pump = TotalPump / ( 1.0 + ( cai * k1 / k2 ) ) ;
   pumpca = TotalPump - pump ;
   ica = 0.0 ;
   ica_pmp = 0.0 ;
   ica_pmp_last = 0.0 ;
   error = _ss_sparse(&_sparseobj1, 22, _slist1, _dlist1, _p, &t, dt, state,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 137 in file cdp.mod:\n\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 22; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 initmodel();
  _ion_cai = cai;
   nrn_wrote_conc(_ca_sym, (&(_ion_cai)) - 1, _style_ca);
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   ica_pmp_last = ica_pmp ;
   ica = ica_pmp ;
   }
 _current += ica;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
if (_nt->_vcv) { _ode_spec1(); }
 _g = _nrn_current(_v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_cai = cai;
  _ion_ica += ica ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 { error = sparse(&_sparseobj1, 22, _slist1, _dlist1, _p, &t, dt, state,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 96 in file cdp.mod:\n  SOLVE state METHOD sparse\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 22; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }  _ion_cai = cai;
 }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(pumpca) - _p;  _dlist1[0] = &(Dpumpca) - _p;
 for(_i=0;_i<4;_i++){_slist1[1+_i] = (Buffer + _i) - _p;  _dlist1[1+_i] = (DBuffer + _i) - _p;}
 for(_i=0;_i<4;_i++){_slist1[5+_i] = (CaIndicator + _i) - _p;  _dlist1[5+_i] = (DCaIndicator + _i) - _p;}
 for(_i=0;_i<4;_i++){_slist1[9+_i] = (CaBuffer + _i) - _p;  _dlist1[9+_i] = (DCaBuffer + _i) - _p;}
 for(_i=0;_i<4;_i++){_slist1[13+_i] = (Indicator + _i) - _p;  _dlist1[13+_i] = (DIndicator + _i) - _p;}
 for(_i=0;_i<4;_i++){_slist1[17+_i] = (ca + _i) - _p;  _dlist1[17+_i] = (Dca + _i) - _p;}
 _slist1[21] = &(pump) - _p;  _dlist1[21] = &(Dpump) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "cdp.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "\n"
  "Author: Ching-Lung Hsu (adapted from Hines and Carnevale, 2000)\n"
  "\n"
  "Calcium ion handling mechanisms with endogenous buffer, radial & longitudinal diffusion and pump\n"
  "A mobile calcium indicator OGB-1 is included\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "  SUFFIX cdp\n"
  "  USEION ca READ cao, cai, ica WRITE cai, ica\n"
  "  RANGE ica_pmp\n"
  "  GLOBAL vrat, TotalBuffer, TotalPump \n"
  "  GLOBAL TotalIndicator\n"
  "    : vrat must be GLOBAL--see INITIAL block\n"
  "    : however TotalBuffer and TotalPump may be RANGE\n"
  "}\n"
  "\n"
  "DEFINE Nannuli 4\n"
  "\n"
  "UNITS {\n"
  "  (mol)   = (1)\n"
  "  (molar) = (1/liter)\n"
  "  (mM)    = (millimolar)\n"
  "  (um)    = (micron)\n"
  "  (mA)    = (milliamp)\n"
  "  FARADAY = (faraday)  (10000 coulomb)\n"
  "  PI      = (pi)       (1)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "  DCa   = 0.6 (um2/ms)\n"
  "  \n"
  "  k1buf = 100 (/mM-ms) : Yamada et al. 1989 : forward rate        : Kd = 1/KD = k1/k2\n"
  "  k2buf = 0.1 (/ms) : backward rate\n"
  "  TotalBuffer = 0.003  (mM)\n"
  "  \n"
  "  Dogb = 0.3 (um2/ms) : smaller than DCa (Schmidt et al., 2003; Cornelisse et al., 2007)\n"
  "                      : An unexpected syntax error -\n"
  "                      : Don't use \"DIndicator\" as the parameter name for indicator's diffusion constant.\n"
  "                      : Because after cdp.mod is compiled into cdp.c, the C code will automatically use DIndicator\n"
  "                      : as an array whenever the state variable Indicator is involved in any REACTION\n"
  "                      : (including the radial diffusion and the calcium-indicator binding reaction);\n"
  "                      : otherwise, the following error message will show up in the shell:\n"
  "                      : \"cdp.c: In fuction _ode_specl:\n"
  "                      :  error: subscripted value is neither array nor pointer\"\n"
  "  k1ind = 430 (/mM-ms)      : Schmidt et al. (2003)\n"
  "  k2ind = 0.14 (/ms)        : Schmidt et al. (2003)\n"
  "  TotalIndicator = 0.05 (mM) : take 50% of the pipette concentration as the effective concentration at equilibrium \n"
  "\n"
  "  k1    = 1       (/mM-ms)\n"
  "  k2    = 0.005   (/ms)\n"
  "  k3    = 1       (/ms)\n"
  "  k4    = 0.005   (/mM-ms)\n"
  "  : to eliminate pump, set TotalPump to 0 in hoc\n"
  "  TotalPump = 1e-11 (mol/cm2)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "  diam      (um)\n"
  "  ica       (mA/cm2)\n"
  "  ica_pmp   (mA/cm2)\n"
  "  ica_pmp_last   (mA/cm2)\n"
  "  parea     (um)     : pump area per unit length\n"
  "  cai       (mM)\n"
  "  cao       (mM)\n"
  "  vrat[Nannuli]  (1) : dimensionless\n"
  "                     : numeric value of vrat[i] equals the volume \n"
  "                     : of annulus i of a 1um diameter cylinder\n"
  "                     : multiply by diam^2 to get volume per um length\n"
  "  Kd        (/mM)\n"
  "  B0        (mM)\n"
  "  Kd_ind    (/mM)    : Ching-Lung\n"
  "  B0_ind    (mM)     :\n"
  "}\n"
  "\n"
  "CONSTANT { volo = 1e10 (um2) }\n"
  "\n"
  "STATE {\n"
  "  : ca[0] is equivalent to cai\n"
  "  : ca[] are very small, so specify absolute tolerance\n"
  "  : let it be ~1.5 - 2 orders of magnitude smaller than baseline level\n"
  "  ca[Nannuli]       (mM) <1e-7>\n"
  "  CaBuffer[Nannuli] (mM) <1e-5>\n"
  "  Buffer[Nannuli]   (mM) <1e-5>\n"
  "\n"
  "  CaIndicator[Nannuli] (mM) <1e-5> :\n"
  "  Indicator[Nannuli]   (mM) <1e-5> :\n"
  "  \n"
  "  pump              (mol/cm2) <1e-15>\n"
  "  pumpca            (mol/cm2) <1e-15>\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "  SOLVE state METHOD sparse\n"
  "  ica_pmp_last = ica_pmp\n"
  "  ica = ica_pmp\n"
  "}\n"
  "\n"
  "LOCAL factors_done\n"
  "\n"
  "INITIAL {\n"
  "   if (factors_done == 0) {  : flag becomes 1 in the first segment\n"
  "      factors_done = 1       :   all subsequent segments will have\n"
  "      factors()              :   vrat = 0 unless vrat is GLOBAL\n"
  "   }\n"
  "\n"
  "  Kd = k1buf/k2buf\n"
  "  B0 = TotalBuffer/(1 + Kd*cai)\n"
  "  \n"
  "  Kd_ind = k1ind/k2ind                      \n"
  "  B0_ind = TotalIndicator/(1 + Kd_ind*cai)\n"
  "\n"
  "  FROM i=0 TO Nannuli-1 {\n"
  "    ca[i] = cai\n"
  "    Buffer[i] = B0\n"
  "    CaBuffer[i] = TotalBuffer - B0\n"
  "    Indicator[i] = B0_ind                       \n"
  "    CaIndicator[i] = TotalIndicator - B0_ind\n"
  "  }\n"
  "\n"
  "  parea = PI*diam\n"
  "\n"
  ": Manually computed initalization of pump\n"
  ": assumes that cai has been equal to cai0_ca_ion for a long time\n"
  "  pump = TotalPump/(1 + (cai*k1/k2))   : a better initialization\n"
  "  pumpca = TotalPump - pump            \n"
  ": If possible, instead of using formulas to calculate pump and pumpca,\n"
  ": let NEURON figure them out--just uncomment the following four statements\n"
  "  ica=0\n"
  "  ica_pmp = 0\n"
  "  ica_pmp_last = 0\n"
  "  SOLVE state STEADYSTATE sparse\n"
  ": This requires that pump and pumpca be constrained by the CONSERVE\n"
  ": statement in the STATE block.\n"
  "\n"
  "}\n"
  "COMMENT\n"
  "As suggested by Ted Carnevale,  \n"
  "the initialization style below may work best\n"
  "\n"
  "  pump = TotalPump/(1 + (cai*k1/k2))\n"
  "  pumpca = TotalPump - pump\n"
  "  SOLVE state STEADYSTATE sparse\n"
  "ENDCOMMENT\n"
  "\n"
  "\n"
  "LOCAL frat[Nannuli]  : scales the rate constants for model geometry\n"
  "PROCEDURE factors() {\n"
  "  LOCAL r, dr2\n"
  "  r = 1/2                : starts at edge (half diam)\n"
  "  dr2 = r/(Nannuli-1)/2  : full thickness of outermost annulus,\n"
  "                         : half thickness of all other annuli\n"
  "  vrat[0] = 0\n"
  "  frat[0] = 2*r\n"
  "  FROM i=0 TO Nannuli-2 {\n"
  "    vrat[i] = vrat[i] + PI*(r-dr2/2)*2*dr2  : interior half\n"
  "    r = r - dr2\n"
  "    frat[i+1] = 2*PI*r/(2*dr2)  : outer radius of annulus\n"
  "                                : div by distance between centers\n"
  "    r = r - dr2\n"
  "    vrat[i+1] = PI*(r+dr2/2)*2*dr2  : outer half of annulus\n"
  "  }\n"
  "}\n"
  "\n"
  "LOCAL dsq, dsqvol  : can't define local variable in KINETIC block\n"
  "                   :   or use in COMPARTMENT statement\n"
  "\n"
  "KINETIC state {\n"
  "  : COMPARTMENT i, diam*diam*vrat[i] {ca CaBuffer Buffer}\n"
  "  COMPARTMENT i, diam*diam*vrat[i] {ca CaBuffer Buffer CaIndicator Indicator}\n"
  "  COMPARTMENT (1e10)*parea {pump pumpca}\n"
  "  COMPARTMENT volo {cao}\n"
  "  \n"
  "  LONGITUDINAL_DIFFUSION i, DCa*diam*diam*vrat[i] {ca}        : Longitudinal diffusion of free Ca\n"
  "                                                              : Longitudinal diffusion of the Indicator,\n"
  "                                                              : assuming CaIndicator and Indicator have the same mobility\n"
  "  LONGITUDINAL_DIFFUSION i, Dogb*diam*diam*vrat[i] {CaIndicator Indicator}\n"
  "\n"
  "  :pump                                                       : a calcium sink\n"
  "  ~ ca[0] + pump <-> pumpca  (k1*parea*(1e10), k2*parea*(1e10)) : Nannuli = 0 is the outermost annulus\n"
  "  ~ pumpca <-> pump + cao    (k3*parea*(1e10), k4*parea*(1e10))\n"
  "  CONSERVE pump + pumpca = TotalPump * parea * (1e10)\n"
  "  ica_pmp = 2*FARADAY*(f_flux - b_flux)/parea\n"
  "\n"
  "  : all currents except pump\n"
  "  : ica is Ca efflux\n"
  "  ~ ca[0] << (-(ica - ica_pmp_last)*PI*diam/(2*FARADAY))       : calcium source\n"
  "  \n"
  "  FROM i=0 TO Nannuli-2 {                                      : Radial diffusion of free Ca\n"
  "    ~ ca[i] <-> ca[i+1]  (DCa*frat[i+1], DCa*frat[i+1])        \n"
  "    ~ Indicator[i] <-> Indicator[i+1]  (Dogb*frat[i+1], Dogb*frat[i+1])      : Radial diffusion of the Indicator,\n"
  "    ~ CaIndicator[i] <-> CaIndicator[i+1]  (Dogb*frat[i+1], Dogb*frat[i+1])  : assuming CaIndicator and Indicator have the same mobility\n"
  "  }\n"
  "  \n"
  "  dsq = diam*diam                                              : calcium buffering\n"
  "  FROM i=0 TO Nannuli-1 {\n"
  "    dsqvol = dsq*vrat[i]\n"
  "    ~ ca[i] + Buffer[i] <-> CaBuffer[i]  (k1buf*dsqvol, k2buf*dsqvol)\n"
  "    ~ ca[i] + Indicator[i] <-> CaIndicator[i]  (k1ind*dsqvol, k2ind*dsqvol)\n"
  "  }\n"
  "  \n"
  "  cai = ca[0]\n"
  "  \n"
  "}\n"
  ;
#endif
