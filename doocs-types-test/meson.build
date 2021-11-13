project('types_test',
    [ 'cpp' ],
    default_options : [
        'cpp_std=c++14',
    ],
)

# Source files
main = [
    'src/main.cc',
]

src = [
    'src/EqFctTest.cc',
]

# Things we install besides the binary
datafiles = [
    'RPC_LIBNO',
    meson.project_name() + '_CONF.TEMPLATE',
]

# Libraries we depend on (usually found via pkg-config)
dep = [
    dependency('doocs-serverlib'),
    dependency('doocs-doocsapi'),
]

install_data(datafiles,
    install_dir : get_option('datadir'),
)

# Server executable
executable(meson.project_name() + '_server',
    [main, src],
    dependencies : dep,
    install : true,
)
