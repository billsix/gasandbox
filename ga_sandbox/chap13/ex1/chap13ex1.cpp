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

// Daniel Fontijne -- fontijne@science.uva.nl

#include <libgasandbox/c3ga.h>
#include <libgasandbox/c3ga_util.h>
#include <libgasandbox/timing.h>

#include <vector>

using namespace c3ga;

int main(int argc, char*argv[]) {
	// profiling for Gaigen 2:
	c3ga::g2Profiling::init();

	// get the basis vectors:
	mv bv[5] = {no, e1, e2, e3, ni};

	// print out the metric:
	printf("Metric:\n");
	printf("    ");
	for (int i = 0; i < 5; i++)
		printf(" %s  ", mv_basisVectorNames[i]);
	printf("\n");
	
	for (int i = 0; i < 5; i++) {
		printf("%s ", mv_basisVectorNames[i]);
		for (int j = 0; j < 5; j++) {
			printf(" % 1.1f", _float(bv[i] << bv[j]));
		}
		printf("\n");
	}

	printf("\n");

	// create 'e' and 'eb'
	const float sqrt2i = 1.0f / 1.4142135623730950488016887242097f;
	mv e = sqrt2i * (no - ni);
	mv eb = sqrt2i * (no + ni);

	// print e and eb
	printf("e and eb:\n");
	printf(" e = %s\n", e.c_str());
	printf("eb = %s\n", eb.c_str());
	printf("\n");
	printf("The metric of e and eb:\n");
	printf(" e . e  = %f\n", _float(e << e));
	printf("eb . eb = %f\n", _float(eb << eb));
	printf(" e . eb = %f\n", _float(e << eb));





	return 0;
}
