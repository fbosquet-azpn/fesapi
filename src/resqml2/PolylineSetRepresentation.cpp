/*-----------------------------------------------------------------------
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"; you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
-----------------------------------------------------------------------*/
#include "PolylineSetRepresentation.h"

#include <stdexcept>

using namespace std;
using namespace RESQML2_NS;

const char* PolylineSetRepresentation::XML_TAG = "PolylineSetRepresentation";

uint64_t PolylineSetRepresentation::getXyzPointCountOfPatch(unsigned int patchIndex) const
{
	if (patchIndex >= getPatchCount()) {
		throw range_error("The index of the patch is not in the allowed range of patch.");
	}

	const unsigned int polylineCount = getPolylineCountOfPatch(patchIndex);
	std::unique_ptr<unsigned int[]> nodeCountPerPolyline(new unsigned int[polylineCount]);

	getNodeCountPerPolylineInPatch(patchIndex, nodeCountPerPolyline.get());

	uint64_t nodeCount = 0;
	for (unsigned int nodeCountPerPolylineIndex = 0; nodeCountPerPolylineIndex < polylineCount; ++nodeCountPerPolylineIndex) {
		nodeCount += nodeCountPerPolyline[nodeCountPerPolylineIndex];
	}
	return nodeCount;
}
