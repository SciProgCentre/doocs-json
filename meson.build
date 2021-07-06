project('doocs-json', 'cpp',
  version : '0.1.0',
  default_options : [
    'warning_level=3',
    'cpp_std=c++17'
  ]
)

doocsapi_dep = dependency('doocs-doocsapi', fallback : [ 'doocs-clientlib', 'doocsapi_dep' ])

# use nlohmann-json3-dev on Ubuntu
nlohmann_json_dep = dependency('nlohmann_json', fallback : ['nlohmann_json', 'nlohmann_json_dep'])

# rsocket dependency
cmake = import('cmake')

#rsocket_sub_project = cmake.subproject('rsocket')
#rsocket_dep = rsocket_sub_project.dependency('ReactiveSocket')

# zmq_sub_project = cmake.subproject('zmqpp')
zmqpp_dep = dependency('libzmqpp') #zmq_sub_project.dependency('zmqpp')

include_dir = include_directories('include')

sources = ['src/doocs_json.cpp','src/doocs_zmq.cpp']


lib = static_library(
  'doocs_json', sources,
  include_directories : include_dir,
  dependencies : [
    doocsapi_dep, 
    nlohmann_json_dep,
#    rsocket_dep,
    zmqpp_dep,
    ]
)

zmq_exe = executable(
  'doocs_zmq_app',
  ['src/doocs_json.cpp','src/doocs_zmq.cpp','src/doocs_zmq_app.cpp'],
  include_directories : include_dir,
  install : true,
  dependencies : [
    doocsapi_dep,
    nlohmann_json_dep,
    zmqpp_dep,
    ]
)

#test('basic', exe)
