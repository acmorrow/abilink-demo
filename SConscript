Import('env')

env = env.Clone()
env.AppendUnique(
    CPPPATH=['.'],
    LIBPATH=[env.Dir('$VARIANT_DIR')],
    RPATH=[env.Dir('$VARIANT_DIR')],
)

env.Library(
    target='common',
    source=[
        'libcommon.cpp',
    ],
)

env.Library(
    target='client',
    source=[
        'libclient.cpp',
    ],
    LIBS=[
        'common',
        'boost_system',
    ],
)

env.Library(
    target='server',
    source=[
        'libserver.cpp',
    ],
    LIBS=[
        'common',
        'boost_system',
    ],
)

env.Program(
    target='client',
    source=[
        'client.cpp',
    ],
    LIBS=[
        'client',
        'common',
        'boost_system',
    ],
)

env.Program(
    target='server',
    source=[
        'server.cpp',
    ],
    LIBS=[
        'server',
        'common',
        'boost_system',
    ],
)
