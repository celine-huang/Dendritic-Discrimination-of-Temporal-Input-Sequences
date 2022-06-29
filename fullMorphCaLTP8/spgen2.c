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
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__SpGen2
#define _nrn_initial _nrn_initial__SpGen2
#define nrn_cur _nrn_cur__SpGen2
#define _nrn_current _nrn_current__SpGen2
#define nrn_jacob _nrn_jacob__SpGen2
#define nrn_state _nrn_state__SpGen2
#define _net_receive _net_receive__SpGen2 
#define event_time event_time__SpGen2 
#define seed seed__SpGen2 
 
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
#define t01 _p[0]
#define t02 _p[1]
#define fast_freq _p[2]
#define slow_freq _p[3]
#define APinburst _p[4]
#define startbursting _p[5]
#define endbursting _p[6]
#define noise _p[7]
#define y _p[8]
#define fast_invl _p[9]
#define slow_invl _p[10]
#define burst _p[11]
#define event _p[12]
#define burst_off _p[13]
#define burst_on _p[14]
#define on _p[15]
#define _tsav _p[16]
#define _nd_area  *_ppvar[0]._pval
 
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
 static double _hoc_event_time();
 static double _hoc_interval();
 static double _hoc_seed();
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

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "event_time", _hoc_event_time,
 "interval", _hoc_interval,
 "seed", _hoc_seed,
 0, 0
};
#define interval interval_SpGen2
 extern double interval( double );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "t01", "ms",
 "t02", "ms",
 "fast_freq", "/s",
 "slow_freq", "/s",
 "startbursting", "ms",
 "endbursting", "ms",
 0,0
};
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"SpGen2",
 "t01",
 "t02",
 "fast_freq",
 "slow_freq",
 "APinburst",
 "startbursting",
 "endbursting",
 "noise",
 0,
 "y",
 0,
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 17, _prop);
 	/*initialize range parameters*/
 	t01 = 20;
 	t02 = 420000;
 	fast_freq = 100;
 	slow_freq = 1e-08;
 	APinburst = 4;
 	startbursting = 30;
 	endbursting = 3200;
 	noise = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 17;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 
#define _tqitem &(_ppvar[2]._pvoid)
 static void _net_receive(Point_process*, double*, double);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _spgen2_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,(void*)0, (void*)0, (void*)0, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 17, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "netsend");
 add_nrn_has_net_event(_mechtype);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_size[_mechtype] = 1;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 SpGen2 C:/Users/Celine/Dropbox/Desktop/Celine/Lab/NEURON/fullMorphCaLTP8_sample_code/fullMorphCaLTP8/spgen2.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Modified SpikeGenerator of M. Hines";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int event_time();
static int seed(double);
 
static int  seed (  double _lx ) {
   set_seed ( _lx ) ;
    return 0; }
 
static double _hoc_seed(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 seed (  *getarg(1) );
 return(_r);
}
 
double interval (  double _lmean ) {
   double _linterval;
 if ( _lmean <= 0. ) {
     _lmean = .01 ;
     }
   if ( noise  == 0.0 ) {
     _linterval = _lmean ;
     }
   else {
     _linterval = ( 1. - noise ) * _lmean + noise * _lmean * exprand ( 1.0 ) ;
     }
   
return _linterval;
 }
 
static double _hoc_interval(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  interval (  *getarg(1) );
 return(_r);
}
 
static int  event_time (  ) {
   if ( slow_freq  == 0.0  || ( burst  != 0.  && APinburst > 1.0 ) ) {
     event = event + interval ( _threadargscomma_ fast_invl ) ;
     if ( slow_freq > 0.0  && event > burst_on + burst_off ) {
       burst = 0. ;
       }
     }
   else {
     burst = 1. ;
     event = event + interval ( _threadargscomma_ slow_invl - ( APinburst - 1.0 ) * fast_invl ) ;
     burst_on = event ;
     burst_off = interval ( _threadargscomma_ ( APinburst - 1.0 ) * fast_invl ) - 1e-6 ;
     }
   if ( event > endbursting ) {
     on = 0.0 ;
     }
    return 0; }
 
static double _hoc_event_time(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 event_time (  );
 return(_r);
}
 
static void _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{    _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t;   if (_lflag == 1. ) {*(_tqitem) = 0;}
 {
   if ( _lflag  == 3.0 ) {
     if ( on  == 0.0 ) {
       on = 1.0 ;
       event = t ;
       burst_on = event ;
       burst_off = interval ( _threadargscomma_ ( APinburst - 1.0 ) * fast_invl ) - 1e-6 ;
       net_send ( _tqitem, _args, _pnt, t +  0.0 , 1.0 ) ;
       }
     }
   if ( _lflag  == 4.0 ) {
     if ( on  == 0.0 ) {
       on = 1.0 ;
       event = t ;
       net_send ( _tqitem, _args, _pnt, t +  0.0 , 1.0 ) ;
       }
     }
   if ( _lflag  == 1.0  && on  == 1.0 ) {
     y = 20.0 ;
     net_event ( _pnt, t ) ;
     if ( t >= startbursting  && t <= endbursting ) {
       event_time ( _threadargs_ ) ;
       net_send ( _tqitem, _args, _pnt, t +  event - t , 1.0 ) ;
       }
     else {
       on = 0.0 ;
       }
     net_send ( _tqitem, _args, _pnt, t +  .1 , 2.0 ) ;
     }
   if ( _lflag  == 2.0 ) {
     y = - 70.0 ;
     }
   } }

static void initmodel() {
  int _i; double _save;_ninits++;
{
 {
   on = 0.0 ;
   y = - 70.0 ;
   endbursting = endbursting - 1e-6 ;
   if ( slow_freq  != 0. ) {
     slow_invl = ( 1.0 / slow_freq ) * ( 1000.0 ) ;
     }
   if ( fast_freq  != 0. ) {
     fast_invl = ( 1.0 / fast_freq ) * ( 1000.0 ) ;
     }
   burst = 1.0 ;
   if ( t01 > 0.0 ) {
     event = t01 ;
     net_send ( _tqitem, (double*)0, _ppvar[1]._pvoid, t +  event , 4.0 ) ;
     }
   if ( t02 > 0.0 ) {
     event = t02 ;
     net_send ( _tqitem, (double*)0, _ppvar[1]._pvoid, t +  event , 4.0 ) ;
     }
   if ( startbursting >= 0.0  && APinburst > 0.0 ) {
     event = startbursting ;
     net_send ( _tqitem, (double*)0, _ppvar[1]._pvoid, t +  event , 3.0 ) ;
     }
   }

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
 _tsav = -1e20;
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
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
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
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "spgen2.mod";
static const char* nmodl_file_text = 
  "TITLE Modified SpikeGenerator of M. Hines\n"
  "NEURON{ \n"
  "  POINT_PROCESS SpGen2\n"
  "  RANGE y, t01,t02\n"
  "  RANGE fast_freq, slow_freq, APinburst, startbursting, endbursting\n"
  "  RANGE noise\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "      t01=20 (ms)\n"
  "      t02=420000 (ms)\n"
  "	fast_freq	= 100 (/s)	: time between spikes in a burst (msec)\n"
  "	slow_freq	= 0.00000001 (/s) :0.00000000001:5 (/s)	: burst period (msec)\n"
  "	APinburst	= 4: 5		: burst length (# spikes)\n"
  "	startbursting = 30 (ms)	: start of first interburst interval\n"
  "	endbursting		= 3200 (ms)	: time to stop bursting\n"
  "	noise		= 0		: amount of randomeaness (0.0 - 1.0)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "      fast_invl (ms)\n"
  "      slow_invl (ms)\n"
  "	y\n"
  "	burst\n"
  "	event (ms)\n"
  "	burst_off (ms)\n"
  "	burst_on (ms)\n"
  "	on\n"
  "}\n"
  "\n"
  "PROCEDURE seed(x) {\n"
  "	set_seed(x)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	on = 0\n"
  "	y = -70\n"
  "    endbursting = endbursting -1e-6 \n"
  "      if (slow_freq != 0.) {slow_invl= (1/slow_freq )*(1000)}\n"
  " if (fast_freq != 0.) {fast_invl= (1/fast_freq )*(1000) }\n"
  "	burst = 1\n"
  "       if (t01>0) {\n"
  "      event= t01\n"
  "      net_send (event,4)}\n"
  " if (t02>0) {\n"
  "      event= t02\n"
  "      net_send (event,4)}\n"
  "      if (startbursting>=0 && APinburst >0 ) {\n"
  "     event = startbursting\n"
  "	net_send(event, 3)\n"
  "	}\n"
  "}	\n"
  "\n"
  "FUNCTION interval(mean (ms)) (ms) {\n"
  "	if (mean <= 0.) {\n"
  "		mean = .01 (ms) 	\n"
  "	}\n"
  "	if (noise == 0) {\n"
  "		interval = mean\n"
  "	}else{\n"
  "		interval = (1. - noise)*mean + noise*mean*exprand(1)\n"
  "	}\n"
  "}\n"
  "\n"
  "PROCEDURE event_time() {\n"
  "	if (slow_freq == 0 || (burst != 0. && APinburst > 1)) {\n"
  "		event = event + interval(fast_invl)\n"
  "if (slow_freq > 0 && event > burst_on + burst_off) {\n"
  "			burst = 0.\n"
  "		}\n"
  "	}else{\n"
  "		burst = 1.\n"
  ": if slow_invl from beginning of burst to beginning of burst\n"
  "		event = event + interval(slow_invl - (APinburst-1)*fast_invl)\n"
  ": use following if slow_invl is interburst interval\n"
  "		:event = event + interval(slow_invl)\n"
  "		burst_on = event\n"
  "		burst_off = interval((APinburst - 1)*fast_invl)-1e-6\n"
  "	}\n"
  "	if (event > endbursting) {\n"
  "		on = 0\n"
  "	}\n"
  "}\n"
  "\n"
  "NET_RECEIVE (w) {\n"
  ":printf(\"Pregen receive t=%g flag=%g\\n\", t, flag) \n"
  "       if (flag == 3){\n"
  "      if (on == 0){\n"
  "       on =1\n"
  "        event = t\n"
  " burst_on = event\n"
  "		burst_off = interval((APinburst - 1)*fast_invl)-1e-6\n"
  "         net_send (0,1)\n"
  "       } }\n"
  "      if (flag == 4)\n"
  "{\n"
  "     if (on == 0) {\n"
  "      on = 1\n"
  "      event = t\n"
  "       net_send (0,1)}}\n"
  "	if (flag == 1 && on == 1) {\n"
  "		y = 20\n"
  "		net_event(t)\n"
  "       if (t>= startbursting && t<= endbursting)\n"
  "		{\n"
  "            event_time()\n"
  "		net_send(event - t, 1)\n"
  "           } else {on=0 }\n"
  "		net_send(.1, 2)\n"
  "	}\n"
  "	if (flag == 2) {\n"
  "		y = -70\n"
  "	}\n"
  "}\n"
  "\n"
  "\n"
  ;
#endif
