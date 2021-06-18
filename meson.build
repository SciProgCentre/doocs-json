project('doocs-json', 'cpp',
  version : '0.1.0',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

doocsapi_dep = dependency('doocs-doocsapi', fallback : [ 'doocs-clientlib', 'doocsapi_dep' ])
nlohmann_json_dep = dependency('nlohmann_json', version : '3.9.1', fallback : ['nlohmann_json', 'nlohmann_json_dep'])

exe = executable(
  'doocs_json', 'doocs_json.cpp',
  install : true, 
  dependencies : [doocsapi_dep, nlohmann_json_dep]
)

test('basic', exe)
