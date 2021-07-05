//
// Created by altavir on 18.06.2021.
//
#include <nlohmann/json.hpp>
#include <eq_data.h>

#ifndef BUILDDIR_DOOCS_JSON_H
#define BUILDDIR_DOOCS_JSON_H

#endif  // BUILDDIR_DOOCS_JSON_H

/**
 * Convert given DOOCS EqData to a json representation
 * @param eqData
 * @return
 */
nlohmann::json eq_data_to_json(EqData eqData);

/**
 * Convert json to DOOCS EqData
 * @param obj
 * @return
 */
EqData *eq_data_from_json(nlohmann::json obj);

/**
 * Make a response to a magix message with DOOCS payload according to
 * https://github.com/waltz-controls/rfc/blob/master/5/readme.md
 *
 */
nlohmann::json respond_magix(nlohmann::json request, const std::string& endpoint_name = "doocs");