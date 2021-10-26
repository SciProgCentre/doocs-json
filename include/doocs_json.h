//
// Created by altavir on 18.06.2021.
//
#include <nlohmann/json.hpp>
#include <eq_data.h>

#ifndef BUILDDIR_DOOCS_JSON_H
#define BUILDDIR_DOOCS_JSON_H

/**
 * Convert given DOOCS EqData to a json representation
 * @param eqData
 * @return
 */
nlohmann::json eq_data_to_json(const EqData& eqData);

/**
 * Convert json to DOOCS EqData
 * @param obj
 * @return
 */
std::unique_ptr<EqData> eq_data_from_json(const nlohmann::json& obj);

/**
 * Make a response to a magix message with DOOCS payload according to
 * https://github.com/waltz-controls/rfc/blob/master/5/readme.md
 *
 */
nlohmann::json respond_magix(nlohmann::json request, const std::string& endpoint_name = "doocs");

nlohmann::json get_property(const std::string &address, const nlohmann::json& data = nullptr);
nlohmann::json set_property(const std::string &address, const nlohmann::json& data = nullptr);
nlohmann::json list_names(const std::string &address);

#endif  // BUILDDIR_DOOCS_JSON_H
