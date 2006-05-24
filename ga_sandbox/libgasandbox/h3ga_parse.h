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

#ifndef _H3GA_PARSE_H_
#define _H3GA_PARSE_H_

#include <string>
#include "h3ga.h"

/** parses a multivector string, returns multivectors (or throws std::string() on error) */
h3ga::mv parseMVString(const std::string &str);


#endif /* _E3GA_PARSE_H_ */