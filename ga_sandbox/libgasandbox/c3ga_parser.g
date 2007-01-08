
// Generated on 2007-01-08 13:41:33 by G2 0.1 from 'E:\ga\ga_sandbox\ga_sandbox\libgasandbox\c3ga.gs2'

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




header "pre_include_cpp" {
	#include <iostream>
		#include <utility>
		#include <string>
		#include <antlr/String.hpp>
		#include <stdlib.h>
		#include "c3ga.h"
		using namespace std;
}

options {
	mangleLiteralPrefix = "TK_";
	language="Cpp";
	genHashLines=false;
	namespace = "c3ga";
}


/* The following code will be copied verbatim into the cpp file generated by ANTLR */
{ 

	void mv_parserProcessBasisElement(float coordinates[32], float c, unsigned int bitmap) {
		if (bitmap > 63) {
			mv_throw_exception("mv_parserProcessBasisElement(): parse error", MV_EXCEPTION_ERROR);
		}

		int idx = mv_basisElementIndexByBitmap[bitmap];
		coordinates[idx] = c / (float)mv_basisElementSign[idx];

		//	printf("BE %f, %d\n", scale, bitmap);

	}

	void mv_parserProcessBasisVector(const std::string &bv, float &scale, unsigned int &bitmap) {
		unsigned int i;
		//	printf("BasisVector: %s\n", bv.c_str());
		for (i = 0; i < 5; i++) {
			if (mv_basisVectorNames[i] == bv) {
				unsigned int b = 1 << i;
				if (bitmap & b) { // bv ^ bv = 0
					scale = 0;
					return;
				}

				// add basis vector to bitmap	
				bitmap |= b;

				i++;
				for (; i < 5; i++) // compute sign flips due to anti commuting basis vectors
				if (bitmap & (1 << i)) scale = -scale;


				//printf("Result: %f, %d\n", scale, bitmap);
				return;
			}
		}
		if (i == 5) {
			// this should never execute, for the basis vector should always be found in MV_basisVectorNames
			// this depends on exceptions or not
			mv_throw_exception(("mv_parserProcessBasisVector(): unknown basis element: " + bv).c_str(), MV_EXCEPTION_ERROR);
		}
	}


} /* End of code that will be copied verbatim into the cpp file generated by ANTLR */


class c3ga_mv_parser extends Parser;
options {
	k = 2;
	importVocab=c3ga_mv_lexer;	// use vocab generated by lexer
	buildAST=false;
}

multivector returns [mv result] 
{
	float coordinates[32];
	mv_zero(coordinates, 32); 
	std::pair<float, unsigned int> be; 
	float sg; 
	float scale = (float)1.0;

}
:
(sg=sign {scale *= sg;})* be = basis_element 
{mv_parserProcessBasisElement(coordinates, scale * be.first, be.second);}
(scale=sign (sg=sign {scale *= sg;})* be = basis_element 
{mv_parserProcessBasisElement(coordinates, scale * be.first, be.second);})*

{
	result = mv_compress(coordinates/*, 0.0, 63*/);
}
;


basis_element returns [std::pair<float, unsigned int> r]
{r.first = 1.0; r.second = 0;}
:
	t1 : NUMBER {r.first = mv_stringToNumber(t1->getText().c_str());} 
((GP | OP)?
	(t2 : BASIS_VECTOR {mv_parserProcessBasisVector(t2->getText(), r.first, r.second);})
(OP t3 : BASIS_VECTOR {mv_parserProcessBasisVector(t3->getText(), r.first, r.second);})*)? |

((t5 : BASIS_VECTOR {mv_parserProcessBasisVector(t5->getText(), r.first, r.second);}) 
(OP t6 : BASIS_VECTOR {mv_parserProcessBasisVector(t6->getText(), r.first, r.second);})*)
;

sign returns [float sg]
{sg = (float)1.0;}
:
	(PLUS | MINUS {sg = -sg;})
;

