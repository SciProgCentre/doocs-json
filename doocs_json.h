//
// Created by altavir on 18.06.2021.
//

#ifndef BUILDDIR_DOOCS_JSON_H
#define BUILDDIR_DOOCS_JSON_H

#endif  // BUILDDIR_DOOCS_JSON_H

#include "doocs_json.cpp"

/**
 * Convert given DOOCS EqData to a json representation
 * @param eqData
 * @return
 */
json eq_data_to_json(EqData eqData);

/**
 * Convert json to DOOCS EqData
 * @param obj
 * @return
 */
EqData *eq_data_from_json(json obj);

