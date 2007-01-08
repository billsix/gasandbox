
// Generated on 2007-01-08 11:06:36 by G2 0.1 from 'E:\ga\ga_sandbox\ga_sandbox\libgasandbox\h3ga.gs2'

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <stdio.h>
#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <string>

	#include "mvtypebase.h"

	// pre_h_include


	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>

	#ifndef _GA_h3ga_h_H_
	#define _GA_h3ga_h_H_

	namespace h3ga {

	// multivector types:
	enum g2Type {
		MVT_NONE = -1,
			MVT_E1_T = 10,
			MVT_E2_T = 11,
			MVT_E3_T = 12,
			MVT_E0_T = 13,
			MVT_SCALAR = 14,
			MVT_VECTOR = 15,
			MVT_POINT = 16,
			MVT_NORMALIZEDPOINT = 17,
			MVT_LINE = 18,
			MVT_LINEATINFINITY = 19,
			MVT_BIVECTOR = 20,
			MVT_PLANE = 21,
			MVT_PLANEATINFINITY = 22,
			MVT_ROTOR = 23,
			MVT___E1_CT__ = 24,
			MVT___E2_CT__ = 25,
			MVT___E3_CT__ = 26,
			MVT___E0_CT__ = 27,
			MVT___E0I_CT__ = 28,
			MVT___I4I_CT__ = 29,
			MVT_MV = 8,
			MVT_LAST = 31 
	};

	// outermorphism types:
	enum omType {
		OMT_NONE = -2,
			OMT_OMPOINT = 30,
			OMT_OM = 9,
			OMT_LAST = 31 
	};

	// grade definitions that can be joined using the '|' operator:
	const int GRADE_0 = 1;
	const int GRADE_1 = 2;
	const int GRADE_2 = 4;
	const int GRADE_3 = 8;
	const int GRADE_4 = 16;

	// The dimension of the space:
	extern const int mv_spaceDim;

	// Is the metric of the space Euclidean?
	extern const bool mv_metricEuclidean;

	// This array can be used to lookup the number of coordinates for a grade part of a general multivector
	extern const int mv_gradeSize[5];

	// This array can be used to lookup the number of coordinates based on a grade usage bitmap
	extern const int mv_size[32];

	// This array of ASCIIZ strings contains the names of the basis vectors
	extern const char *mv_basisVectorNames[4];

	// This array of integers contains the order of basis elements in the general multivector
	// Use it to answer: 'what basis vectors are in the basis element at position [x]?
	extern const int mv_basisElements[16][5];

	// This array of integers contains the 'sign' (even/odd permutation of canonical order) of basis elements in the general multivector
	extern const double mv_basisElementSign[16];

	// This array of integers contains the order of basis elements in the general multivector
	// Use it to answer: 'at what index do I find basis element [x] (x = basis vector bitmap)?'
	extern const int mv_basisElementIndexByBitmap[16];

	// This array of integers contains the indices of basis elements in the general multivector
	// Use it to answer: 'what basis element do I find at index [x]'?
	extern const int mv_basisElementBitmapByIndex[16];



	/* *************************************************************************** */
	/* *************************** define all classes upfront *************************** */
	/* *************************************************************************** */
	class e1_t;
	class e2_t;
	class e3_t;
	class e0_t;
	class scalar;
	class vector;
	class point;
	class normalizedPoint;
	class line;
	class lineAtInfinity;
	class bivector;
	class plane;
	class planeAtInfinity;
	class rotor;
	class __e1_ct__;
	class __e2_ct__;
	class __e3_ct__;
	class __e0_ct__;
	class __e0i_ct__;
	class __I4i_ct__;
	class mv;
	class omPoint;
	class om;




	// exception handling:
	const int MV_EXCEPTION_WARNING = 1;
	const int MV_EXCEPTION_ERROR = 2;
	// Exception mechanism: ignore & pray
	inline void mv_throw_exception(const char *msg, int level) {}

	// You can alter the formatting of 'string()' through this function.
	// 'format' = NULL will give you back the default.
	void mv_setStringFormat(const char *what, const char *format = NULL);

	extern const char *mv_string_fp; /* = \"%2.2f\" */
	extern const char *mv_string_start; /* = \"\" */
	extern const char *mv_string_end; /* = \"\" */
	extern const char *mv_string_mul; /* = \"*\" */
	extern const char *mv_string_wedge; /* = \"^\" */
	extern const char *mv_string_plus; /* = \" + \" */
	extern const char *mv_string_minus; /* = \" - \" */

	// declaration of profiling functions
	namespace g2Profiling {
		void profile(unsigned int funcIdx, unsigned short storageTypeIdx, unsigned short nbArg, 
			unsigned short argType[], int nbReturnType, unsigned short returnType[]);
		void reset();
		void save(const char *filename = "E:\\ga\\ga_sandbox\\ga_sandbox\\libgasandbox\\h3ga.gp2", bool append = true);
		void init(const char *filename = "E:\\ga\\ga_sandbox\\ga_sandbox\\libgasandbox\\h3ga.gp2",
			const char *hostName = "localhost", int port = 7693);
	} // end of namespace g2Profiling



	inline void mv_memcpy(float *to, const float *from, const int nb) {
		memcpy(to, from, sizeof(float) * nb);
	}

	inline void mv_zero(float *ptr, const int nb) {
		memset(ptr, 0, sizeof(float) * nb);
	}

	// a is any number, b is positive number
	inline bool mv_absLessThan(const float a, const float b) {
		return ((a > b) || (a < -b));
	}

	inline float mv_stringToNumber(const char *asciiz) {
		return (float)atof(asciiz);
	}

	void updateCoordinateString(const mv &x, char **cs, size_t &csl);
	char *c_str(const mv &  obj, const char *fp = NULL);
	std::string toString(const mv &  obj, const char *fp = NULL);

	inline char *c_str_f(const mv &  obj) {return c_str(obj, "%f");}
	inline char *c_str_e(const mv &  obj) {return c_str(obj, "%e");}
	inline char *c_str_e20(const mv &  obj) {return c_str(obj, "%2.20e");}

	inline std::string toString_f(const mv &  obj) {return toString(obj, "%f");}
	inline std::string toString_e(const mv &  obj) {return toString(obj, "%e");}
	inline std::string toString_e20(const mv &  obj) {return toString(obj, "%2.20e");}


	class mv {
		// the friend classes of mv 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		// friend functions of mv 
		friend char *string(const mv &obj, char *str, int maxLength, const char *fp /*= NULL*/);
		friend void compress(const float *c, float *cc, int &cgu, float epsilon = 0.0, int gu = 31);
		friend mv compress(const mv & arg, float epsilon);

		public:
			typedef float Float;

		/// zero constructor
		inline mv () {

			set();
		}

		/// copy constructor (MUST PASS BY REFERENCE)
		inline mv(const mv &arg1) {

			set(arg1);
		}

		/// scalar constructor
		inline mv(Float scalar) {

			set(scalar);
		}

		/// pointer to coordinates constructor
		inline mv(unsigned int gradeUsage, const Float *coordinates, g2Type type = MVT_MV) {

			set(gradeUsage, coordinates, type);
		}

		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, type);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, g2Type type = MVT_MV) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, type);
		}

		/// init from e1_t constructor
		inline mv(const e1_t &arg1) {
			set(arg1);
		}
		/// init from e2_t constructor
		inline mv(const e2_t &arg1) {
			set(arg1);
		}
		/// init from e3_t constructor
		inline mv(const e3_t &arg1) {
			set(arg1);
		}
		/// init from e0_t constructor
		inline mv(const e0_t &arg1) {
			set(arg1);
		}
		/// init from scalar constructor
		inline mv(const scalar &arg1) {
			set(arg1);
		}
		/// init from vector constructor
		inline mv(const vector &arg1) {
			set(arg1);
		}
		/// init from point constructor
		inline mv(const point &arg1) {
			set(arg1);
		}
		/// init from normalizedPoint constructor
		inline mv(const normalizedPoint &arg1) {
			set(arg1);
		}
		/// init from line constructor
		inline mv(const line &arg1) {
			set(arg1);
		}
		/// init from lineAtInfinity constructor
		inline mv(const lineAtInfinity &arg1) {
			set(arg1);
		}
		/// init from bivector constructor
		inline mv(const bivector &arg1) {
			set(arg1);
		}
		/// init from plane constructor
		inline mv(const plane &arg1) {
			set(arg1);
		}
		/// init from planeAtInfinity constructor
		inline mv(const planeAtInfinity &arg1) {
			set(arg1);
		}
		/// init from rotor constructor
		inline mv(const rotor &arg1) {
			set(arg1);
		}
		/// init from __e1_ct__ constructor
		inline mv(const __e1_ct__ &arg1) {
			set(arg1);
		}
		/// init from __e2_ct__ constructor
		inline mv(const __e2_ct__ &arg1) {
			set(arg1);
		}
		/// init from __e3_ct__ constructor
		inline mv(const __e3_ct__ &arg1) {
			set(arg1);
		}
		/// init from __e0_ct__ constructor
		inline mv(const __e0_ct__ &arg1) {
			set(arg1);
		}
		/// init from __e0i_ct__ constructor
		inline mv(const __e0i_ct__ &arg1) {
			set(arg1);
		}
		/// init from __I4i_ct__ constructor
		inline mv(const __I4i_ct__ &arg1) {
			set(arg1);
		}


		/// set to null
		void set();

		/// set to copy
		void set(const mv &arg1);

		/// set to scalar
		void set(Float scalar);

		/// pointer to coordinates constructor
		void set(unsigned int gradeUsage, const Float *coordinates, g2Type type = MVT_MV);


		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, g2Type type = MVT_MV);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, g2Type type = MVT_MV);


		/// set to e1_t 
		void set(const e1_t &arg1);
		/// set to e2_t 
		void set(const e2_t &arg1);
		/// set to e3_t 
		void set(const e3_t &arg1);
		/// set to e0_t 
		void set(const e0_t &arg1);
		/// set to scalar 
		void set(const scalar &arg1);
		/// set to vector 
		void set(const vector &arg1);
		/// set to point 
		void set(const point &arg1);
		/// set to normalizedPoint 
		void set(const normalizedPoint &arg1);
		/// set to line 
		void set(const line &arg1);
		/// set to lineAtInfinity 
		void set(const lineAtInfinity &arg1);
		/// set to bivector 
		void set(const bivector &arg1);
		/// set to plane 
		void set(const plane &arg1);
		/// set to planeAtInfinity 
		void set(const planeAtInfinity &arg1);
		/// set to rotor 
		void set(const rotor &arg1);
		/// set to __e1_ct__ 
		void set(const __e1_ct__ &arg1);
		/// set to __e2_ct__ 
		void set(const __e2_ct__ &arg1);
		/// set to __e3_ct__ 
		void set(const __e3_ct__ &arg1);
		/// set to __e0_ct__ 
		void set(const __e0_ct__ &arg1);
		/// set to __e0i_ct__ 
		void set(const __e0i_ct__ &arg1);
		/// set to __I4i_ct__ 
		void set(const __I4i_ct__ &arg1);


		/// assign copy
		mv &operator=(const mv &arg1);

		/// assign scalar
		mv &operator=(Float scalar);

		/// assign e1_t 
		mv&operator=(const e1_t& arg1);
		/// assign e2_t 
		mv&operator=(const e2_t& arg1);
		/// assign e3_t 
		mv&operator=(const e3_t& arg1);
		/// assign e0_t 
		mv&operator=(const e0_t& arg1);
		/// assign scalar 
		mv&operator=(const scalar& arg1);
		/// assign vector 
		mv&operator=(const vector& arg1);
		/// assign point 
		mv&operator=(const point& arg1);
		/// assign normalizedPoint 
		mv&operator=(const normalizedPoint& arg1);
		/// assign line 
		mv&operator=(const line& arg1);
		/// assign lineAtInfinity 
		mv&operator=(const lineAtInfinity& arg1);
		/// assign bivector 
		mv&operator=(const bivector& arg1);
		/// assign plane 
		mv&operator=(const plane& arg1);
		/// assign planeAtInfinity 
		mv&operator=(const planeAtInfinity& arg1);
		/// assign rotor 
		mv&operator=(const rotor& arg1);
		/// assign __e1_ct__ 
		mv&operator=(const __e1_ct__& arg1);
		/// assign __e2_ct__ 
		mv&operator=(const __e2_ct__& arg1);
		/// assign __e3_ct__ 
		mv&operator=(const __e3_ct__& arg1);
		/// assign __e0_ct__ 
		mv&operator=(const __e0_ct__& arg1);
		/// assign __e0i_ct__ 
		mv&operator=(const __e0i_ct__& arg1);
		/// assign __I4i_ct__ 
		mv&operator=(const __I4i_ct__& arg1);


		void compress(Float epsilon = 0.0);
		inline Float const *nullFloats() const {
			static Float *nf = NULL;
			if (nf == NULL) nf = new Float[16];
			return nf;
		}
		void expand(const Float *ptrs[], bool nulls = true) const;
		/// returns the absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;


		/// coordinate extraction by name
		inline Float e1() const {
			if (gu() & 2)
				return m_c[mv_size[gu() & 1] + 0];
			else return (float)0.0;
		}
		inline Float e2() const {
			if (gu() & 2)
				return m_c[mv_size[gu() & 1] + 1];
			else return (float)0.0;
		}
		inline Float e3() const {
			if (gu() & 2)
				return m_c[mv_size[gu() & 1] + 2];
			else return (float)0.0;
		}
		inline Float e0() const {
			if (gu() & 2)
				return m_c[mv_size[gu() & 1] + 3];
			else return (float)0.0;
		}
		inline Float e1e2() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 0];
			else return (float)0.0;
		}
		inline Float e2e3() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 1];
			else return (float)0.0;
		}
		inline Float e3e1() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 2];
			else return (float)0.0;
		}
		inline Float e1e0() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 3];
			else return (float)0.0;
		}
		inline Float e2e0() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 4];
			else return (float)0.0;
		}
		inline Float e3e0() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 5];
			else return (float)0.0;
		}
		inline Float e1e2e3() const {
			if (gu() & 8)
				return m_c[mv_size[gu() & 7] + 0];
			else return (float)0.0;
		}
		inline Float e1e2e0() const {
			if (gu() & 8)
				return m_c[mv_size[gu() & 7] + 1];
			else return (float)0.0;
		}
		inline Float e2e3e0() const {
			if (gu() & 8)
				return m_c[mv_size[gu() & 7] + 2];
			else return (float)0.0;
		}
		inline Float e3e1e0() const {
			if (gu() & 8)
				return m_c[mv_size[gu() & 7] + 3];
			else return (float)0.0;
		}
		inline Float e1e2e3e0() const {
			if (gu() & 16)
				return m_c[mv_size[gu() & 15] + 0];
			else return (float)0.0;
		}

		// coordinate storage, grade usage
		Float m_c[16]; ///< coordinate storage (TODO: if parity pure, allocate only half of the coordinates!!!)
		unsigned int m_gu; ///< grade usage
		inline unsigned int gu() const {return m_gu;}
		inline void gu(unsigned int g) {m_gu = g;}
		g2Type m_type; ///< type (used for profiling)
		inline g2Type type() const {return m_type;}
		inline void type(g2Type t) {m_type = t;}



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}
		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}
		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}



	}; // end of class mv 

	char *string(const mv & obj, char *str, int maxLength, const char *fp = NULL);
	// this function should be deprecated (conflicts with C++ stdlib)
	char *string(const mv & obj, const char *fp = NULL);


	mv mv_compress(const float *coordinates, float epsilon = (float)0.0, int gu = 16 * 2 -1);


	// underscore 'constructors' for float types:

	/// returns scalar part of arg1 as float
	inline float _float(const mv & arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)44), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return (arg1.m_gu & 1) ? (float)arg1.m_c[0] : 0.0f;
	}
	/// returns scalar part of arg1 as double
	inline double _double(const mv & arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)45), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return (arg1.m_gu & 1) ? (double)arg1.m_c[0] : 0.0;
	}
	/// returns scalar part of arg1 as Float
	inline float _Float(const mv & arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)46), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return (arg1.m_gu & 1) ? arg1.m_c[0] : (float)0.0;
	}

	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline const mv like(const mv &what, const mv &example) {return what;}
	inline mv like(mv &what, const mv &example) {return what;}


	/// enum for the coordinates of e1_t 
	enum __e1_t_coordinates__ {e1_t_e1};

	class e1_t {
		// the friend classes of e1_t 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline e1_t() {

			set();
		}

		/// scalar constructor 
		inline e1_t(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> e1_t	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline e1_t(const e1_t &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline e1_t(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> e1_t	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline e1_t(__e1_t_coordinates__, const Float *coordinates) {

			set(e1_t_e1, coordinates);
		}

		/// coordinates constructor
		inline e1_t(__e1_t_coordinates__, Float c_e1) {

			set(e1_t_e1, c_e1);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const e1_t &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__e1_t_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__e1_t_coordinates__, Float c_e1);

		/// assign copy
		e1_t &operator=(const e1_t &arg1);

		/// assign general multivector
		e1_t &operator=(const mv &arg1);

		/// assign scalar
		e1_t &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__e1_t_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class e1_t 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline e1_t _e1_t(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)24), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return e1_t(arg1, 0);
	}
	/// from const specialization class:
	inline const e1_t &_e1_t(const e1_t &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline e1_t &_e1_t(e1_t &arg1) {
		return arg1;
	}
	/// from Float:
	inline e1_t _e1_t(e1_t::Float arg1) {
		return e1_t(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline e1_t like(const mv &what, const e1_t &example) {return _e1_t(what);}
	/// from const specialization class:
	inline const e1_t like(const e1_t &what, const e1_t &example) {return _e1_t(what);}
	/// from non-const specialization class:
	inline e1_t like(e1_t &what, const e1_t &example) {return _e1_t(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const e1_t & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const e1_t & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const e1_t & v) {
		return (float)0;
	}


	/// enum for the coordinates of e2_t 
	enum __e2_t_coordinates__ {e2_t_e2};

	class e2_t {
		// the friend classes of e2_t 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;

		public:
			typedef float Float;

		/// zero constructor
		inline e2_t() {

			set();
		}

		/// scalar constructor 
		inline e2_t(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> e2_t	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline e2_t(const e2_t &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline e2_t(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> e2_t	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline e2_t(__e2_t_coordinates__, const Float *coordinates) {

			set(e2_t_e2, coordinates);
		}

		/// coordinates constructor
		inline e2_t(__e2_t_coordinates__, Float c_e2) {

			set(e2_t_e2, c_e2);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const e2_t &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__e2_t_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__e2_t_coordinates__, Float c_e2);

		/// assign copy
		e2_t &operator=(const e2_t &arg1);

		/// assign general multivector
		e2_t &operator=(const mv &arg1);

		/// assign scalar
		e2_t &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e2() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__e2_t_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class e2_t 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline e2_t _e2_t(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)25), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return e2_t(arg1, 0);
	}
	/// from const specialization class:
	inline const e2_t &_e2_t(const e2_t &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline e2_t &_e2_t(e2_t &arg1) {
		return arg1;
	}
	/// from Float:
	inline e2_t _e2_t(e2_t::Float arg1) {
		return e2_t(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline e2_t like(const mv &what, const e2_t &example) {return _e2_t(what);}
	/// from const specialization class:
	inline const e2_t like(const e2_t &what, const e2_t &example) {return _e2_t(what);}
	/// from non-const specialization class:
	inline e2_t like(e2_t &what, const e2_t &example) {return _e2_t(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const e2_t & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const e2_t & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const e2_t & v) {
		return (float)0;
	}


	/// enum for the coordinates of e3_t 
	enum __e3_t_coordinates__ {e3_t_e3};

	class e3_t {
		// the friend classes of e3_t 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline e3_t() {

			set();
		}

		/// scalar constructor 
		inline e3_t(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> e3_t	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline e3_t(const e3_t &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline e3_t(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> e3_t	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline e3_t(__e3_t_coordinates__, const Float *coordinates) {

			set(e3_t_e3, coordinates);
		}

		/// coordinates constructor
		inline e3_t(__e3_t_coordinates__, Float c_e3) {

			set(e3_t_e3, c_e3);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const e3_t &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__e3_t_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__e3_t_coordinates__, Float c_e3);

		/// assign copy
		e3_t &operator=(const e3_t &arg1);

		/// assign general multivector
		e3_t &operator=(const mv &arg1);

		/// assign scalar
		e3_t &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e3() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__e3_t_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class e3_t 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline e3_t _e3_t(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)26), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return e3_t(arg1, 0);
	}
	/// from const specialization class:
	inline const e3_t &_e3_t(const e3_t &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline e3_t &_e3_t(e3_t &arg1) {
		return arg1;
	}
	/// from Float:
	inline e3_t _e3_t(e3_t::Float arg1) {
		return e3_t(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline e3_t like(const mv &what, const e3_t &example) {return _e3_t(what);}
	/// from const specialization class:
	inline const e3_t like(const e3_t &what, const e3_t &example) {return _e3_t(what);}
	/// from non-const specialization class:
	inline e3_t like(e3_t &what, const e3_t &example) {return _e3_t(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const e3_t & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const e3_t & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const e3_t & v) {
		return (float)0;
	}


	/// enum for the coordinates of e0_t 
	enum __e0_t_coordinates__ {e0_t_e0};

	class e0_t {
		// the friend classes of e0_t 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline e0_t() {

			set();
		}

		/// scalar constructor 
		inline e0_t(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> e0_t	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline e0_t(const e0_t &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline e0_t(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> e0_t	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline e0_t(__e0_t_coordinates__, const Float *coordinates) {

			set(e0_t_e0, coordinates);
		}

		/// coordinates constructor
		inline e0_t(__e0_t_coordinates__, Float c_e0) {

			set(e0_t_e0, c_e0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const e0_t &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__e0_t_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__e0_t_coordinates__, Float c_e0);

		/// assign copy
		e0_t &operator=(const e0_t &arg1);

		/// assign general multivector
		e0_t &operator=(const mv &arg1);

		/// assign scalar
		e0_t &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e0() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__e0_t_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class e0_t 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline e0_t _e0_t(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)27), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return e0_t(arg1, 0);
	}
	/// from const specialization class:
	inline const e0_t &_e0_t(const e0_t &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline e0_t &_e0_t(e0_t &arg1) {
		return arg1;
	}
	/// from Float:
	inline e0_t _e0_t(e0_t::Float arg1) {
		return e0_t(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline e0_t like(const mv &what, const e0_t &example) {return _e0_t(what);}
	/// from const specialization class:
	inline const e0_t like(const e0_t &what, const e0_t &example) {return _e0_t(what);}
	/// from non-const specialization class:
	inline e0_t like(e0_t &what, const e0_t &example) {return _e0_t(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const e0_t & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const e0_t & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const e0_t & v) {
		return (float)0;
	}


	/// enum for the coordinates of scalar 
	enum __scalar_coordinates__ {scalar_scalar};

	class scalar {
		// the friend classes of scalar 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline scalar() {

			set();
		}

		/// scalar constructor 
		inline scalar(Float s) {

			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline scalar(const scalar &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline scalar(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> scalar	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline scalar(__scalar_coordinates__, const Float *coordinates) {

			set(scalar_scalar, coordinates);
		}

		/// coordinates constructor
		inline scalar(__scalar_coordinates__, Float c_scalar) {

			set(scalar_scalar, c_scalar);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const scalar &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__scalar_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__scalar_coordinates__, Float c_scalar);

		/// assign copy
		scalar &operator=(const scalar &arg1);

		/// assign general multivector
		scalar &operator=(const mv &arg1);

		/// assign scalar
		scalar &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__scalar_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class scalar 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline scalar _scalar(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)28), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return scalar(arg1, 0);
	}
	/// from const specialization class:
	inline const scalar &_scalar(const scalar &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline scalar &_scalar(scalar &arg1) {
		return arg1;
	}
	/// from Float:
	inline scalar _scalar(scalar::Float arg1) {
		return scalar(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline scalar like(const mv &what, const scalar &example) {return _scalar(what);}
	/// from const specialization class:
	inline const scalar like(const scalar &what, const scalar &example) {return _scalar(what);}
	/// from non-const specialization class:
	inline scalar like(scalar &what, const scalar &example) {return _scalar(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const scalar & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const scalar & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const scalar & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of vector 
	enum __vector_coordinates__ {vector_e1_e2_e3};

	class vector {
		// the friend classes of vector 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline vector() {

			set();
		}

		/// scalar constructor 
		inline vector(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> vector	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline vector(const vector &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline vector(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> vector	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline vector(__vector_coordinates__, const Float *coordinates) {

			set(vector_e1_e2_e3, coordinates);
		}

		/// coordinates constructor
		inline vector(__vector_coordinates__, Float c_e1, Float c_e2, Float c_e3) {

			set(vector_e1_e2_e3, c_e1, c_e2, c_e3);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const vector &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__vector_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__vector_coordinates__, Float c_e1, Float c_e2, Float c_e3);

		/// assign copy
		vector &operator=(const vector &arg1);

		/// assign general multivector
		vector &operator=(const mv &arg1);

		/// assign scalar
		vector &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}
		inline Float e3() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__vector_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class vector 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline vector _vector(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)29), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return vector(arg1, 0);
	}
	/// from const specialization class:
	inline const vector &_vector(const vector &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline vector &_vector(vector &arg1) {
		return arg1;
	}
	/// from Float:
	inline vector _vector(vector::Float arg1) {
		return vector(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline vector like(const mv &what, const vector &example) {return _vector(what);}
	/// from const specialization class:
	inline const vector like(const vector &what, const vector &example) {return _vector(what);}
	/// from non-const specialization class:
	inline vector like(vector &what, const vector &example) {return _vector(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const vector & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const vector & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const vector & v) {
		return (float)0;
	}


	/// enum for the coordinates of point 
	enum __point_coordinates__ {point_e1_e2_e3_e0};

	class point {
		// the friend classes of point 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline point() {

			set();
		}

		/// scalar constructor 
		inline point(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> point	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline point(const point &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline point(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> point	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline point(__point_coordinates__, const Float *coordinates) {

			set(point_e1_e2_e3_e0, coordinates);
		}

		/// coordinates constructor
		inline point(__point_coordinates__, Float c_e1, Float c_e2, Float c_e3, Float c_e0) {

			set(point_e1_e2_e3_e0, c_e1, c_e2, c_e3, c_e0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const point &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__point_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__point_coordinates__, Float c_e1, Float c_e2, Float c_e3, Float c_e0);

		/// assign copy
		point &operator=(const point &arg1);

		/// assign general multivector
		point &operator=(const mv &arg1);

		/// assign scalar
		point &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}
		inline Float e3() const {
			return m_c[2];
		}
		inline Float e0() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__point_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class point 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline point _point(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)30), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return point(arg1, 0);
	}
	/// from const specialization class:
	inline const point &_point(const point &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline point &_point(point &arg1) {
		return arg1;
	}
	/// from Float:
	inline point _point(point::Float arg1) {
		return point(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline point like(const mv &what, const point &example) {return _point(what);}
	/// from const specialization class:
	inline const point like(const point &what, const point &example) {return _point(what);}
	/// from non-const specialization class:
	inline point like(point &what, const point &example) {return _point(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const point & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const point & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const point & v) {
		return (float)0;
	}


	/// enum for the coordinates of normalizedPoint 
	enum __normalizedPoint_coordinates__ {normalizedPoint_e1_e2_e3_e0f1_0};

	class normalizedPoint {
		// the friend classes of normalizedPoint 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline normalizedPoint() {

			set();
		}

		/// scalar constructor 
		inline normalizedPoint(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> normalizedPoint	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline normalizedPoint(const normalizedPoint &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline normalizedPoint(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> normalizedPoint	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline normalizedPoint(__normalizedPoint_coordinates__, const Float *coordinates) {

			set(normalizedPoint_e1_e2_e3_e0f1_0, coordinates);
		}

		/// coordinates constructor
		inline normalizedPoint(__normalizedPoint_coordinates__, Float c_e1, Float c_e2, Float c_e3) {

			set(normalizedPoint_e1_e2_e3_e0f1_0, c_e1, c_e2, c_e3);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const normalizedPoint &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__normalizedPoint_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__normalizedPoint_coordinates__, Float c_e1, Float c_e2, Float c_e3);

		/// assign copy
		normalizedPoint &operator=(const normalizedPoint &arg1);

		/// assign general multivector
		normalizedPoint &operator=(const mv &arg1);

		/// assign scalar
		normalizedPoint &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}
		inline Float e3() const {
			return m_c[2];
		}

		/// const coordinate extraction by name
		inline Float e0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__normalizedPoint_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class normalizedPoint 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline normalizedPoint _normalizedPoint(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)31), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return normalizedPoint(arg1, 0);
	}
	/// from const specialization class:
	inline const normalizedPoint &_normalizedPoint(const normalizedPoint &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline normalizedPoint &_normalizedPoint(normalizedPoint &arg1) {
		return arg1;
	}
	/// from Float:
	inline normalizedPoint _normalizedPoint(normalizedPoint::Float arg1) {
		return normalizedPoint(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline normalizedPoint like(const mv &what, const normalizedPoint &example) {return _normalizedPoint(what);}
	/// from const specialization class:
	inline const normalizedPoint like(const normalizedPoint &what, const normalizedPoint &example) {return _normalizedPoint(what);}
	/// from non-const specialization class:
	inline normalizedPoint like(normalizedPoint &what, const normalizedPoint &example) {return _normalizedPoint(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const normalizedPoint & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const normalizedPoint & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const normalizedPoint & v) {
		return (float)0;
	}


	/// enum for the coordinates of line 
	enum __line_coordinates__ {line_e1e2_e2e3_e3e1_e1e0_e2e0_e3e0};

	class line {
		// the friend classes of line 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline line() {

			set();
		}

		/// scalar constructor 
		inline line(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> line	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline line(const line &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline line(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> line	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline line(__line_coordinates__, const Float *coordinates) {

			set(line_e1e2_e2e3_e3e1_e1e0_e2e0_e3e0, coordinates);
		}

		/// coordinates constructor
		inline line(__line_coordinates__, Float c_e1e2, Float c_e2e3, Float c_e3e1, Float c_e1e0, Float c_e2e0, Float c_e3e0) {

			set(line_e1e2_e2e3_e3e1_e1e0_e2e0_e3e0, c_e1e2, c_e2e3, c_e3e1, c_e1e0, c_e2e0, c_e3e0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const line &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__line_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__line_coordinates__, Float c_e1e2, Float c_e2e3, Float c_e3e1, Float c_e1e0, Float c_e2e0, Float c_e3e0);

		/// assign copy
		line &operator=(const line &arg1);

		/// assign general multivector
		line &operator=(const mv &arg1);

		/// assign scalar
		line &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[0];
		}
		inline Float e2e3() const {
			return m_c[1];
		}
		inline Float e3e1() const {
			return m_c[2];
		}
		inline Float e1e0() const {
			return m_c[3];
		}
		inline Float e2e0() const {
			return m_c[4];
		}
		inline Float e3e0() const {
			return m_c[5];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__line_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[6];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class line 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline line _line(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)32), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return line(arg1, 0);
	}
	/// from const specialization class:
	inline const line &_line(const line &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline line &_line(line &arg1) {
		return arg1;
	}
	/// from Float:
	inline line _line(line::Float arg1) {
		return line(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline line like(const mv &what, const line &example) {return _line(what);}
	/// from const specialization class:
	inline const line like(const line &what, const line &example) {return _line(what);}
	/// from non-const specialization class:
	inline line like(line &what, const line &example) {return _line(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const line & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const line & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const line & v) {
		return (float)0;
	}


	/// enum for the coordinates of lineAtInfinity 
	enum __lineAtInfinity_coordinates__ {lineAtInfinity_e1e2_e2e3_e3e1};

	class lineAtInfinity {
		// the friend classes of lineAtInfinity 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline lineAtInfinity() {

			set();
		}

		/// scalar constructor 
		inline lineAtInfinity(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> lineAtInfinity	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline lineAtInfinity(const lineAtInfinity &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline lineAtInfinity(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> lineAtInfinity	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline lineAtInfinity(__lineAtInfinity_coordinates__, const Float *coordinates) {

			set(lineAtInfinity_e1e2_e2e3_e3e1, coordinates);
		}

		/// coordinates constructor
		inline lineAtInfinity(__lineAtInfinity_coordinates__, Float c_e1e2, Float c_e2e3, Float c_e3e1) {

			set(lineAtInfinity_e1e2_e2e3_e3e1, c_e1e2, c_e2e3, c_e3e1);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const lineAtInfinity &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__lineAtInfinity_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__lineAtInfinity_coordinates__, Float c_e1e2, Float c_e2e3, Float c_e3e1);

		/// assign copy
		lineAtInfinity &operator=(const lineAtInfinity &arg1);

		/// assign general multivector
		lineAtInfinity &operator=(const mv &arg1);

		/// assign scalar
		lineAtInfinity &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[0];
		}
		inline Float e2e3() const {
			return m_c[1];
		}
		inline Float e3e1() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__lineAtInfinity_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class lineAtInfinity 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline lineAtInfinity _lineAtInfinity(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)33), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return lineAtInfinity(arg1, 0);
	}
	/// from const specialization class:
	inline const lineAtInfinity &_lineAtInfinity(const lineAtInfinity &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline lineAtInfinity &_lineAtInfinity(lineAtInfinity &arg1) {
		return arg1;
	}
	/// from Float:
	inline lineAtInfinity _lineAtInfinity(lineAtInfinity::Float arg1) {
		return lineAtInfinity(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline lineAtInfinity like(const mv &what, const lineAtInfinity &example) {return _lineAtInfinity(what);}
	/// from const specialization class:
	inline const lineAtInfinity like(const lineAtInfinity &what, const lineAtInfinity &example) {return _lineAtInfinity(what);}
	/// from non-const specialization class:
	inline lineAtInfinity like(lineAtInfinity &what, const lineAtInfinity &example) {return _lineAtInfinity(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const lineAtInfinity & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const lineAtInfinity & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const lineAtInfinity & v) {
		return (float)0;
	}


	/// enum for the coordinates of bivector 
	enum __bivector_coordinates__ {bivector_e1e2_e2e3_e3e1};

	class bivector {
		// the friend classes of bivector 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline bivector() {

			set();
		}

		/// scalar constructor 
		inline bivector(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> bivector	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline bivector(const bivector &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline bivector(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> bivector	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline bivector(__bivector_coordinates__, const Float *coordinates) {

			set(bivector_e1e2_e2e3_e3e1, coordinates);
		}

		/// coordinates constructor
		inline bivector(__bivector_coordinates__, Float c_e1e2, Float c_e2e3, Float c_e3e1) {

			set(bivector_e1e2_e2e3_e3e1, c_e1e2, c_e2e3, c_e3e1);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const bivector &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__bivector_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__bivector_coordinates__, Float c_e1e2, Float c_e2e3, Float c_e3e1);

		/// assign copy
		bivector &operator=(const bivector &arg1);

		/// assign general multivector
		bivector &operator=(const mv &arg1);

		/// assign scalar
		bivector &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[0];
		}
		inline Float e2e3() const {
			return m_c[1];
		}
		inline Float e3e1() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__bivector_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class bivector 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline bivector _bivector(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)34), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return bivector(arg1, 0);
	}
	/// from const specialization class:
	inline const bivector &_bivector(const bivector &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline bivector &_bivector(bivector &arg1) {
		return arg1;
	}
	/// from Float:
	inline bivector _bivector(bivector::Float arg1) {
		return bivector(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline bivector like(const mv &what, const bivector &example) {return _bivector(what);}
	/// from const specialization class:
	inline const bivector like(const bivector &what, const bivector &example) {return _bivector(what);}
	/// from non-const specialization class:
	inline bivector like(bivector &what, const bivector &example) {return _bivector(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const bivector & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const bivector & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const bivector & v) {
		return (float)0;
	}


	/// enum for the coordinates of plane 
	enum __plane_coordinates__ {plane_e1e2e3_e1e2e0_e2e3e0_e3e1e0};

	class plane {
		// the friend classes of plane 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline plane() {

			set();
		}

		/// scalar constructor 
		inline plane(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> plane	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline plane(const plane &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline plane(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> plane	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline plane(__plane_coordinates__, const Float *coordinates) {

			set(plane_e1e2e3_e1e2e0_e2e3e0_e3e1e0, coordinates);
		}

		/// coordinates constructor
		inline plane(__plane_coordinates__, Float c_e1e2e3, Float c_e1e2e0, Float c_e2e3e0, Float c_e3e1e0) {

			set(plane_e1e2e3_e1e2e0_e2e3e0_e3e1e0, c_e1e2e3, c_e1e2e0, c_e2e3e0, c_e3e1e0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const plane &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__plane_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__plane_coordinates__, Float c_e1e2e3, Float c_e1e2e0, Float c_e2e3e0, Float c_e3e1e0);

		/// assign copy
		plane &operator=(const plane &arg1);

		/// assign general multivector
		plane &operator=(const mv &arg1);

		/// assign scalar
		plane &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2e3() const {
			return m_c[0];
		}
		inline Float e1e2e0() const {
			return m_c[1];
		}
		inline Float e2e3e0() const {
			return m_c[2];
		}
		inline Float e3e1e0() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__plane_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class plane 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline plane _plane(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)35), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return plane(arg1, 0);
	}
	/// from const specialization class:
	inline const plane &_plane(const plane &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline plane &_plane(plane &arg1) {
		return arg1;
	}
	/// from Float:
	inline plane _plane(plane::Float arg1) {
		return plane(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline plane like(const mv &what, const plane &example) {return _plane(what);}
	/// from const specialization class:
	inline const plane like(const plane &what, const plane &example) {return _plane(what);}
	/// from non-const specialization class:
	inline plane like(plane &what, const plane &example) {return _plane(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const plane & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const plane & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const plane & v) {
		return (float)0;
	}


	/// enum for the coordinates of planeAtInfinity 
	enum __planeAtInfinity_coordinates__ {planeAtInfinity_e1e2e3};

	class planeAtInfinity {
		// the friend classes of planeAtInfinity 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline planeAtInfinity() {

			set();
		}

		/// scalar constructor 
		inline planeAtInfinity(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> planeAtInfinity	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline planeAtInfinity(const planeAtInfinity &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline planeAtInfinity(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> planeAtInfinity	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline planeAtInfinity(__planeAtInfinity_coordinates__, const Float *coordinates) {

			set(planeAtInfinity_e1e2e3, coordinates);
		}

		/// coordinates constructor
		inline planeAtInfinity(__planeAtInfinity_coordinates__, Float c_e1e2e3) {

			set(planeAtInfinity_e1e2e3, c_e1e2e3);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const planeAtInfinity &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__planeAtInfinity_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__planeAtInfinity_coordinates__, Float c_e1e2e3);

		/// assign copy
		planeAtInfinity &operator=(const planeAtInfinity &arg1);

		/// assign general multivector
		planeAtInfinity &operator=(const mv &arg1);

		/// assign scalar
		planeAtInfinity &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2e3() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__planeAtInfinity_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class planeAtInfinity 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline planeAtInfinity _planeAtInfinity(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)36), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return planeAtInfinity(arg1, 0);
	}
	/// from const specialization class:
	inline const planeAtInfinity &_planeAtInfinity(const planeAtInfinity &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline planeAtInfinity &_planeAtInfinity(planeAtInfinity &arg1) {
		return arg1;
	}
	/// from Float:
	inline planeAtInfinity _planeAtInfinity(planeAtInfinity::Float arg1) {
		return planeAtInfinity(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline planeAtInfinity like(const mv &what, const planeAtInfinity &example) {return _planeAtInfinity(what);}
	/// from const specialization class:
	inline const planeAtInfinity like(const planeAtInfinity &what, const planeAtInfinity &example) {return _planeAtInfinity(what);}
	/// from non-const specialization class:
	inline planeAtInfinity like(planeAtInfinity &what, const planeAtInfinity &example) {return _planeAtInfinity(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const planeAtInfinity & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const planeAtInfinity & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const planeAtInfinity & v) {
		return (float)0;
	}


	/// enum for the coordinates of rotor 
	enum __rotor_coordinates__ {rotor_scalar_e1e2_e2e3_e3e1};

	class rotor {
		// the friend classes of rotor 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline rotor() {

			set();
		}

		/// scalar constructor 
		inline rotor(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> rotor	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline rotor(const rotor &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline rotor(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> rotor	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline rotor(__rotor_coordinates__, const Float *coordinates) {

			set(rotor_scalar_e1e2_e2e3_e3e1, coordinates);
		}

		/// coordinates constructor
		inline rotor(__rotor_coordinates__, Float c_scalar, Float c_e1e2, Float c_e2e3, Float c_e3e1) {

			set(rotor_scalar_e1e2_e2e3_e3e1, c_scalar, c_e1e2, c_e2e3, c_e3e1);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const rotor &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__rotor_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__rotor_coordinates__, Float c_scalar, Float c_e1e2, Float c_e2e3, Float c_e3e1);

		/// assign copy
		rotor &operator=(const rotor &arg1);

		/// assign general multivector
		rotor &operator=(const mv &arg1);

		/// assign scalar
		rotor &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[1];
		}
		inline Float e2e3() const {
			return m_c[2];
		}
		inline Float e3e1() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__rotor_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class rotor 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline rotor _rotor(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)37), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return rotor(arg1, 0);
	}
	/// from const specialization class:
	inline const rotor &_rotor(const rotor &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline rotor &_rotor(rotor &arg1) {
		return arg1;
	}
	/// from Float:
	inline rotor _rotor(rotor::Float arg1) {
		return rotor(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline rotor like(const mv &what, const rotor &example) {return _rotor(what);}
	/// from const specialization class:
	inline const rotor like(const rotor &what, const rotor &example) {return _rotor(what);}
	/// from non-const specialization class:
	inline rotor like(rotor &what, const rotor &example) {return _rotor(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const rotor & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const rotor & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const rotor & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of __e1_ct__ 
	enum ____e1_ct___coordinates__ {__e1_ct___e1f1_0};

	class __e1_ct__ {
		// the friend classes of __e1_ct__ 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline __e1_ct__() {

			set();
		}

		/// scalar constructor 
		inline __e1_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __e1_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __e1_ct__(const __e1_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __e1_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __e1_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __e1_ct__(____e1_ct___coordinates__, const Float *coordinates) {

			set(__e1_ct___e1f1_0, coordinates);
		}

		/// coordinates constructor
		inline __e1_ct__(____e1_ct___coordinates__) {

			set(__e1_ct___e1f1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __e1_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____e1_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____e1_ct___coordinates__);

		/// assign copy
		__e1_ct__ &operator=(const __e1_ct__ &arg1);

		/// assign general multivector
		__e1_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__e1_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e1f1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____e1_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __e1_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __e1_ct__ ___e1_ct__(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)38), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return __e1_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __e1_ct__ &___e1_ct__(const __e1_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __e1_ct__ &___e1_ct__(__e1_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __e1_ct__ ___e1_ct__(__e1_ct__::Float arg1) {
		return __e1_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __e1_ct__ like(const mv &what, const __e1_ct__ &example) {return ___e1_ct__(what);}
	/// from const specialization class:
	inline const __e1_ct__ like(const __e1_ct__ &what, const __e1_ct__ &example) {return ___e1_ct__(what);}
	/// from non-const specialization class:
	inline __e1_ct__ like(__e1_ct__ &what, const __e1_ct__ &example) {return ___e1_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __e1_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __e1_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __e1_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __e2_ct__ 
	enum ____e2_ct___coordinates__ {__e2_ct___e2f1_0};

	class __e2_ct__ {
		// the friend classes of __e2_ct__ 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline __e2_ct__() {

			set();
		}

		/// scalar constructor 
		inline __e2_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __e2_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __e2_ct__(const __e2_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __e2_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __e2_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __e2_ct__(____e2_ct___coordinates__, const Float *coordinates) {

			set(__e2_ct___e2f1_0, coordinates);
		}

		/// coordinates constructor
		inline __e2_ct__(____e2_ct___coordinates__) {

			set(__e2_ct___e2f1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __e2_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____e2_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____e2_ct___coordinates__);

		/// assign copy
		__e2_ct__ &operator=(const __e2_ct__ &arg1);

		/// assign general multivector
		__e2_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__e2_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e2f1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____e2_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __e2_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __e2_ct__ ___e2_ct__(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)39), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return __e2_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __e2_ct__ &___e2_ct__(const __e2_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __e2_ct__ &___e2_ct__(__e2_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __e2_ct__ ___e2_ct__(__e2_ct__::Float arg1) {
		return __e2_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __e2_ct__ like(const mv &what, const __e2_ct__ &example) {return ___e2_ct__(what);}
	/// from const specialization class:
	inline const __e2_ct__ like(const __e2_ct__ &what, const __e2_ct__ &example) {return ___e2_ct__(what);}
	/// from non-const specialization class:
	inline __e2_ct__ like(__e2_ct__ &what, const __e2_ct__ &example) {return ___e2_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __e2_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __e2_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __e2_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __e3_ct__ 
	enum ____e3_ct___coordinates__ {__e3_ct___e3f1_0};

	class __e3_ct__ {
		// the friend classes of __e3_ct__ 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline __e3_ct__() {

			set();
		}

		/// scalar constructor 
		inline __e3_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __e3_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __e3_ct__(const __e3_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __e3_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __e3_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __e3_ct__(____e3_ct___coordinates__, const Float *coordinates) {

			set(__e3_ct___e3f1_0, coordinates);
		}

		/// coordinates constructor
		inline __e3_ct__(____e3_ct___coordinates__) {

			set(__e3_ct___e3f1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __e3_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____e3_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____e3_ct___coordinates__);

		/// assign copy
		__e3_ct__ &operator=(const __e3_ct__ &arg1);

		/// assign general multivector
		__e3_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__e3_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e3f1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____e3_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __e3_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __e3_ct__ ___e3_ct__(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)40), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return __e3_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __e3_ct__ &___e3_ct__(const __e3_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __e3_ct__ &___e3_ct__(__e3_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __e3_ct__ ___e3_ct__(__e3_ct__::Float arg1) {
		return __e3_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __e3_ct__ like(const mv &what, const __e3_ct__ &example) {return ___e3_ct__(what);}
	/// from const specialization class:
	inline const __e3_ct__ like(const __e3_ct__ &what, const __e3_ct__ &example) {return ___e3_ct__(what);}
	/// from non-const specialization class:
	inline __e3_ct__ like(__e3_ct__ &what, const __e3_ct__ &example) {return ___e3_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __e3_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __e3_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __e3_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __e0_ct__ 
	enum ____e0_ct___coordinates__ {__e0_ct___e0f1_0};

	class __e0_ct__ {
		// the friend classes of __e0_ct__ 
		friend class __e0i_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline __e0_ct__() {

			set();
		}

		/// scalar constructor 
		inline __e0_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __e0_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __e0_ct__(const __e0_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __e0_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __e0_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __e0_ct__(____e0_ct___coordinates__, const Float *coordinates) {

			set(__e0_ct___e0f1_0, coordinates);
		}

		/// coordinates constructor
		inline __e0_ct__(____e0_ct___coordinates__) {

			set(__e0_ct___e0f1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __e0_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____e0_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____e0_ct___coordinates__);

		/// assign copy
		__e0_ct__ &operator=(const __e0_ct__ &arg1);

		/// assign general multivector
		__e0_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__e0_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e0f1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____e0_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __e0_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __e0_ct__ ___e0_ct__(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)41), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return __e0_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __e0_ct__ &___e0_ct__(const __e0_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __e0_ct__ &___e0_ct__(__e0_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __e0_ct__ ___e0_ct__(__e0_ct__::Float arg1) {
		return __e0_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __e0_ct__ like(const mv &what, const __e0_ct__ &example) {return ___e0_ct__(what);}
	/// from const specialization class:
	inline const __e0_ct__ like(const __e0_ct__ &what, const __e0_ct__ &example) {return ___e0_ct__(what);}
	/// from non-const specialization class:
	inline __e0_ct__ like(__e0_ct__ &what, const __e0_ct__ &example) {return ___e0_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __e0_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __e0_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __e0_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __e0i_ct__ 
	enum ____e0i_ct___coordinates__ {__e0i_ct___e0f1_0};

	class __e0i_ct__ {
		// the friend classes of __e0i_ct__ 
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline __e0i_ct__() {

			set();
		}

		/// scalar constructor 
		inline __e0i_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __e0i_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __e0i_ct__(const __e0i_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __e0i_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __e0i_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __e0i_ct__(____e0i_ct___coordinates__, const Float *coordinates) {

			set(__e0i_ct___e0f1_0, coordinates);
		}

		/// coordinates constructor
		inline __e0i_ct__(____e0i_ct___coordinates__) {

			set(__e0i_ct___e0f1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __e0i_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____e0i_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____e0i_ct___coordinates__);

		/// assign copy
		__e0i_ct__ &operator=(const __e0i_ct__ &arg1);

		/// assign general multivector
		__e0i_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__e0i_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e0f1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____e0i_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __e0i_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __e0i_ct__ ___e0i_ct__(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)42), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return __e0i_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __e0i_ct__ &___e0i_ct__(const __e0i_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __e0i_ct__ &___e0i_ct__(__e0i_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __e0i_ct__ ___e0i_ct__(__e0i_ct__::Float arg1) {
		return __e0i_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __e0i_ct__ like(const mv &what, const __e0i_ct__ &example) {return ___e0i_ct__(what);}
	/// from const specialization class:
	inline const __e0i_ct__ like(const __e0i_ct__ &what, const __e0i_ct__ &example) {return ___e0i_ct__(what);}
	/// from non-const specialization class:
	inline __e0i_ct__ like(__e0i_ct__ &what, const __e0i_ct__ &example) {return ___e0i_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __e0i_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __e0i_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __e0i_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __I4i_ct__ 
	enum ____I4i_ct___coordinates__ {__I4i_ct___e1e2e3e0f1_0};

	class __I4i_ct__ {
		// the friend classes of __I4i_ct__ 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// zero constructor
		inline __I4i_ct__() {

			set();
		}

		/// scalar constructor 
		inline __I4i_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __I4i_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __I4i_ct__(const __I4i_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __I4i_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __I4i_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __I4i_ct__(____I4i_ct___coordinates__, const Float *coordinates) {

			set(__I4i_ct___e1e2e3e0f1_0, coordinates);
		}

		/// coordinates constructor
		inline __I4i_ct__(____I4i_ct___coordinates__) {

			set(__I4i_ct___e1e2e3e0f1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __I4i_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____I4i_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____I4i_ct___coordinates__);

		/// assign copy
		__I4i_ct__ &operator=(const __I4i_ct__ &arg1);

		/// assign general multivector
		__I4i_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__I4i_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e1e2e3e0f1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____I4i_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::h3ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::h3ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __I4i_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __I4i_ct__ ___I4i_ct__(const mv &arg1) {
		/* start of profiling instrumentation code */;
		unsigned short __profileArgs__[]  = {arg1.type()};
		g2Profiling::profile(((unsigned int)43), ((unsigned short)-1), ((unsigned short)1), __profileArgs__, (unsigned short)0, NULL);
		/* end of profiling instrumentation code */;
		return __I4i_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __I4i_ct__ &___I4i_ct__(const __I4i_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __I4i_ct__ &___I4i_ct__(__I4i_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __I4i_ct__ ___I4i_ct__(__I4i_ct__::Float arg1) {
		return __I4i_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __I4i_ct__ like(const mv &what, const __I4i_ct__ &example) {return ___I4i_ct__(what);}
	/// from const specialization class:
	inline const __I4i_ct__ like(const __I4i_ct__ &what, const __I4i_ct__ &example) {return ___I4i_ct__(what);}
	/// from non-const specialization class:
	inline __I4i_ct__ like(__I4i_ct__ &what, const __I4i_ct__ &example) {return ___I4i_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __I4i_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __I4i_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __I4i_ct__ & v) {
		return (float)0;
	}


	class om {
		// the friend classes of om 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class omPoint;
		friend class e2_t;

		public:
			typedef float Float;

		/// identity 'I' constructor
		inline om() {
			set();
		}

		/// copy constructor (MUST PASS BY REFERENCE!)
		inline om(const om &arg1) {
			set(arg1);
		}

		/// scalar constructor (creates scalar * 'I' outermorphism)
		inline om(Float scalar) {
			set(scalar);
		}

		/// pointer to coordinates constructor
		inline om(const Float *coordinates) {
			set(coordinates);
		}

		/// pointer to coordinates/transpose constructor
		inline om(const Float *coordinates, bool transpose) {
			set(coordinates, transpose);
		}

		/// constructor from basis vectors array
		inline om(const point *vectors) {
			set(vectors);
		}

		/// constructor from basis vectors 
		inline om(const point & image_of_e1, const point & image_of_e2, const point & image_of_e3, const point & image_of_e0) {
			set(image_of_e1, image_of_e2, image_of_e3, image_of_e0);
		}

		/// init from specialization constructor
		inline om(const omPoint &arg1) {
			set(arg1);
		}

		/// set to identity 'I'
		void set();

		/// set to copy
		void set(const om &arg1);

		/// set to scalar (creates scalar * 'I' outermorphism)
		void set(Float scalarVal);

		/// set to coordinates 
		void set(const Float *coordinates);

		/// set to coordinates/transpose 
		void set(const Float *coordinates, bool transpose);

		/// set from basis vectors array
		void set(const point *vectors);

		/// set from basis vectors 
		void set(
			const point & image_of_e1, const point & image_of_e2, const point & image_of_e3, const point & image_of_e0);

		/// set to specialization
		void set(const omPoint &arg1);

		/// assign copy
		om &operator=(const om &arg1);

		/// assign scalar (creates scalar * 'I' outermorphism)
		om &operator=(Float scalarVal);

		/// assign specialization:
		om &operator=(const omPoint &arg1);


		Float m_c[69]; ///< coordinate storage



		omType m_type; /// type (for profiling)
		inline omType type() const {return m_type;}
		inline void type(omType t) {m_type = t;}


	}; // end of class om



	class omPoint {
		// the friend classes of omPoint 
		friend class __e0i_ct__;
		friend class __e0_ct__;
		friend class lineAtInfinity;
		friend class mv;
		friend class __e1_ct__;
		friend class __e2_ct__;
		friend class normalizedPoint;
		friend class e0_t;
		friend class e3_t;
		friend class scalar;
		friend class __e3_ct__;
		friend class __I4i_ct__;
		friend class bivector;
		friend class vector;
		friend class om;
		friend class e1_t;
		friend class rotor;
		friend class line;
		friend class plane;
		friend class planeAtInfinity;
		friend class point;
		friend class e2_t;

		public:
			typedef float Float;

		/// identity 'I' constructor
		inline omPoint() {
			set();
		}

		/// copy constructor (MUST PASS BY REFERENCE!)
		inline omPoint(const omPoint &arg1) {
			set(arg1);
		}

		/// init from genenal OM constructor
		inline omPoint(const om & arg1) {
			set(arg1);
		}

		/// scalar constructor (creates scalar * identity outermorphism)
		inline omPoint(Float scalar) {
			set(scalar);
		}

		/// pointer to coordinates constructor
		inline omPoint(const Float *coordinates) {
			set(coordinates);
		}
		/// pointer to coordinates/transpose constructor
		inline omPoint(const Float *coordinates, bool transpose) {
			set(coordinates, transpose);
		}

		/// constructor from basis vectors array
		inline omPoint(const point *vectors) {
			set(vectors);
		}


		/// images of basis vectors constructor
		inline omPoint(const point & image_of_e1, const point & image_of_e2, const point & image_of_e3, const point & image_of_e0) {
			set(image_of_e1, image_of_e2, image_of_e3, image_of_e0);
		}



		/// set to identity 'I'
		void set();

		/// set to copy
		void set(const omPoint &arg1);

		/// set to genenal OM
		void set(const om & arg1);

		/// set to scalar (creates scalar * identity outermorphism)
		void set(Float scalar);

		/// pointer to coordinates constructor
		void set(const Float *coordinates);

		/// pointer to coordinates/transpose constructor
		void set(const Float *coordinates, bool transpose);

		/// set to basis vectors array
		void set(const point *vectors);



		/// set to images of basis vectors
		void set(const point & image_of_e1, const point & image_of_e2, const point & image_of_e3, const point & image_of_e0);




		/// assign copy
		omPoint &operator=(const omPoint &arg1);

		/// assign genenal OM
		omPoint &operator=(const om & arg1);

		/// assign scalar (creates scalar * 'I' outermorphism)
		omPoint &operator=(Float scalarVal);


		Float m_c[16]; ///< coordinate storage

	}; // end of class omPoint

	// multivector type
	class mvType : public mvTypeBase {
		public:

			inline mvType() {
		}

		/** Creates a new instance of MultivectorInfo */
		inline mvType(const mv &X) {
			init(X, (mv::Float)0.0);
		}

		/** Creates a new instance of MultivectorInfo */
		inline mvType(const mv &X, mv::Float epsilon) {
			init(X, epsilon);
		}

		inline mvType(const mvType &T) {
		}


		void init(const mv &X, mv::Float epsilon);

		std::string toString() const;

		protected:
			void init(const mv &X, mv::Float epsilon, bool useAlgebraMetric, int guCnt);
	};





	// extra underscore constructors from profile:


	extern __I4i_ct__ I4i;
	extern __e0_ct__ e0;
	extern __e3_ct__ e3;
	extern __e1_ct__ e1;
	extern __e2_ct__ e2;
	extern __I4i_ct__ I4;
	extern __e0i_ct__ e0i;
	mv lcont(const mv& x, const mv& y);
	scalar scp(const mv& x, const mv& y);
	mv gp(const mv& x, const mv& y);
	mv op(const mv& x, const mv& y);
	mv add(const mv& x, const mv& y);
	mv subtract(const mv& x, const mv& y);
	scalar norm_e2(const mv& x);
	scalar norm_e(const mv& x);
	mv unit_e(const mv& x);
	scalar norm_r2(const mv& x);
	scalar norm_r(const mv& x);
	mv unit_r(const mv& x);
	mv reverse(const mv& x);
	mv negate(const mv& x);
	mv dual(const mv& x);
	mv undual(const mv& x);
	mv inverse(const mv& x);
	mv apply_om(const om& x, const mv& y);
	mv gradeInvolution(const mv& x);
	namespace __G2_GENERATED__ {
		void set(om& __x__, const point& __image_of_e1__, const point& __image_of_e2__, const point& __image_of_e3__, const point& __image_of_e0__);
		void set(om& __x__, const omPoint& __y__);
		inline void set(omPoint& __x__, const point& __image_of_e1__, const point& __image_of_e2__, const point& __image_of_e3__, const point& __image_of_e0__);
		void set(omPoint& __x__, const om& __y__);
	} /* end of namespace __G2_GENERATED__ */
	inline mv operator+=(mv& arg1, const mv& arg2);
	inline e1_t operator+=(e1_t& arg1, const mv& arg2);
	inline e2_t operator+=(e2_t& arg1, const mv& arg2);
	inline e3_t operator+=(e3_t& arg1, const mv& arg2);
	inline e0_t operator+=(e0_t& arg1, const mv& arg2);
	inline scalar operator+=(scalar& arg1, const mv& arg2);
	inline vector operator+=(vector& arg1, const mv& arg2);
	inline point operator+=(point& arg1, const mv& arg2);
	inline normalizedPoint operator+=(normalizedPoint& arg1, const mv& arg2);
	inline line operator+=(line& arg1, const mv& arg2);
	inline lineAtInfinity operator+=(lineAtInfinity& arg1, const mv& arg2);
	inline bivector operator+=(bivector& arg1, const mv& arg2);
	inline plane operator+=(plane& arg1, const mv& arg2);
	inline planeAtInfinity operator+=(planeAtInfinity& arg1, const mv& arg2);
	inline rotor operator+=(rotor& arg1, const mv& arg2);
	inline __e1_ct__ operator+=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator+=(__e2_ct__& arg1, const mv& arg2);
	inline __e3_ct__ operator+=(__e3_ct__& arg1, const mv& arg2);
	inline __e0_ct__ operator+=(__e0_ct__& arg1, const mv& arg2);
	inline __e0i_ct__ operator+=(__e0i_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator+=(__I4i_ct__& arg1, const mv& arg2);
	inline mv operator+(const mv& arg1, const mv& arg2);
	inline mv operator-=(mv& arg1, const mv& arg2);
	inline e1_t operator-=(e1_t& arg1, const mv& arg2);
	inline e2_t operator-=(e2_t& arg1, const mv& arg2);
	inline e3_t operator-=(e3_t& arg1, const mv& arg2);
	inline e0_t operator-=(e0_t& arg1, const mv& arg2);
	inline scalar operator-=(scalar& arg1, const mv& arg2);
	inline vector operator-=(vector& arg1, const mv& arg2);
	inline point operator-=(point& arg1, const mv& arg2);
	inline normalizedPoint operator-=(normalizedPoint& arg1, const mv& arg2);
	inline line operator-=(line& arg1, const mv& arg2);
	inline lineAtInfinity operator-=(lineAtInfinity& arg1, const mv& arg2);
	inline bivector operator-=(bivector& arg1, const mv& arg2);
	inline plane operator-=(plane& arg1, const mv& arg2);
	inline planeAtInfinity operator-=(planeAtInfinity& arg1, const mv& arg2);
	inline rotor operator-=(rotor& arg1, const mv& arg2);
	inline __e1_ct__ operator-=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator-=(__e2_ct__& arg1, const mv& arg2);
	inline __e3_ct__ operator-=(__e3_ct__& arg1, const mv& arg2);
	inline __e0_ct__ operator-=(__e0_ct__& arg1, const mv& arg2);
	inline __e0i_ct__ operator-=(__e0i_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator-=(__I4i_ct__& arg1, const mv& arg2);
	inline mv operator-(const mv& arg1, const mv& arg2);
	inline mv operator-(const mv& arg1);
	inline mv operator%=(mv& arg1, const mv& arg2);
	inline e1_t operator%=(e1_t& arg1, const mv& arg2);
	inline e2_t operator%=(e2_t& arg1, const mv& arg2);
	inline e3_t operator%=(e3_t& arg1, const mv& arg2);
	inline e0_t operator%=(e0_t& arg1, const mv& arg2);
	inline scalar operator%=(scalar& arg1, const mv& arg2);
	inline vector operator%=(vector& arg1, const mv& arg2);
	inline point operator%=(point& arg1, const mv& arg2);
	inline normalizedPoint operator%=(normalizedPoint& arg1, const mv& arg2);
	inline line operator%=(line& arg1, const mv& arg2);
	inline lineAtInfinity operator%=(lineAtInfinity& arg1, const mv& arg2);
	inline bivector operator%=(bivector& arg1, const mv& arg2);
	inline plane operator%=(plane& arg1, const mv& arg2);
	inline planeAtInfinity operator%=(planeAtInfinity& arg1, const mv& arg2);
	inline rotor operator%=(rotor& arg1, const mv& arg2);
	inline __e1_ct__ operator%=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator%=(__e2_ct__& arg1, const mv& arg2);
	inline __e3_ct__ operator%=(__e3_ct__& arg1, const mv& arg2);
	inline __e0_ct__ operator%=(__e0_ct__& arg1, const mv& arg2);
	inline __e0i_ct__ operator%=(__e0i_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator%=(__I4i_ct__& arg1, const mv& arg2);
	inline scalar operator%(const mv& arg1, const mv& arg2);
	inline mv operator^=(mv& arg1, const mv& arg2);
	inline e1_t operator^=(e1_t& arg1, const mv& arg2);
	inline e2_t operator^=(e2_t& arg1, const mv& arg2);
	inline e3_t operator^=(e3_t& arg1, const mv& arg2);
	inline e0_t operator^=(e0_t& arg1, const mv& arg2);
	inline scalar operator^=(scalar& arg1, const mv& arg2);
	inline vector operator^=(vector& arg1, const mv& arg2);
	inline point operator^=(point& arg1, const mv& arg2);
	inline normalizedPoint operator^=(normalizedPoint& arg1, const mv& arg2);
	inline line operator^=(line& arg1, const mv& arg2);
	inline lineAtInfinity operator^=(lineAtInfinity& arg1, const mv& arg2);
	inline bivector operator^=(bivector& arg1, const mv& arg2);
	inline plane operator^=(plane& arg1, const mv& arg2);
	inline planeAtInfinity operator^=(planeAtInfinity& arg1, const mv& arg2);
	inline rotor operator^=(rotor& arg1, const mv& arg2);
	inline __e1_ct__ operator^=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator^=(__e2_ct__& arg1, const mv& arg2);
	inline __e3_ct__ operator^=(__e3_ct__& arg1, const mv& arg2);
	inline __e0_ct__ operator^=(__e0_ct__& arg1, const mv& arg2);
	inline __e0i_ct__ operator^=(__e0i_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator^=(__I4i_ct__& arg1, const mv& arg2);
	inline mv operator^(const mv& arg1, const mv& arg2);
	inline mv operator*=(mv& arg1, const mv& arg2);
	inline e1_t operator*=(e1_t& arg1, const mv& arg2);
	inline e2_t operator*=(e2_t& arg1, const mv& arg2);
	inline e3_t operator*=(e3_t& arg1, const mv& arg2);
	inline e0_t operator*=(e0_t& arg1, const mv& arg2);
	inline scalar operator*=(scalar& arg1, const mv& arg2);
	inline vector operator*=(vector& arg1, const mv& arg2);
	inline point operator*=(point& arg1, const mv& arg2);
	inline normalizedPoint operator*=(normalizedPoint& arg1, const mv& arg2);
	inline line operator*=(line& arg1, const mv& arg2);
	inline lineAtInfinity operator*=(lineAtInfinity& arg1, const mv& arg2);
	inline bivector operator*=(bivector& arg1, const mv& arg2);
	inline plane operator*=(plane& arg1, const mv& arg2);
	inline planeAtInfinity operator*=(planeAtInfinity& arg1, const mv& arg2);
	inline rotor operator*=(rotor& arg1, const mv& arg2);
	inline __e1_ct__ operator*=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator*=(__e2_ct__& arg1, const mv& arg2);
	inline __e3_ct__ operator*=(__e3_ct__& arg1, const mv& arg2);
	inline __e0_ct__ operator*=(__e0_ct__& arg1, const mv& arg2);
	inline __e0i_ct__ operator*=(__e0i_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator*=(__I4i_ct__& arg1, const mv& arg2);
	inline mv operator*(const mv& arg1, const mv& arg2);
	inline mv operator<<=(mv& arg1, const mv& arg2);
	inline e1_t operator<<=(e1_t& arg1, const mv& arg2);
	inline e2_t operator<<=(e2_t& arg1, const mv& arg2);
	inline e3_t operator<<=(e3_t& arg1, const mv& arg2);
	inline e0_t operator<<=(e0_t& arg1, const mv& arg2);
	inline scalar operator<<=(scalar& arg1, const mv& arg2);
	inline vector operator<<=(vector& arg1, const mv& arg2);
	inline point operator<<=(point& arg1, const mv& arg2);
	inline normalizedPoint operator<<=(normalizedPoint& arg1, const mv& arg2);
	inline line operator<<=(line& arg1, const mv& arg2);
	inline lineAtInfinity operator<<=(lineAtInfinity& arg1, const mv& arg2);
	inline bivector operator<<=(bivector& arg1, const mv& arg2);
	inline plane operator<<=(plane& arg1, const mv& arg2);
	inline planeAtInfinity operator<<=(planeAtInfinity& arg1, const mv& arg2);
	inline rotor operator<<=(rotor& arg1, const mv& arg2);
	inline __e1_ct__ operator<<=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator<<=(__e2_ct__& arg1, const mv& arg2);
	inline __e3_ct__ operator<<=(__e3_ct__& arg1, const mv& arg2);
	inline __e0_ct__ operator<<=(__e0_ct__& arg1, const mv& arg2);
	inline __e0i_ct__ operator<<=(__e0i_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator<<=(__I4i_ct__& arg1, const mv& arg2);
	inline mv operator<<(const mv& arg1, const mv& arg2);
	inline mv operator*(const mv& arg1);
	inline mv operator!(const mv& arg1);
	inline mv operator~(const mv& arg1);














	// set to zero
	inline void e1_t::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void e1_t::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void e1_t::set(const e1_t &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void e1_t::set(__e1_t_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void e1_t::set(__e1_t_coordinates__, Float c_e1) {
		// set coordinates
		m_c[0] = c_e1;

	}





	// assign copy
	inline e1_t &e1_t::operator=(const e1_t &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline e1_t &e1_t::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline e1_t &e1_t::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void e2_t::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void e2_t::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void e2_t::set(const e2_t &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void e2_t::set(__e2_t_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void e2_t::set(__e2_t_coordinates__, Float c_e2) {
		// set coordinates
		m_c[0] = c_e2;

	}





	// assign copy
	inline e2_t &e2_t::operator=(const e2_t &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline e2_t &e2_t::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline e2_t &e2_t::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void e3_t::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void e3_t::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void e3_t::set(const e3_t &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void e3_t::set(__e3_t_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void e3_t::set(__e3_t_coordinates__, Float c_e3) {
		// set coordinates
		m_c[0] = c_e3;

	}





	// assign copy
	inline e3_t &e3_t::operator=(const e3_t &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline e3_t &e3_t::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline e3_t &e3_t::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void e0_t::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void e0_t::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void e0_t::set(const e0_t &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void e0_t::set(__e0_t_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void e0_t::set(__e0_t_coordinates__, Float c_e0) {
		// set coordinates
		m_c[0] = c_e0;

	}





	// assign copy
	inline e0_t &e0_t::operator=(const e0_t &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline e0_t &e0_t::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline e0_t &e0_t::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void scalar::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void scalar::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;

	}


	// set to copy
	inline void scalar::set(const scalar &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void scalar::set(__scalar_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void scalar::set(__scalar_coordinates__, Float c_scalar) {
		// set coordinates
		m_c[0] = c_scalar;

	}





	// assign copy
	inline scalar &scalar::operator=(const scalar &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline scalar &scalar::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline scalar &scalar::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void vector::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void vector::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void vector::set(const vector &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void vector::set(__vector_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void vector::set(__vector_coordinates__, Float c_e1, Float c_e2, Float c_e3) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;
		m_c[2] = c_e3;

	}





	// assign copy
	inline vector &vector::operator=(const vector &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline vector &vector::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline vector &vector::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void point::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void point::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void point::set(const point &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void point::set(__point_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void point::set(__point_coordinates__, Float c_e1, Float c_e2, Float c_e3, Float c_e0) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;
		m_c[2] = c_e3;
		m_c[3] = c_e0;

	}





	// assign copy
	inline point &point::operator=(const point &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline point &point::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline point &point::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void normalizedPoint::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void normalizedPoint::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void normalizedPoint::set(const normalizedPoint &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void normalizedPoint::set(__normalizedPoint_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void normalizedPoint::set(__normalizedPoint_coordinates__, Float c_e1, Float c_e2, Float c_e3) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;
		m_c[2] = c_e3;

	}





	// assign copy
	inline normalizedPoint &normalizedPoint::operator=(const normalizedPoint &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline normalizedPoint &normalizedPoint::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline normalizedPoint &normalizedPoint::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void line::set() {
		// set coordinates to 0
		mv_zero(m_c, 6);

	}

	// set to scalar 
	inline void line::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;

	}


	// set to copy
	inline void line::set(const line &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 6);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];

	}

	// set to pointer to coordinates
	inline void line::set(__line_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 6);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];

	}

	// set to 'coordinates specified' 
	inline void line::set(__line_coordinates__, Float c_e1e2, Float c_e2e3, Float c_e3e1, Float c_e1e0, Float c_e2e0, Float c_e3e0) {
		// set coordinates
		m_c[0] = c_e1e2;
		m_c[1] = c_e2e3;
		m_c[2] = c_e3e1;
		m_c[3] = c_e1e0;
		m_c[4] = c_e2e0;
		m_c[5] = c_e3e0;

	}





	// assign copy
	inline line &line::operator=(const line &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline line &line::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline line &line::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void lineAtInfinity::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void lineAtInfinity::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void lineAtInfinity::set(const lineAtInfinity &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void lineAtInfinity::set(__lineAtInfinity_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void lineAtInfinity::set(__lineAtInfinity_coordinates__, Float c_e1e2, Float c_e2e3, Float c_e3e1) {
		// set coordinates
		m_c[0] = c_e1e2;
		m_c[1] = c_e2e3;
		m_c[2] = c_e3e1;

	}





	// assign copy
	inline lineAtInfinity &lineAtInfinity::operator=(const lineAtInfinity &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline lineAtInfinity &lineAtInfinity::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline lineAtInfinity &lineAtInfinity::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void bivector::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void bivector::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void bivector::set(const bivector &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void bivector::set(__bivector_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void bivector::set(__bivector_coordinates__, Float c_e1e2, Float c_e2e3, Float c_e3e1) {
		// set coordinates
		m_c[0] = c_e1e2;
		m_c[1] = c_e2e3;
		m_c[2] = c_e3e1;

	}





	// assign copy
	inline bivector &bivector::operator=(const bivector &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline bivector &bivector::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline bivector &bivector::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void plane::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void plane::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void plane::set(const plane &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void plane::set(__plane_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void plane::set(__plane_coordinates__, Float c_e1e2e3, Float c_e1e2e0, Float c_e2e3e0, Float c_e3e1e0) {
		// set coordinates
		m_c[0] = c_e1e2e3;
		m_c[1] = c_e1e2e0;
		m_c[2] = c_e2e3e0;
		m_c[3] = c_e3e1e0;

	}





	// assign copy
	inline plane &plane::operator=(const plane &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline plane &plane::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline plane &plane::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void planeAtInfinity::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void planeAtInfinity::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void planeAtInfinity::set(const planeAtInfinity &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void planeAtInfinity::set(__planeAtInfinity_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void planeAtInfinity::set(__planeAtInfinity_coordinates__, Float c_e1e2e3) {
		// set coordinates
		m_c[0] = c_e1e2e3;

	}





	// assign copy
	inline planeAtInfinity &planeAtInfinity::operator=(const planeAtInfinity &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline planeAtInfinity &planeAtInfinity::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline planeAtInfinity &planeAtInfinity::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void rotor::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void rotor::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void rotor::set(const rotor &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void rotor::set(__rotor_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void rotor::set(__rotor_coordinates__, Float c_scalar, Float c_e1e2, Float c_e2e3, Float c_e3e1) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_e1e2;
		m_c[2] = c_e2e3;
		m_c[3] = c_e3e1;

	}





	// assign copy
	inline rotor &rotor::operator=(const rotor &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline rotor &rotor::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline rotor &rotor::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __e1_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __e1_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __e1_ct__::set(const __e1_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __e1_ct__::set(____e1_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __e1_ct__::set(____e1_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __e1_ct__ &__e1_ct__::operator=(const __e1_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __e1_ct__ &__e1_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __e1_ct__ &__e1_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __e2_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __e2_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __e2_ct__::set(const __e2_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __e2_ct__::set(____e2_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __e2_ct__::set(____e2_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __e2_ct__ &__e2_ct__::operator=(const __e2_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __e2_ct__ &__e2_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __e2_ct__ &__e2_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __e3_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __e3_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __e3_ct__::set(const __e3_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __e3_ct__::set(____e3_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __e3_ct__::set(____e3_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __e3_ct__ &__e3_ct__::operator=(const __e3_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __e3_ct__ &__e3_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __e3_ct__ &__e3_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __e0_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __e0_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __e0_ct__::set(const __e0_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __e0_ct__::set(____e0_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __e0_ct__::set(____e0_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __e0_ct__ &__e0_ct__::operator=(const __e0_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __e0_ct__ &__e0_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __e0_ct__ &__e0_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __e0i_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __e0i_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __e0i_ct__::set(const __e0i_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __e0i_ct__::set(____e0i_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __e0i_ct__::set(____e0i_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __e0i_ct__ &__e0i_ct__::operator=(const __e0i_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __e0i_ct__ &__e0i_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __e0i_ct__ &__e0i_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __I4i_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __I4i_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __I4i_ct__::set(const __I4i_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __I4i_ct__::set(____I4i_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __I4i_ct__::set(____I4i_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __I4i_ct__ &__I4i_ct__::operator=(const __I4i_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __I4i_ct__ &__I4i_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __I4i_ct__ &__I4i_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}










	// set to identity 'I'
	inline void omPoint::set() {
		// simplify forward call to set(scalar)
		set(1.0);
	}

	// set to copy
	inline void omPoint::set(const omPoint &arg1) {
		//mv_memcpy(m_c, arg1.m_c, 16);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];
		m_c[6] = arg1.m_c[6];
		m_c[7] = arg1.m_c[7];
		m_c[8] = arg1.m_c[8];
		m_c[9] = arg1.m_c[9];
		m_c[10] = arg1.m_c[10];
		m_c[11] = arg1.m_c[11];
		m_c[12] = arg1.m_c[12];
		m_c[13] = arg1.m_c[13];
		m_c[14] = arg1.m_c[14];
		m_c[15] = arg1.m_c[15];
	}

	// set to scalar
	inline void omPoint::set(Float scalarVal) {
		h3ga::__G2_GENERATED__::set(*this, point(point_e1_e2_e3_e0, scalarVal, (Float)0, (Float)0, (Float)0), point(point_e1_e2_e3_e0, (Float)0, scalarVal, (Float)0, (Float)0), point(point_e1_e2_e3_e0, (Float)0, (Float)0, scalarVal, (Float)0), point(point_e1_e2_e3_e0, (Float)0, (Float)0, (Float)0, scalarVal));
	}


	// set to coordinates 
	inline void omPoint::set(const Float *coordinates) {
		//	mv_memcpy(m_c, coordinates, 16);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];
		m_c[6] = coordinates[6];
		m_c[7] = coordinates[7];
		m_c[8] = coordinates[8];
		m_c[9] = coordinates[9];
		m_c[10] = coordinates[10];
		m_c[11] = coordinates[11];
		m_c[12] = coordinates[12];
		m_c[13] = coordinates[13];
		m_c[14] = coordinates[14];
		m_c[15] = coordinates[15];
	}

	// set to general OM
	inline void omPoint::set(const om& arg1) {
		h3ga::__G2_GENERATED__::set(*this, arg1);
	}

	// set by coordinates, transpose
	inline void omPoint::set(const Float *coordinates, bool transpose) {
		if (transpose) {
			m_c[0] = coordinates[0];
			m_c[4] = coordinates[1];
			m_c[8] = coordinates[2];
			m_c[12] = coordinates[3];
			m_c[1] = coordinates[4];
			m_c[5] = coordinates[5];
			m_c[9] = coordinates[6];
			m_c[13] = coordinates[7];
			m_c[2] = coordinates[8];
			m_c[6] = coordinates[9];
			m_c[10] = coordinates[10];
			m_c[14] = coordinates[11];
			m_c[3] = coordinates[12];
			m_c[7] = coordinates[13];
			m_c[11] = coordinates[14];
			m_c[15] = coordinates[15];
		}
		else set(coordinates);
	}


	// set to basis vectors array
	inline void omPoint::set(const point *vectors) {
		h3ga::__G2_GENERATED__::set(*this, vectors[0], vectors[1], vectors[2], vectors[3]);
	}




	// set from images of basis vectors 
	inline void omPoint::set(const point & image_of_e1, const point & image_of_e2, const point & image_of_e3, const point & image_of_e0) {
		h3ga::__G2_GENERATED__::set(*this, image_of_e1, image_of_e2, image_of_e3, image_of_e0);
	}






	/// assign copy
	inline omPoint &omPoint::operator=(const omPoint &arg1) {
		set(arg1);
		return *this;
	}

	/// assign genenal OM
	inline omPoint &omPoint::operator=(const om & arg1) {
		set(arg1);
		return *this;
	}

	/// assign scalar (creates scalar * 'I' outermorphism)
	inline omPoint &omPoint::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}







	inline mv operator+=(mv& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline e1_t operator+=(e1_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline e2_t operator+=(e2_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline e3_t operator+=(e3_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline e0_t operator+=(e0_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline scalar operator+=(scalar& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline vector operator+=(vector& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline point operator+=(point& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator+=(normalizedPoint& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline line operator+=(line& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline lineAtInfinity operator+=(lineAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline bivector operator+=(bivector& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline plane operator+=(plane& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline planeAtInfinity operator+=(planeAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline rotor operator+=(rotor& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator+=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator+=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline __e3_ct__ operator+=(__e3_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline __e0_ct__ operator+=(__e0_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline __e0i_ct__ operator+=(__e0i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator+=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::add(arg1, arg2));
		return arg1;
	}
	inline mv operator+(const mv& arg1, const mv& arg2) {
		return ::h3ga::add(arg1, arg2);
	}
	inline mv operator-=(mv& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline e1_t operator-=(e1_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline e2_t operator-=(e2_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline e3_t operator-=(e3_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline e0_t operator-=(e0_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline scalar operator-=(scalar& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline vector operator-=(vector& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline point operator-=(point& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator-=(normalizedPoint& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline line operator-=(line& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline lineAtInfinity operator-=(lineAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline bivector operator-=(bivector& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline plane operator-=(plane& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline planeAtInfinity operator-=(planeAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline rotor operator-=(rotor& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator-=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator-=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e3_ct__ operator-=(__e3_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e0_ct__ operator-=(__e0_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e0i_ct__ operator-=(__e0i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator-=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::subtract(arg1, arg2));
		return arg1;
	}
	inline mv operator-(const mv& arg1, const mv& arg2) {
		return ::h3ga::subtract(arg1, arg2);
	}
	inline mv operator-(const mv& arg1) {
		return ::h3ga::negate(arg1);
	}
	inline mv operator%=(mv& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline e1_t operator%=(e1_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline e2_t operator%=(e2_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline e3_t operator%=(e3_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline e0_t operator%=(e0_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline scalar operator%=(scalar& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline vector operator%=(vector& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline point operator%=(point& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator%=(normalizedPoint& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline line operator%=(line& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline lineAtInfinity operator%=(lineAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline bivector operator%=(bivector& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline plane operator%=(plane& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline planeAtInfinity operator%=(planeAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline rotor operator%=(rotor& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator%=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator%=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e3_ct__ operator%=(__e3_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e0_ct__ operator%=(__e0_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e0i_ct__ operator%=(__e0i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator%=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::scp(arg1, arg2));
		return arg1;
	}
	inline scalar operator%(const mv& arg1, const mv& arg2) {
		return ::h3ga::scp(arg1, arg2);
	}
	inline mv operator^=(mv& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline e1_t operator^=(e1_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline e2_t operator^=(e2_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline e3_t operator^=(e3_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline e0_t operator^=(e0_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline scalar operator^=(scalar& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline vector operator^=(vector& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline point operator^=(point& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator^=(normalizedPoint& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline line operator^=(line& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline lineAtInfinity operator^=(lineAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline bivector operator^=(bivector& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline plane operator^=(plane& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline planeAtInfinity operator^=(planeAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline rotor operator^=(rotor& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator^=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator^=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline __e3_ct__ operator^=(__e3_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline __e0_ct__ operator^=(__e0_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline __e0i_ct__ operator^=(__e0i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator^=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::op(arg1, arg2));
		return arg1;
	}
	inline mv operator^(const mv& arg1, const mv& arg2) {
		return ::h3ga::op(arg1, arg2);
	}
	inline mv operator*=(mv& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline e1_t operator*=(e1_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline e2_t operator*=(e2_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline e3_t operator*=(e3_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline e0_t operator*=(e0_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline vector operator*=(vector& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline point operator*=(point& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator*=(normalizedPoint& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline line operator*=(line& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline lineAtInfinity operator*=(lineAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline bivector operator*=(bivector& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline plane operator*=(plane& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline planeAtInfinity operator*=(planeAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline rotor operator*=(rotor& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator*=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator*=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e3_ct__ operator*=(__e3_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e0_ct__ operator*=(__e0_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e0i_ct__ operator*=(__e0i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator*=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::gp(arg1, arg2));
		return arg1;
	}
	inline mv operator*(const mv& arg1, const mv& arg2) {
		return ::h3ga::gp(arg1, arg2);
	}
	inline mv operator<<=(mv& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline e1_t operator<<=(e1_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline e2_t operator<<=(e2_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline e3_t operator<<=(e3_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline e0_t operator<<=(e0_t& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline scalar operator<<=(scalar& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline vector operator<<=(vector& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline point operator<<=(point& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator<<=(normalizedPoint& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline line operator<<=(line& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline lineAtInfinity operator<<=(lineAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline bivector operator<<=(bivector& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline plane operator<<=(plane& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline planeAtInfinity operator<<=(planeAtInfinity& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline rotor operator<<=(rotor& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator<<=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator<<=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e3_ct__ operator<<=(__e3_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e0_ct__ operator<<=(__e0_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e0i_ct__ operator<<=(__e0i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator<<=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::h3ga::lcont(arg1, arg2));
		return arg1;
	}
	inline mv operator<<(const mv& arg1, const mv& arg2) {
		return ::h3ga::lcont(arg1, arg2);
	}
	inline mv operator*(const mv& arg1) {
		return ::h3ga::dual(arg1);
	}
	inline mv operator!(const mv& arg1) {
		return ::h3ga::inverse(arg1);
	}
	inline mv operator~(const mv& arg1) {
		return ::h3ga::reverse(arg1);
	}


	// G2 functions:
	namespace __G2_GENERATED__ {
		inline void set(omPoint& __x__, const point& __image_of_e1__, const point& __image_of_e2__, const point& __image_of_e3__, const point& __image_of_e0__) {
			__x__.m_c[0] = __image_of_e1__.m_c[0];
			__x__.m_c[1] = __image_of_e1__.m_c[1];
			__x__.m_c[2] = __image_of_e1__.m_c[2];
			__x__.m_c[3] = __image_of_e1__.m_c[3];
			__x__.m_c[4] = __image_of_e2__.m_c[0];
			__x__.m_c[5] = __image_of_e2__.m_c[1];
			__x__.m_c[6] = __image_of_e2__.m_c[2];
			__x__.m_c[7] = __image_of_e2__.m_c[3];
			__x__.m_c[8] = __image_of_e3__.m_c[0];
			__x__.m_c[9] = __image_of_e3__.m_c[1];
			__x__.m_c[10] = __image_of_e3__.m_c[2];
			__x__.m_c[11] = __image_of_e3__.m_c[3];
			__x__.m_c[12] = __image_of_e0__.m_c[0];
			__x__.m_c[13] = __image_of_e0__.m_c[1];
			__x__.m_c[14] = __image_of_e0__.m_c[2];
			__x__.m_c[15] = __image_of_e0__.m_c[3];
		}
	} /* end of namespace __G2_GENERATED__ */









} // end of namespace h3ga
// post_h_include


#endif //  _GA_h3ga_h_H_
